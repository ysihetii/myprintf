/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:50:47 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 20:50:48 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

char	g_x[16] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'a', 'b', 'c', 'd', 'e', 'f'
};

char	*to_0xl(long long n)
{
	int			len;
	uintmax_t	nn;
	char		*res;

	nn = 1844674407370955161;
	nn = (n < 0) ? nn * 10 + 5 + n + 1 : n;
	len = dow_0x(n);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = g_x[nn % 16];
		nn /= 16;
		len--;
	}
	return (res);
}

char	*to_0x(int n)
{
	int				len;
	unsigned int	nn;
	char			*res;

	nn = (n < 0) ? 4294967295 + n + 1 : n;
	len = dow_0x(nn);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = g_x[nn % 16];
		nn /= 16;
		len--;
	}
	return (res);
}

int		fcontinue(char *str, t_param *p, int len, char *x)
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

int		pr_x(char *str, t_param *p, int len, char *x)
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
		res = fcontinue(str, p, len, x);
	free(str);
	return (res);
}

int		ft_print_x(long long n, t_param *p)
{
	char	*chislo;
	char	*x;

	x = ft_strcmp(p->type, "X") ? "0x" : "0X";
	if (ft_strstr(p->modificator, "l") || !ft_strcmp(p->modificator, "j")
	|| !ft_strcmp(p->modificator, "z"))
		chislo = to_0xl(n);
	else if (!ft_strcmp(p->modificator, "h"))
	{
		chislo = to_0x((unsigned short)n);
	}
	else if (!ft_strcmp(p->modificator, "hh"))
		chislo = to_0x((unsigned char)n);
	else
		chislo = to_0x((int)n);
	if (n == 0)
		p->flag[3] = 0;
	if (n == 0 && p->precision == 0)
		ft_bzero(chislo, ft_strlen(chislo));
	if (p->precision > (int)ft_strlen(chislo))
		chislo = ft_pr(&chislo, p->precision);
	if (!ft_strcmp(p->type, "X"))
		to_upper(chislo);
	return (pr_x(chislo, p, ft_strlen(chislo), x));
}
