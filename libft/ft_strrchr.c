/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:26:55 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 15:26:56 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	q;

	q = (char)c;
	i = ft_strlen((char*)s);
	if (s[i] == q)
		return (&((char*)s)[i]);
	while (i >= 0)
	{
		if (s[i] == q)
			return (&((char*)s)[i]);
		i--;
	}
	return (0);
}
