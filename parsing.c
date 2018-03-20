/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:31:34 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 19:31:36 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

char		*g_flags = "+-0# ";
const int	g_types_num = 20;
const int	g_modificators_num = 5;
char		*g_types[g_types_num] =
{
	"i", "s", "S", "d", "D", "p",
	"o", "O", "u", "U", "x", "X", "c", "C", "%", "*", "$", "L", "'", "n"
};
char		*g_modificators[g_modificators_num] =
{
	"ll", "j", "z", "l", "hh"
};

void		do_with_flags(char *str, t_param **p)
{
	int i;

	i = 0;
	while (g_flags[i])
	{
		if (ft_strchr(str, g_flags[i]))
			if (i != 2)
				(*p)->flag[i] = g_flags[i];
		i++;
	}
	if (find_z(str))
		(*p)->flag[2] = '0';
}

int			ft_rec(char *format, char **arr, int n, char this[])
{
	int i;
	int j;
	int q;

	q = 0;
	i = *format == '%' ? 1 : 0;
	while (format[i])
	{
		if (prosto_function(format[i], n, &(this[0])))
			return (&(format[i]) - format);
		j = 0;
		while (j < n)
		{
			if (ft_strnstr(&(format[i]), arr[j], ft_strlen(arr[j])))
			{
				ft_strcpy(this, arr[j]);
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

int			ft_work_with_param(char *str, t_param *p)
{
	int j;

	j = 0;
	if (ft_strlen(str) == 0)
		return (0);
	ft_rec(str, g_modificators, g_modificators_num, (p->modificator));
	if (((p->modificator)[0] == 'w' || (p->modificator)[0] == 'h')
	&& find_h(str))
	{
		(p->modificator)[0] = 'h';
		(p->modificator)[1] = '\0';
	}
	do_with_flags(str, &p);
	while ((str[j] <= '0' || str[j] > '9') && str[j] != '.' && str[j])
		j++;
	p->width = ft_atoi(&(str[j]));
	j += ft_pass_digit(&(str[j]));
	if (ft_strchr(str, '.'))
	{
		j++;
		p->precision = ft_atoi(&(str[j]));
		j += ft_pass_digit(&(str[j]));
	}
	return (0);
}

void		push_to_print(t_param *p, int *res, va_list *ap, char format)
{
	if (!ft_strcmp(p->type, "qw"))
		*res += ft_print_c((format), p);
	else if (!ft_strcmp(p->type, "s") || !ft_strcmp(p->type, "S"))
	{
		if (!ft_strcmp(p->modificator, "l") || !ft_strcmp(p->modificator, "ll")
		|| !ft_strcmp(p->modificator, "j") || !ft_strcmp(p->type, "S"))
			*res += ft_print_sss(va_arg(*ap, wchar_t*), p);
		else
			*res += ft_print_s(va_arg(*ap, char*), p);
	}
	else if (!ft_strcmp(p->type, "c") || !ft_strcmp(p->type, "C"))
		*res += ft_print_c(va_arg(*ap, int), p);
	else if (!ft_strcmp(p->type, "%"))
		*res += ft_print_pr("%", p);
	else if (!ft_strcmp(p->type, "p"))
		*res += ft_print_p(va_arg(*ap, unsigned long long), p);
	else if (!ft_strcmp(p->type, "x") || !ft_strcmp(p->type, "X"))
		*res += ft_print_x(va_arg(*ap, long long), p);
	else if (!ft_strcmp(p->type, "o") || !ft_strcmp(p->type, "O"))
		*res += ft_print_o(va_arg(*ap, long long), p);
	else if (!ft_strcmp(p->type, "u") || !ft_strcmp(p->type, "U"))
		*res += ft_print_u(va_arg(*ap, unsigned long long), p);
	else if (!ft_strcmp(p->type, "d") || !ft_strcmp(p->type, "i")
		|| !ft_strcmp(p->type, "D"))
		*res += ft_print_i(va_arg(*ap, long long int), p);
}

int			ft_printf(char *format, ...)
{
	va_list	ap;
	int		res;
	int		is_valid;
	t_param	*p;

	va_start(ap, format);
	ft_preludiya(&p, &res);
	while (*format)
	{
		if (*format == '%')
		{
			p = ft_new_p(p);
			is_valid = ft_rec(format, g_types, g_types_num, (p->type));
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
