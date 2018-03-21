/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:43:22 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 19:43:24 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *q;

	q = (char*)malloc(len + 1);
	q[len] = '\0';
	if (!q || !s)
		return (0);
	q = ft_strncpy(q, &(s[start]), len);
	return (q);
}
