/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:36:46 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 19:36:48 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

char		g_ox[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};

char		*to_o0xl(long long n)
{
	int			len;
	uintmax_t	nn;
	char		*res;

	nn = 1844674407370955161;
	nn = (n < 0) ? nn * 10 + 5 + n + 1 : n;
	len = dow_o0x(n);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = g_ox[nn % 8];
		nn /= 8;
		len--;
	}
	return (res);
}

char		*to_o0x(int n)
{
	int				len;
	unsigned int	nn;
	char			*res;

	nn = (n < 0) ? 4294967295 + n + 1 : n;
	len = dow_o0x(nn);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = g_ox[nn % 8];
		nn /= 8;
		len--;
	}
	return (res);
}

int			focontinue(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (p->flag[2])
	{
		if (p->flag[3])
			res += write(1, x, 1);
		while (p->width - res - len > 0)
			res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len - (int)(p->flag[3] == '#') > 0)
			res += write(1, " ", 1);
		if (p->flag[3])
			res += write(1, x, 1);
		res += write(1, str, len);
	}
	return (res);
}

int			pr_ox(char *str, t_param *p, int len, char *x)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		if (p->flag[3])
			res += write(1, x, 1);
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		if (p->flag[3])
			res += write(1, x, 1);
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else
		res = focontinue(str, p, len, x);
	free(str);
	return (res);
}

int			ft_print_o(long long n, t_param *p)
{
	char *chislo;
	char *x;

	x = "0";
	if (ft_strstr(p->modificator, "l") || !ft_strcmp(p->modificator, "j")
	|| !ft_strcmp(p->type, "O") || !ft_strcmp(p->modificator, "z"))
		chislo = to_o0xl(n);
	else if (!ft_strcmp(p->modificator, "h"))
		chislo = to_o0x((unsigned short)n);
	else if (!ft_strcmp(p->modificator, "hh"))
		chislo = to_o0x((unsigned char)n);
	else
		chislo = to_o0x((int)n);
	if (n == 0 && p->precision == 0)
		ft_bzero(chislo, ft_strlen(chislo));
	else if (n == 0)
	{
		p->flag[3] = '#';
		ft_bzero(chislo, ft_strlen(chislo));
	}
	if (p->precision > (int)ft_strlen(chislo))
		chislo = ft_opr(&chislo, p->precision);
	if (chislo[0] == '0')
		p->flag[3] = 0;
	return (pr_ox(chislo, p, ft_strlen(chislo), x));
}
