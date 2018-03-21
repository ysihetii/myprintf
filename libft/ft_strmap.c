/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:58:17 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 18:58:18 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*q;

	if (!s)
		return (0);
	i = 0;
	q = ft_strnew(ft_strlen((char*)s));
	if (!q)
		return (0);
	if (!s)
		return (0);
	while (s[i])
	{
		q[i] = f(s[i]);
		i++;
	}
	return (q);
}
