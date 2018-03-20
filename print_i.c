/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:37:08 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 19:37:09 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

char	*to_i0x(int n, char **x)
{
	int				len;
	unsigned int	nn;
	char			*res;

	nn = (n < 0) ? -n : n;
	*x = n < 0 ? "-" : *x;
	len = dow_i0x(nn);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}

char	*ft_ipr(char **str, int precision)
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

int		ficontinue(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (p->flag[2])
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
		while (p->width - res - len - (int)(x != 0) > 0)
			res += write(1, " ", 1);
		if (x)
			res += write(1, x, 1);
		res += write(1, str, len);
	}
	return (res);
}

int		pr_ix(char *str, t_param *p, int len, char *x)
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
	else
		res = ficontinue(str, p, len, x);
	free(str);
	return (res);
}

int		ft_print_i(long long n, t_param *p)
{
	char	*chislo;
	int		len;
	char	*x;

	x = p->flag[4] ? " " : 0;
	x = p->flag[0] ? "+" : x;
	if (!ft_strcmp(p->modificator, "l") || !ft_strcmp(p->modificator, "ll")
	|| !ft_strcmp(p->modificator, "j") || !ft_strcmp(p->type, "D")
	|| !ft_strcmp(p->modificator, "z"))
		chislo = to_i0xl(n, &x);
	else if (!ft_strcmp(p->modificator, "ww"))
		chislo = to_i0x((int)n, &x);
	else if (!ft_strcmp(p->modificator, "h"))
		chislo = to_i0x((short)n, &x);
	else if (!ft_strcmp(p->modificator, "hh"))
		chislo = to_i0x((signed char)n, &x);
	else
		chislo = to_i0x((int)n, &x);
	if (n == 0 && p->precision == 0)
		ft_bzero(chislo, ft_strlen(chislo));
	if (p->precision > (int)ft_strlen(chislo))
		chislo = ft_ipr(&chislo, p->precision);
	len = ft_strlen(chislo);
	return (pr_ix(chislo, p, len, x));
}
