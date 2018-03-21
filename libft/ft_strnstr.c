/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:45:34 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 15:45:35 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s2[j] && j + i < n && s1[i + j])
		{
			if (s1[i + j] == s2[j])
				++j;
			else
				break ;
		}
		if (j == (size_t)ft_strlen((char*)s2))
			return (&((char*)s1)[i]);
		i++;
	}
	return (0);
}
