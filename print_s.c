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
	return (p->width);
}

int ft_print_s(char *str, t_param *p)
{
	int len;

	len = strlen(str);
	if (p->precision <= 0 && p->precision != -17777)
	{
		for (int j = 0; j > p->precision; j--)
			write(1, " ", 1);
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
		return(len);
	}
	else 
		return(print_flag_and_width(len, p,str));
return (0);
}

int ft_print_pr(char *str, t_param *p)
{
	int len;

	if (p->precision < 0)
		p->precision = -p->precision;
	if (p->precision == 0)
		p->precision = 1;
	len = strlen(str);
	if (p->precision <= 0 && p->precision != -17777)
	{
		for (int j = 0; j > p->precision; j--)
			write(1, " ", 1);
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
		return(len);
	}
	else 
		return(print_flag_and_width(len, p,str));
return (0);
}