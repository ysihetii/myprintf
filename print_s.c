#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int print_flag_and_width(int len, t_param *p, char *str)
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
	//free(str);
	return (p->width);
}

int pr_sx(char *str, t_param *p, int len)
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
				res += write(1, "0", 1);
				//res += write(1, " ", 1);
			else
				res += write(1, "0", 1);
				//res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len )
			res += write(1, " ", 1);
		res += write(1, str, len);
	}
	//free(str);
	return (res);
}
void ft_putchar(char c)
{
	write (1,&c, 1);
}
void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n < -9 || n > 9)
	{
		ft_putnbr(mod(n / 10));
		ft_putchar(mod(n % 10) + '0');
	}
	else
		ft_putchar(mod(n % 10) + '0');
}
int max(int a, int b)
{
	return (a > b ? a : b);
}
int ft_print_s(char *str, t_param *p)
{
	int len;
	
if (!str)
{
	str = "(null)";
	len = 6;
}
else
	len = strlen(str);
	if (p->precision == 0 )
	{

		for (int j = 0; j < p->width; j++)
			if (p->flag[2])
				write(1, "0", 1);
			else
				write(1, " ", 1);
			//free(str);
		return p->width;
	}
	if (p->precision < 0 && p->precision != -17777)
	{
		for (int j = 0; j > p->precision; j--)
			write(1, " ", 1);
		//free(str);
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
		//free(str);
		return(len);
	}
	else 
		return(pr_sx(str, p, len));
return (0);
}

int ft_print_pr(char *str, t_param *p)
{
	int len;

	
	if (p->precision == 0)
		p->precision = 1;
	len = strlen(str);
	if (p->precision <= 0 && p->precision != -17777)
	{
		for (int j = 0; j > p->precision; j--)
			write(1, " ", 1);
		//free(str);
		return (-p->precision);
	}
	if (p->precision < len && p->precision != -17777)
	{
		for (int j = p->precision; j < len; j++)
			str[j] = '\0';
		len = p->precision;
	}
	if (len >= p->width)
	{
		write(1, str, len);
		//free(str);
		return(len);
	}
	else 
		return(print_flag_and_width(len, p,str));
return (0);
}
