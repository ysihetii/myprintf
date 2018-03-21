/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:54:34 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 21:54:35 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_kokoko(int *st, int *fin, char const *s)
{
	while (s[*st])
	{
		if (s[*st] != ' ' && s[*st] != ',' && s[*st] != '\n' && s[*st] != '\t')
			break ;
		++*st;
	}
	while (*fin >= 0)
	{
		if (s[*fin] != ' ' && s[*fin] != ',' &&
			s[*fin] != '\n' && s[*fin] != '\t')
			break ;
		--*fin;
	}
}

char			*ft_strtrim(char const *s)
{
	int		st;
	int		fin;
	char	*res;

	if (!s)
		return (0);
	st = 0;
	fin = ft_strlen((char*)s) - 1;
	ft_kokoko(&st, &fin, s);
	if (st > fin)
		return (ft_strnew(0));
	res = ft_strnew(fin - st + 1);
	if (!res)
		return (0);
	res = ft_strncpy(res, &s[st], fin - st + 1);
	return (res);
}
