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


	p->param = -1;
	for (int i =0; i < 5; i++)
		p->flag[i] = 0;
	p->width = 0;
	p->precision = -17777;
	p->modificator[2] = '\0';
	strcpy(p->modificator, "ww");
	//p->type = ft_strnew(2);
	p->type[2] = '\0';
	strcpy(p->type, "ww");
	return (p);
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
		if (!not_alph(format[i]) && n != MODIFICATORS_NUM)
		{
			this[0] = 'q';
			return (&(format[i]) - format);
		}
		j = 0;
		while (j < n)
		{
			if (ft_strnstr(&(format[i]), arr[j], strlen(arr[j])))
			{
				strcpy(this,  arr[j]);
				q = (&(format[i]) - format);
				//return (&(format[i]) - format);
			}
			if (q)
				return (q);
			j++;
		}
			i++;
	}
	return (-2);
}




int ft_work_with_param(char *str, t_param *p)
{
	int is_valid = 1;
	int i = 0;
	int j = 0;
	if (strlen(str) == 0)
		return (0);
	is_valid = ft_rec(str, MODIFICATORS, MODIFICATORS_NUM, (p->modificator));
	if (( (p->modificator)[0] == 'w'|| (p->modificator)[0] == 'h') && find_h(str))
		{
		(p->modificator)[0] = 'h';
		(p->modificator)[1] = '\0';
	}
	while (FLAGS[i])
	{
		if (strchr(str, FLAGS[i]))
			if(i != 2)
				p->flag[i] = FLAGS[i];
		i++;
	}
	if (find_z(str))
		p->flag[2] = '0';
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
	
	if (is_valid < 0)
		return (-1);
	if (p->modificator[0] != 'w')
		j += strlen(p->modificator);
	//free(str);
	return(0);
}
int	ft_printf(char *format, ...)
{
	va_list ap;
	int res;
	res = 0;
	char *ss;

	t_param *p = (t_param*)malloc(sizeof(t_param));;
	int is_valid = 1;
	
	va_start(ap, format);
	while (*format && is_valid)
	{
		if (*format == '%')
		{
			p = ft_new_p(p);

			is_valid = ft_rec(format, TYPES, TYPES_NUM, (p->type));
			if (is_valid < 0)
			{
				while (not_alph(*format) && *format)
				{
					format++;
				}
				continue ;
			}
			if (is_valid < 0)
				return (-1);
			ss = ft_strsub(format, 1, is_valid - 1);
			ft_work_with_param(ss, p);
			free(ss);
			format += is_valid;
			if (!strcmp(p->type, "qw"))
				res += ft_print_c( *(format),p);
			if (!strcmp(p->type, "S"))
				res += ft_print_sS(va_arg(ap, wchar_t*),p);
			 else if (!strcmp(p->type, "s"))
			 {
			 	if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j"))
			 		res += ft_print_sS(va_arg(ap, wchar_t*),p);
			 	else
					res += ft_print_s(va_arg(ap, char*),p);
			}
			if (!strcmp(p->type, "c") || !strcmp(p->type, "C"))
				res += ft_print_c(va_arg(ap, int),p);
			if (!strcmp(p->type, "%"))
				res += ft_print_pr("%", p);
			if (!strcmp(p->type, "p"))
			{
				p->flag[3] = '#';
				res += ft_print_p(va_arg(ap,unsigned long long),p);
			}
			if (!strcmp(p->type, "x") || !strcmp(p->type, "X"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->modificator, "z"))
					res += ft_print_x(va_arg(ap, long long),p);
				else 
					res += ft_print_x(va_arg(ap, int),p);
			}
			if (!strcmp(p->type, "o") || !strcmp(p->type, "O"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->type, "O") || !strcmp(p->modificator, "z"))
					res += ft_print_o(va_arg(ap, long long),p);
				else 
					res += ft_print_o(va_arg(ap, int),p);
			}
			if (!strcmp(p->type, "u") || !strcmp(p->type, "U"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->modificator, "z") || !strcmp(p->type, "U"))
					res += ft_print_u(va_arg(ap, unsigned long long),p);
				else 
					res += ft_print_u(va_arg(ap, unsigned int),p);
			}
			else if (!strcmp(p->type, "d") || !strcmp(p->type, "i") || !strcmp(p->type, "D"))
			{/*
				if (!strcmp(p->modificator, "z"))
				{
					p->modificator = "l";
					res += ft_print_u(va_arg(ap, unsigned long long),p);
				}
				else */if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->modificator, "z") || !strcmp(p->type, "D"))
					res += ft_print_i(va_arg(ap, long long),p);
				else 
					res += ft_print_i(va_arg(ap, int),p);
				//p_free(&p);
			}
		}
		else
			res += write(1, format, 1);
		format++;
	}
	va_end(ap);
	free(p);
return (res); 
}


