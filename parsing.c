#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

char *FLAGS="+-0# ";
char *TYPES[TYPES_NUM] = {"i", "s",  "S", "d", "D", "p", "o", "O", "u", "U", "x", "X", "c", "C", "%", "*","$", "L", "'", "n"};
char *MODIFICATORS[MODIFICATORS_NUM] = {"ll",  "j", "z","l", "hh"};




t_param *ft_new_p(t_param *p)
{
	int i;

	i = 0;
	p->param = -1;
	while (i < 5)
	{
		p->flag[i] = 0;
		i++;
	}
	p->width = 0;
	p->precision = -17777;
	p->modificator[2] = '\0';
	strcpy(p->modificator, "ww");
	p->type[2] = '\0';
	strcpy(p->type, "ww");
	return (p);
}

int prosto_function(char format,  int n, char *this)
{
	if (!not_alph(format) && n != MODIFICATORS_NUM)
		{
			*this = 'q';
			return (1);
		}
	return (0);
}

int		ft_rec(char *format, char **arr, int n, char this[])
{
	int i;
	int j;
	int q;

	q = 0;
	i = *format == '%' ? 1 : 0;
	while(format[i])
	{
		if (prosto_function(format[i], n,  &(this[0])))
			return (&(format[i]) - format);
		j = 0;
		while (j < n)
		{
			if (ft_strnstr(&(format[i]), arr[j], strlen(arr[j])))
			{
				strcpy(this,  arr[j]);
				q = (&(format[i]) - format);
			}
			if (q)
				return (q);
			j++;
		}
			i++;
	}
	return (-2);
}

void do_with_flags(char *str, t_param **p)
{
	int i;

	i = 0;
	while (FLAGS[i])
	{
		if (strchr(str, FLAGS[i]))
			if(i != 2)
				(*p)->flag[i] = FLAGS[i];
		i++;
	}
	if (find_z(str))
		(*p)->flag[2] = '0';
}

int ft_work_with_param(char *str, t_param *p)
{
	int j;

	j = 0;
	if (strlen(str) == 0)
		return (0);
	ft_rec(str, MODIFICATORS, MODIFICATORS_NUM, (p->modificator));
	if (((p->modificator)[0] == 'w'|| (p->modificator)[0] == 'h') && find_h(str))
	{
		(p->modificator)[0] = 'h';
		(p->modificator)[1] = '\0';
	}
	do_with_flags(str, &p);
	while ((str[j] <= '0' || str[j] > '9') && str[j] != '.' && str[j])
		j++;
	p->width = ft_atoi(&(str[j]));
	j += ft_pass_digit(&(str[j]));
	if (strchr(str, '.'))
	{
		j++;
		p->precision = ft_atoi(&(str[j]));
		j += ft_pass_digit(&(str[j]));
	}
	return(0);
}

void push_to_print(t_param *p, int *res, va_list *ap, char format)
{
	if (!strcmp(p->type, "qw"))
		*res += ft_print_c( (format),p);
	else if (!strcmp(p->type, "s") || !strcmp(p->type, "S"))
	{
		if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->type, "S"))
			 *res += ft_print_sS(va_arg(*ap, wchar_t*),p);
		else
			*res += ft_print_s(va_arg(*ap, char*),p);
	}
	else if (!strcmp(p->type, "c") || !strcmp(p->type, "C"))
		*res += ft_print_c(va_arg(*ap, int),p);
	else if (!strcmp(p->type, "%"))
		*res += ft_print_pr("%", p);
	else if (!strcmp(p->type, "p"))
		*res += ft_print_p(va_arg(*ap,unsigned long long),p);
	else if (!strcmp(p->type, "x") || !strcmp(p->type, "X"))
		*res += ft_print_x(va_arg(*ap, long long),p);
	else if (!strcmp(p->type, "o") || !strcmp(p->type, "O"))
		*res += ft_print_o(va_arg(*ap, long long),p);
	else if (!strcmp(p->type, "u") || !strcmp(p->type, "U"))
		*res += ft_print_u(va_arg(*ap, unsigned long long),p);
	else if (!strcmp(p->type, "d") || !strcmp(p->type, "i") || !strcmp(p->type, "D"))
		*res += ft_print_i(va_arg(*ap, long long int),p);
}

void ft_preludiya(t_param **p, int *res)
{
	*p = (t_param*)malloc(sizeof(t_param));
	*res = 0;
}

int chtototamneto(int is_valid, char **format)
{
	if (is_valid < 0)
	{
		while (not_alph(**format) && **format)
			(*format)++;
		return (1);
	}
	return (0);
}

void do_manipulations(char **format, t_param **p, int is_valid)
{
	char *ss;

	ss = ft_strsub(*format, 1, is_valid - 1);
	ft_work_with_param(ss, *p);
	free(ss);
	*format += is_valid;
}

int	ft_printf(char *format, ...)
{
	va_list ap;
	int res;
	int is_valid;
	t_param *p;

	va_start(ap, format);
	ft_preludiya(&p, &res);
	while (*format)
	{
		if (*format == '%')
		{
			p = ft_new_p(p);
			is_valid = ft_rec(format, TYPES, TYPES_NUM, (p->type));
			if (chtototamneto(is_valid, &format))
				continue ;
			do_manipulations(&format, &p, is_valid);
			push_to_print(p, &res, &ap, *format);
		}
		else
			res += write(1, format, 1);
		format++;
	}
	va_end(ap);
	free(p);
return (res);
}


