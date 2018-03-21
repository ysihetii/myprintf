/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:28:36 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 19:28:37 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if ((!s1[0] && !s2[0]) || (!n))
		return (1);
	else if (!s1[0] || !s2[0])
		return (0);
	if (ft_strncmp(s1, s2, n))
		return (0);
	else
		return (1);
}
