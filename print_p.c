#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	dow_p0x(unsigned long long n)
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

char xp[16] ={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
char *to_p0xl(long long n)
{
	int len;
	uintmax_t nn = 1844674407370955161;
	char *res;

	nn = (n < 0) ? nn * 10 + 5 + n + 1 : n;
	//printf("\nnn=%lli\n", nn);
	len = dow_p0x(n);
	//res = (char*)malloc(len + 1);
	//res[len + 1] = '\0';
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = xp[nn % 16];
		nn /= 16;
		len--;
	}
	return (res);
}
char *to_p0x(int n)
{
	int len;
	unsigned int nn;
	char *res;

	nn = (n < 0) ? 4294967295 + n + 1 : n;
	//printf("\nnn=%u\n", nn);
	len = dow_p0x(nn);
	//printf("\ndow=%i\n", len);
	//res = (char*)malloc(len + 1);
	//res[len + 1] = '\0';
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = xp[nn % 16];
		nn /= 16;
		len--;
	}
	return (res);
}
char *ft_ppr(char **str, int precision)
{
	int len;
	int i;
	char *res;

	len = strlen(*str);
	//res = (char*)malloc(precision + 1);
	//res[precision + 1] = '\0';
	res = ft_strnew(precision);
	//res = ft_strnew(2);
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

int pr_ppx(char *str, t_param *p, int len, char* x)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		if (p->flag[3])
			res += write(1, x, 4);
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		if (p->flag[3])
			res += write(1, x, 4);
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else if (p->flag[2])
	{
		if (p->flag[3])
			res += write(1, x, 4);
		while (p->width - res - len > 0)
			res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len - 4 * (int)(p->flag[3] == '#')> 0)
			res += write(1, " ", 1);
		if (p->flag[3])
			res += write(1, x, 4);
		res += write(1, str, len);
	}
	return (res);
}

int ft_print_p(long long n, t_param *p)
{
	char *chislo;
	int len;
	char *x = "0x10";

	if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j"))
		chislo = to_p0xl(n);
	else
		chislo = to_p0x(n);
	if (n == 0)
		p->flag[3] = 0;
	if (n == 0 && p->precision == 0)
	{
		free(chislo);
		chislo = ft_strnew(0);
	}
	if (p->precision > (int)strlen(chislo))
		chislo = ft_ppr(&chislo, p->precision);
	len = strlen(chislo);
	return (pr_ppx(chislo, p, len, x));
}
