/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:50:00 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 19:50:01 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *q;

	if (!s1 || !s2)
		return (0);
	q = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	if (!q)
		return (0);
	q = ft_strcpy(q, s1);
	q = ft_strcat(q, s2);
	return (q);
}
