/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:19:53 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/11 20:19:54 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	q;

	q = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == q)
			return (&((char*)s)[i]);
		i++;
	}
	if (s[i] == q)
		return (&((char*)s)[i]);
	return (0);
}
