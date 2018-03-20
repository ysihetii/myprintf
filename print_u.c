/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:22:06 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 20:22:07 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		dow_u0x(unsigned long long n)
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

char	*ft_upr(char **str, int precision)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(*str);
	res = ft_strnew(precision);
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

int		fucontinue(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (p->flag[2])
	{
		if (p->flag[3])
			res += write(1, x, 2);
		while (p->width - res - len > 0)
			res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len - 2 * (int)(p->flag[3] == '#') > 0)
			res += write(1, " ", 1);
		if (p->flag[3])
			res += write(1, x, 2);
		res += write(1, str, len);
	}
	return (res);
}

int		pr_ux(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		if (p->flag[3])
			res += write(1, x, 2);
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		if (p->flag[3])
			res += write(1, x, 2);
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else
		res = fucontinue(str, p, len, x);
	free(str);
	return (res);
}

int		ft_print_u(unsigned long long n, t_param *p)
{
	char *chislo;
	char *x;

	x = ft_strcmp(p->type, "X") ? "0x" : "0X";
	if (!ft_strcmp(p->modificator, "l") || !ft_strcmp(p->modificator, "ll")
	|| !ft_strcmp(p->modificator, "j") || !ft_strcmp(p->type, "U")
	|| !ft_strcmp(p->modificator, "z"))
		chislo = to_u0xl(n);
	else if (!ft_strcmp(p->modificator, "h"))
		chislo = to_u0x((unsigned short)n);
	else if (!ft_strcmp(p->modificator, "hh"))
		chislo = to_u0x((unsigned char)n);
	else
		chislo = to_u0x((unsigned int)n);
	if (n == 0)
		p->flag[3] = 0;
	if (n == 0 && p->precision == 0)
		ft_bzero(chislo, ft_strlen(chislo));
	if (p->precision > (int)ft_strlen(chislo))
		chislo = ft_upr(&chislo, p->precision);
	return (pr_ux(chislo, p, ft_strlen(chislo), x));
}
