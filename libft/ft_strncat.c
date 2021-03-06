/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:50:51 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/11 15:50:53 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t l;

	l = ft_strlen(s1);
	i = l;
	while (s2[i - l] && i < l + n)
	{
		s1[i] = s2[i - l];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
