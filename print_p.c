/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:56:12 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 19:56:12 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

char	g_xp[16] =
{
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

char	*to_p0xl(unsigned long long n)
{
	int		len;
	char	*res;

	len = dow_p0x(n);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = g_xp[n % 16];
		n /= 16;
		len--;
	}
	return (res);
}

char	*ft_ppr(char **str, int precision)
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

int		fpcontinue(char *str, t_param *p, int len, char *x)
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

int		pr_ppx(char *str, t_param *p, int len, char *x)
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
		res = fpcontinue(str, p, len, x);
	free(str);
	return (res);
}

int		ft_print_p(unsigned long long n, t_param *p)
{
	char	*chislo;
	int		len;
	char	*x;

	p->flag[3] = '#';
	x = "0x";
	chislo = to_p0xl(n);
	if (n == 0 && p->precision == 0)
	{
		free(chislo);
		chislo = ft_strnew(0);
	}
	if (p->precision > (int)ft_strlen(chislo))
		chislo = ft_ppr(&chislo, p->precision);
	len = ft_strlen(chislo);
	return (pr_ppx(chislo, p, len, x));
}
