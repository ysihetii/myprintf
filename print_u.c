#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	dow_u0x(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char *to_u0xl(unsigned long long n)
{
	int len;
	uintmax_t nn = 1844674407370955161;
	char *res;

	nn = n;
	len = dow_u0x(n);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}
char *to_u0x(unsigned int n)
{
	int len;
	unsigned int nn;
	char *res;

	nn = n;
	len = dow_u0x(nn);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}
char *ft_upr(char **str, int precision)
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

int pr_ux(char *str, t_param *p, int len, char* x)
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
	else if (p->flag[2])
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
	free(str);
	return (res);
}

int ft_print_u(unsigned long long n, t_param *p)
{
	char *chislo;
	int len;
	char *x = strcmp(p->type, "X") ? "0x" : "0X";
	if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j")|| !strcmp(p->type, "U") || !strcmp(p->modificator, "z"))
		chislo = to_u0xl(n);
	else if (!strcmp(p->modificator, "h"))
	{
		chislo = to_u0x((unsigned short)n);
	}
	else if (!strcmp(p->modificator, "hh"))
		chislo = to_u0x((unsigned char)n);
	else
		chislo = to_u0x(n);
	if (n == 0)
		p->flag[3] = 0;
	if (n == 0 && p->precision == 0)
	{
		free(chislo);
		chislo = ft_strnew(0);
	}
	if (p->precision > (int)strlen(chislo))
		chislo = ft_upr(&chislo, p->precision);
	len = strlen(chislo);
	return (pr_ux(chislo, p, len, x));
}
