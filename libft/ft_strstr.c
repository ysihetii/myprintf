/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:31:27 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 15:31:28 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j])
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
