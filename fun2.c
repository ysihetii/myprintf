/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:10:44 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 21:10:45 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		dow_o0x(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 8;
		i++;
	}
	return (i);
}

char	*to_u0xl(unsigned long long n)
{
	int			len;
	uintmax_t	nn;
	char		*res;

	nn = 1844674407370955161;
	nn = n;
	len = dow_u0x(n);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}

char	*to_u0x(unsigned int n)
{
	int				len;
	unsigned int	nn;
	char			*res;

	nn = n;
	len = dow_u0x(nn);
	res = ft_strnew(len);
	while (len > 0)
	{
		res[len - 1] = '0' + nn % 10;
		nn /= 10;
		len--;
	}
	return (res);
}

char	*ft_opr(char **str, int precision)
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
