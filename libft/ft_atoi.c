/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:18:08 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 14:18:09 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *a)
{
	int i;
	int zn;
	int res;

	i = 0;
	zn = 1;
	res = 0;
	while (a[i])
	{
		if ((a[i] >= 9 && a[i] <= 13) || a[i] == ' ')
		{
			i++;
			continue;
		}
		if (a[i] == '-')
			zn = -1;
		if (a[i] == '+' || a[i] == '-')
			i++;
		while (a[i] >= '0' && a[i] <= '9')
			res = res * 10 + zn * (a[i++] - '0');
		return (res);
	}
	return (0);
}
