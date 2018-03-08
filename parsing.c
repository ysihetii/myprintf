#include "ft_printf.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

char *FLAGS="+-0# ";
char *TYPES[TYPES_NUM] = {"i", "s",  "S", "d", "D", "p", "o", "O", "u", "U", "x", "X", "c", "C", "%", "*","$", "L", "'", "n"};
//char *MODIFICATORS[MODIFICATORS_NUM] = {"hh", "h", "ll", "l", "j", "z"};
char *MODIFICATORS[MODIFICATORS_NUM] = {"ll",  "j", "z","l", "hh"};

int find_h(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h' &&  ( (i == 0 && str[i + 1] !='h')  ||     (str[i + 1] != 'h' && str[i - 1] != 'h')))
			return (1);
		i++;
	}
	return(0);
}

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
int not_alph(char c)
{
	char *alph ="0123456789. +-#sSpdDioOuUxXcChljz%";
	return ((int)strchr(alph, c));
}

int		ft_rec(char *format, char **arr, int n, char **this)
{
	int i;
	int j;

	int q;
	q = 0;
//printf("\nformat=%s\n", format);
	i = *format == '%' ? 1 : 0;
	while(format[i])
	{
		if (!not_alph(format[i]) && n != MODIFICATORS_NUM)
		{
			*this = "q";
			return (&(format[i]) - format);
		}
		j = 0;
		while (j < n)
		{
			if (ft_strnstr(&(format[i]), arr[j], strlen(arr[j])))
			{
				*this = arr[j];
				q = (&(format[i]) - format);
				//return (&(format[i]) - format);
			}
			if (q)
				return (q);
			j++;
		}
		//if (n == MODIFICATORS_NUM)
		//	return (-1);
		//else
			i++;
	}
	return (-2);
}

int is_dig(char c)
{
	return (c >= '0' && c <='9');
}
int find_z(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' && (i == 0 || !is_dig(str[i - 1])) && str[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}


int ft_work_with_param(char *str, t_param *p)
{
	int is_valid = 1;
	int i = 0;
	//printf ("\nstr=%s\n", str);
	if (strlen(str) == 0)
		return (0);
	is_valid = ft_rec(str, MODIFICATORS, MODIFICATORS_NUM, &(p->modificator));
	//printf("\nis_h=%i\n",(p->modificator)[0]);
	if (( (p->modificator)[0] == ' '|| (p->modificator)[0] == 'h') && find_h(str))
		{//strcpy(p->modificator, "h");
	//printf("efvrgvrgvrtvtrvrtv");
		(p->modificator)[0] = 'h';
		(p->modificator)[1] = '\0';
	}
	//printf("\nh=%s\n", p->modificator);
	while (FLAGS[i])
	{
		//printf("%s\n", strchr(str, FLAGS[i]));
		if (strchr(str, FLAGS[i]))
			if(i != 2)
				p->flag[i] = FLAGS[i];
		i++;
	}
	if (find_z(str))
		p->flag[2] = '0';
	//print_flags(p);

	//p->flag = strchr(FLAGS, *str) ? *str : '\0';
	//if (p->flag)
	//	str++;
	while ((*str <= '0' || *str > '9') && *str != '.' && *str)
		str++;
//printf ("\nstr=%s\n", str);
	p->width = ft_atoi(str);
	str += ft_pass_digit(str);
	if (strchr(str, '.'))
	{
		str++;
		p->precision = ft_atoi(str);
		str += ft_pass_digit(str);
	}
	
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
	int res;
	res = 0;

	t_param *p = (t_param*)malloc(sizeof(t_param));;
	int is_valid = 1;
	
	va_start(ap, format);
	while (*format && is_valid)
	{
		if (*format == '%')
		{
			p = ft_new_p(p);

			is_valid = ft_rec(format, TYPES, TYPES_NUM, &(p->type));
			//rintf ("\nis=%i\n", is_valid);
			if (is_valid < 0)
			{
				//printf("l");
				//printf ("\ni=%i", not_alph(*format));
				while (not_alph(*format) && *format)
				{
					format++;
				}
				continue ;
			}
			
			if (!strcmp(p->type, "*") || !strcmp(p->type, "'") || !strcmp(p->type, "$") || !strcmp(p->type, "L") || !strcmp(p->type, "n"))
				return (-1);
			if (is_valid < 0)
				return (-1);
			
			ft_work_with_param(ft_strsub(format, 1, is_valid - 1), p);
			format += is_valid;
		//	ft_print_param(p);
			//print_flags(p);
			if (!strcmp(p->type, "q"))
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

