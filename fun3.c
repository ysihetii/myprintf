/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 22:13:33 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 22:13:34 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		dow_i0x(unsigned long long n)
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

char	*to_i0xl(long long n, char **x)
{
	int			len;
	uintmax_t	nn;
	char		*res;

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

int		dow_p0x(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
