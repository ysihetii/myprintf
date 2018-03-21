/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:03:39 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/11 16:03:41 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t l;

	l = ft_strlen(dst);
	i = l;
	if (!dstsize)
		return (ft_strlen((char*)src));
	while (i < dstsize - 1)
	{
		dst[i] = src[i - l];
		i++;
	}
	while (i < dstsize)
		dst[i++] = '\0';
	return (min(l, dstsize) + ft_strlen((char*)src));
}
