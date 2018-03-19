#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
}


int	dow_0x(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char x[16] ={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
char *to_0xl(long long n)
{
	int len;
	uintmax_t nn;
	char *res;

	nn = 1844674407370955161;
	nn = (n < 0) ? nn * 10 + 5 + n + 1 : n;
	len = dow_0x(n);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = x[nn % 16];
		nn /= 16;
		len--;
	}
	return (res);
}
char *to_0x(int n)
{
	int len;
	unsigned int nn;
	char *res;

	nn = (n < 0) ? 4294967295 + n + 1 : n;
	len = dow_0x(nn);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = x[nn % 16];
		nn /= 16;
		len--;
	}
	return (res);
}
char *ft_pr(char **str, int precision)
{
	int len;
	int i;
	char *res;

	len = strlen(*str);
	res = ft_strnew(precision);
	i = 0;
	while (i < precision)
		{
			if (i < precision - len)
				res[i] = '0';
			else
				res[i] = (*str)[i + len - precision];
			i++;
		}
	free(*str);
	return (res);
}

int fcontinue(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (p->flag[2])
	{
		if (p->flag[3])
			res += write(1, x, 2);
		while (p->width - res - len > 0)
			res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len - 2 * (int)(p->flag[3] == '#')> 0)
			res += write(1, " ", 1);
		if (p->flag[3])
			res += write(1, x, 2);
		res += write(1, str, len);
	}
	return (res);
}

int pr_x(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		if (p->flag[3])
			res += write(1, x, 2);
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		if (p->flag[3])
			res += write(1, x, 2);
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else
		res = fcontinue(str, p, len, x);
	free(str);
	return (res);
}

int ft_print_x(long long n, t_param *p)
{
	char *chislo;
	int len;
	char *x;

	x = strcmp(p->type, "X") ? "0x" : "0X";
	if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->modificator, "z"))
		chislo = to_0xl(n);
		else if (!strcmp(p->modificator, "h"))
	{
		chislo = to_0x((unsigned short)n);
	}
	else if (!strcmp(p->modificator, "hh"))
		chislo = to_0x((unsigned char)n);
	else
		chislo = to_0x((int)n);
	if (n == 0)
		p->flag[3] = 0;
	if (n == 0 && p->precision == 0)
		bzero(chislo, strlen(chislo));
	if (p->precision > (int)strlen(chislo))
		chislo = ft_pr(&chislo, p->precision);
	len = strlen(chislo);
	if (!strcmp(p->type, "X"))
		to_upper(chislo);
	return (pr_x(chislo, p, len, x));
}
