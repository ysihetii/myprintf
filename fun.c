/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:02:09 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 20:02:10 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		find_h(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h' && ((i == 0 && str[i + 1] != 'h')
		|| (str[i + 1] != 'h' && str[i - 1] != 'h')))
			return (1);
		i++;
	}
	return (0);
}

int		ft_pass_digit(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		not_alph(char c)
{
	char *alph;

	alph = "0123456789. +-#sSpdDioOuUxXcChljz%";
	return ((int)ft_strchr(alph, c));
}

int		is_dig(char c)
{
	return (c >= '0' && c <= '9');
}

int		find_z(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' && (i == 0 ||
		!is_dig(str[i - 1])) && str[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}
