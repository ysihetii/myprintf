/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:29:14 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 20:29:15 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dow(int n)
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

char		*ft_itoa(int n)
{
	int		l;
	int		zn;
	char	*res;

	zn = 0;
	if (n < 0)
		zn = 1;
	l = dow(n) + zn;
	res = ft_strnew(l);
	if (!res)
		return (0);
	if (zn)
		res[0] = '-';
	while (l > zn)
	{
		res[l - 1] = '0' + mod(n % 10);
		n /= 10;
		l--;
	}
	return (res);
}
