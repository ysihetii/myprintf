#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int print_flag_and_widthS(int len, t_param *p, char *str)
{
	if (p->flag[1])
	{
		write (1, str, len);
		for (int j = len; j < p->width; ++j)
			write (1, " ", 1);
	}
	else if (p->flag[2])
	{
		for (int j = len; j < p->width; ++j)
			write (1, "0", 1);
		write (1, str, len);
	}
	else
	{
		for (int j = len; j < p->width; ++j)
			write (1, " ", 1);
		write (1, str, len);
	}
	return (p->width);
}

int pr_sxS(char *str, t_param *p, int len)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else if (p->flag[2])
	{
		while (p->width - res - len > 0)
			if (p->precision > -1)
				res += write(1, " ", 1);
			else
				res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len )
			res += write(1, " ", 1);
		res += write(1, str, len);
	}
	return (res);
}
void ft_putcharS(char c)
{
	write (1,&c, 1);
}
void	ft_putnbrS(int n)
{
	if (n < 0)
		ft_putcharS('-');
	if (n < -9 || n > 9)
	{
		ft_putnbrS(mod(n / 10));
		ft_putcharS(mod(n % 10) + '0');
	}
	else
		ft_putcharS(mod(n % 10) + '0');
}

int ft_print_unicodesS(char *s, wchar_t n)
{
    if (n <= 127 || MB_CUR_MAX == 1)
        *s = n;
    else if (n <= 2047)
    {
        s[0] = (n >> 6) | 192;
        s[1] = (n & 63) | 128;
    }
    else if (n <= 65535)
    {
        s[0] = (n >> 12) | 224;
        s[1] = ((n >> 6) & 63) | 128;
        s[2] = (n & 63) | 128;
    }
    else
    {
        s[0] = (n >> 18) | 240;
        s[1] = ((n >> 12) & 63) | 128;
        s[2] = ((n >> 6) & 63) | 128;
        s[3] = (n & 63) | 128;
    }
    return (strlen(s));
}

int ft_print_sS(wchar_t *sstr, t_param *p)
{
	int i;
	int k=0;
	char *str;
	
	char *s;

	int len;
	i = 0;
	if (!sstr)
{
	str = "(null)";
	len = 6;
	return(pr_sxS(str, p, len));
}
	while (sstr[i])
		i++;
	s = ft_strnew(4);
	str = ft_strnew(i * MB_CUR_MAX);
		//printf("\ni=%i", i);
	i = 0;

	while (*sstr)
	{
		for (int j = 0; j< 4; j++)
			s[j] = '\0';
		i = ft_print_unicodesS(s, *sstr);
		strcpy(&str[k], s);
		sstr++;
		k += i;
	}
	len = strlen(str);
	//printf("\nlen=%i\n", len);
	//printf("%S\n", u);
	/*
	ft_print_param(p);
write(1,p->type, 1);
write(1,"\n",1);
ft_putnbr(p->precision);
write(1,"\n",1);
ft_putnbr(p->width);

write(1, str, strlen(str));
write(1,"\n",1);
*/


	len = strlen(str);
	if (p->precision <= 0 && p->precision != -17777)
	{
		for (int j = 0; j > p->precision; j--)
			write(1, " ", 1);
		return (-p->precision);
	}
	if (p->precision < len && p->precision != -17777)
	{
		if (p->precision != -17777)
			len = p->precision;
	}
	if (len >= p->width)
	{
		write(1, str, len);
		return(len);
	}
	else 
		return(pr_sxS(str, p, len));
return (0);
}
