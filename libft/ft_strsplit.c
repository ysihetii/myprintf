/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:14:32 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/13 12:14:33 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordc(char const *s, char c)
{
	int i;
	int in;
	int res;

	i = 0;
	res = 0;
	in = 0;
	while (s[i])
	{
		if (!in && s[i] != c)
			in = 1;
		else if (in && s[i] == c)
		{
			in = 0;
			res++;
		}
		i++;
	}
	if (in)
		res++;
	return (res);
}

static char		*ft_getword(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (ft_strsub(s, 0, i));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		in;

	if (!s)
		return (0);
	res = (char**)malloc(sizeof(char*) * (ft_wordc(s, c) + 1));
	if (!res)
		return (0);
	res[ft_wordc(s, c)] = 0;
	j = 0;
	i = 0;
	in = 0;
	while (s[i++])
	{
		if (!in && s[i - 1] != c)
		{
			in = 1;
			res[j++] = ft_getword(&(s[i - 1]), c);
		}
		else if (in && s[i - 1] == c)
			in = 0;
	}
	return (res);
}
