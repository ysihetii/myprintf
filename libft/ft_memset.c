/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:24:29 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/08 19:24:43 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *str, int val, size_t n)
{
	size_t	i;
	char	q;

	i = 0;
	q = val;
	while (i < n)
	{
		((char*)str)[i] = q;
		i++;
	}
	return (str);
}
