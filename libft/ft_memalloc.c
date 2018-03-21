/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:24:59 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 17:25:00 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*q;
	size_t			i;

	q = (unsigned char*)malloc((int)size);
	i = 0;
	if (q)
	{
		while (i < size)
			q[i++] = '\0';
		return (q);
	}
	else
		return (0);
}
