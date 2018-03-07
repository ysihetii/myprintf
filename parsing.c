#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

char *FLAGS="+-0# ";
char *TYPES[TYPES_NUM] = {"i", "s",  "S", "d", "D", "p", "o", "O", "u", "U", "x", "X", "c", "C", "%"};
char *MODIFICATORS[MODIFICATORS_NUM] = {"hh", "h", "ll", "l", "j", "z"};




int ft_pass_digit(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

t_param *ft_new_p(t_param *p)
{


	p->param = -1;
	for (int i =0; i < 5; i++)
		p->flag[i] = 0;
	p->width = 0;
	p->precision = -17777;
	p->modificator = ft_strnew(2);
	strcpy(p->modificator, "  ");
	p->type = 0;
	return (p);
}

void print_flags(t_param *p)
{
	printf("\n-------------------------\n");
	for (int i = 0; i < 5; i++)
		printf("%i=%c\n", i, p->flag[i]);
	printf("-------------------------\n");
}
void ft_print_param(t_param *p)
{
	printf("\n-------------------------\n");
	printf("param=%i\n", p->param);
	printf("flag=%c\n", p->flag[0]);
	printf("width=%i\n", p->width);
	printf("precision=%i\n", p->precision);
	printf("modificator=%s\n", p->modificator);
	printf("type=%s\n", p->type);
	printf("-------------------------\n");
}

int		ft_rec(char *format, char **arr, int n, char **this)
{
	int i;
	int j;

//printf("\nformat=%s\n", format);
	i = *format == '%' ? 1 : 0;
	while(format[i])
	{
		j = 0;
		while (j < n)
		{
			if (ft_strnstr(&(format[i]), arr[j], strlen(arr[j])))
			{
				*this = arr[j];
				return (&(format[i]) - format);
			}
			j++;
		}
		if (n == MODIFICATORS_NUM)
			return (-1);
		else
			i++;
	}
	return (0);
}

int ft_work_with_param(char *str, t_param *p)
{
	int is_valid = 1;
	//printf ("\nstr=%s\n", str);
	if (strlen(str) == 0)
		return (0);
	while (strchr(FLAGS, *str))
	{
		p->flag[strchr(FLAGS, *str) - FLAGS] = *str;
		str++;
	}
	//print_flags(p);

	//p->flag = strchr(FLAGS, *str) ? *str : '\0';
	//if (p->flag)
	//	str++;
	p->width = ft_atoi(str);
	str += ft_pass_digit(str);
	if (*str == '.')
	{
		str++;
		p->precision = ft_atoi(str);
		str += ft_pass_digit(str);
	}
	is_valid = ft_rec(str, MODIFICATORS, MODIFICATORS_NUM, &(p->modificator));
	if (is_valid < 0)
		return (-1);
	if (p->modificator)
		str += strlen(p->modificator);
	//ft_print_param(p);
	if (*str)
		return (-1); //не закінчився рядок,  є помилка
//printf ("\nstr=%s\n", str);
	return(0);
}
int	ft_printf(char *format, ...)
{
	va_list ap;
	static int res;
	t_param *p = (t_param*)malloc(sizeof(t_param));;
	int is_valid = 1;
	
	va_start(ap, format);
	while (*format && is_valid)
	{
		if (*format == '%')
		{
			p = ft_new_p(p);

			is_valid = ft_rec(format, TYPES, TYPES_NUM, &(p->type));

			
			if (is_valid < 0)
				return (-1);
			
			ft_work_with_param(ft_strsub(format, 1, is_valid - 1), p);
			format += is_valid;
			if (!strcmp(p->type, "s"))
				res += ft_print_s(va_arg(ap, char*),p);
			if (!strcmp(p->type, "c") || !strcmp(p->type, "C"))
				res += ft_print_c(va_arg(ap, int),p);
			if (!strcmp(p->type, "%"))
				res += ft_print_pr("%", p);
			if (!strcmp(p->type, "x") || !strcmp(p->type, "X"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j"))
					res += ft_print_x(va_arg(ap, long long),p);
				else 
					res += ft_print_x(va_arg(ap, int),p);
			}
			if (!strcmp(p->type, "o"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j"))
					res += ft_print_o(va_arg(ap, long long),p);
				else 
					res += ft_print_o(va_arg(ap, int),p);
			}
			if (!strcmp(p->type, "d") || !strcmp(p->type, "i"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->modificator, "z"))
					res += ft_print_i(va_arg(ap, long long),p);
				else 
					res += ft_print_i(va_arg(ap, int),p);
			}
			if (!strcmp(p->type, "u") || !strcmp(p->type, "U"))
			{
				if (!strcmp(p->modificator, "l") || !strcmp(p->modificator, "ll") || !strcmp(p->modificator, "j") || !strcmp(p->modificator, "z") || !strcmp(p->type, "U"))
					res += ft_print_u(va_arg(ap, unsigned long long),p);
				else 
					res += ft_print_u(va_arg(ap, unsigned int),p);
			}
			//ft_print_param(p);
			//ft_print
		}
		else
			res += write(1, format, 1);
		format++;
	}
return (res); 
}
/*
int ft_printf(char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{

	}



}
*/

