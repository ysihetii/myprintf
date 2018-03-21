/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:19:50 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 19:19:51 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (!s1[0] && !s2[0])
		return (1);
	else if (!s1[0] || !s2[0])
		return (0);
	if (ft_strcmp(s1, s2))
		return (0);
	else
		return (1);
}
