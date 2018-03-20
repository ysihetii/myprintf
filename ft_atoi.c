/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:18:08 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 22:16:35 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

void	to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
}

char	*ft_pr(char **str, int precision)
{
	int		len;
	int		i;
	char	*res;

	len = ft_strlen(*str);
	res = ft_strnew(precision);
	i = 0;
	while (i < precision)
	{
		if (i < precision - len)
			res[i] = '0';
		else
			res[i] = (*str)[i + len - precision];
		i++;
	}
	free(*str);
	return (res);
}

int		dow_0x(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		print_flag_and_widthss(int len, t_param *p, char *str)
{
	int i;

	i = len;
	if (p->flag[1])
	{
		write(1, str, len);
		while (i++ < p->width)
			write(1, " ", 1);
	}
	else if (p->flag[2])
	{
		while (i++ < p->width)
			write(1, "0", 1);
		write(1, str, len);
	}
	else
	{
		while (i++ < p->width)
			write(1, " ", 1);
		write(1, str, len);
	}
	return (p->width);
}

int		fssscontinue(char *str, t_param *p, int len)
{
	int res;

	res = 0;
	if (p->flag[2])
	{
		while (p->width - res - len > 0)
			if (p->precision > -1)
				res += write(1, "0", 1);
			else
				res += write(1, "0", 1);
		res += write(1, str, len);
	}
	else
	{
		while (p->width - res - len)
			res += write(1, " ", 1);
		res += write(1, str, len);
	}
	return (res);
}
