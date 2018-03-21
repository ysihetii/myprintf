/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:12:43 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/09 20:12:45 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char		*temp;
	char const	*s;

	if (dst <= src)
	{
		temp = (char *)dst;
		s = (char *)src;
		while (len--)
			*temp++ = *s++;
	}
	else
	{
		temp = (char *)dst;
		temp += len;
		s = src;
		s += len;
		while (len--)
			*--temp = *--s;
	}
	return (dst);
}
