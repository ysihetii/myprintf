/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:51:27 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 17:51:28 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*q;
	size_t	i;

	q = (char*)malloc((int)size + 1);
	i = 0;
	if (q)
	{
		q[size] = '\0';
		while (i < size)
			q[i++] = 0;
		return (q);
	}
	else
		return (0);
}
