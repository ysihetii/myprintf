/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:17:08 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 19:17:09 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*q;

	if (!s || !f)
		return (0);
	i = 0;
	q = ft_strnew(ft_strlen((char*)s));
	if (!q)
		return (0);
	if (!s)
		return (0);
	while (s[i])
	{
		q[i] = f(i, s[i]);
		i++;
	}
	return (q);
}
