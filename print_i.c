#include "ft_printf.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	dow_i0x(unsigned long long n)
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


char *to_i0xl(long long n)
{
	int len;
	uintmax_t nn ;
	char *res;

	nn = (n < 0) ? -n : n;
	//printf("\nnn=%lli\n", nn);
	len = dow_i0x(nn);
	//res = (char*)malloc(len + 1);
	//res[len + 1] = '\0';
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}
char *to_i0x(int n)
{
	int len;
	unsigned int nn;
	char *res;

	nn = (n < 0) ? -n : n;
	//printf("\nnn=%u\n", nn);
	len = dow_i0x(nn);
	//printf("\ndow=%i\n", len);
	//res = (char*)malloc(len + 1);
	//res[len + 1] = '\0';
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}
char *ft_ipr(char **str, int precision)
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

int pr_ix(char *str, t_param *p, int len, char* x)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		if (x)
			res += write(1, x, 1);
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		if (x)
			res += write(1, x, 1);
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else if (p->flag[2])
	{
		if (x)
			res += write(1, x, 1);
		while (p->width - res - len > 0)
			if (p->precision > -1)
				res += write(1, " ", 1);
			else
				res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len - (int)(x != 0)> 0)
			res += write(1, " ", 1);
		if (x)
			res += write(1, x, 1);
		res += write(1, str, len);
	}
	return (res);
}

int ft_print_i(long long n, t_param *p)
{
	char *chislo;
	int len;
	short pp;
	char *x;

	x = p->flag[4] ? " " : 0;
	x = p->flag[0] ? "+" : x;

	//printf("n=%lli\n", n);
	//printf("\nn=%lli\n", n);
	//ft_print_param(p);
	//printf("\nx=%ss\n", x);
	if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->type, "D") || !strcmp(p->modificator, "z"))
		{

			x = n < (long long)0 ? "-" : x;
			chislo = to_i0xl(n);
			
		}/*
	else if (!strcmp(p->modificator, "z"))
		{
			chislo = to_i0xl((size_t)n);
		}*/
	else if (!strcmp(p->modificator, "h"))
	{
		x = (short)n < 0 ? "-" : x;
		pp = (short)n;
		//printf("n=%d\n", (int)pp);
		chislo = to_i0x((short)n);
	}
	else if (!strcmp(p->modificator, "hh"))
	{
		x = (signed char)n < 0 ? "-" : x;
		chislo = to_i0x((signed char)n);
	}
		else
		{
				x = n < (long long)0 ? "-" : x;
			chislo = to_i0x(n);
		}
	//printf("\nchislo=%ss\n", chislo);
	if (n == 0 && p->precision == 0)
	{
		free(chislo);
		chislo = ft_strnew(0);
	}
	
	if (p->precision > (int)strlen(chislo))
		chislo = ft_ipr(&chislo, p->precision);
	len = strlen(chislo);
	//printf("\nch=%s len=%i", chislo, len);
	return (pr_ix(chislo, p, len, x));
}
