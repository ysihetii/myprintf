/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:29:33 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 20:29:34 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		pr_sxss(char *str, t_param *p, int len)
{
	int res;

	res = 0;
	if (len >= p->width)
	{
		res += write(1, str, len);
	}
	else if (p->flag[1])
	{
		res += write(1, str, len);
		while (p->width - res > 0)
			res += write(1, " ", 1);
	}
	else
		res = fssscontinue(str, p, len);
	if (str)
		free(str);
	return (res);
}

int		ft_print_unicodesss(char *s, wchar_t n)
{
	if (n <= 127 || MB_CUR_MAX == 1)
		*s = n;
	else if (n <= 2047)
	{
		s[0] = (n >> 6) | 192;
		s[1] = (n & 63) | 128;
	}
	else if (n <= 65535)
	{
		s[0] = (n >> 12) | 224;
		s[1] = ((n >> 6) & 63) | 128;
		s[2] = (n & 63) | 128;
	}
	else
	{
		s[0] = (n >> 18) | 240;
		s[1] = ((n >> 12) & 63) | 128;
		s[2] = ((n >> 6) & 63) | 128;
		s[3] = (n & 63) | 128;
	}
	return (ft_strlen(s));
}

void	get_str(wchar_t *sstr, t_param *p, char *str)
{
	char	*s;
	int		k;
	int		i;

	str = (!sstr) ? ft_strcpy(str, "(null)") : str;
	s = ft_strnew(4);
	k = 0;
	i = 0;
	if (sstr)
		while (*sstr)
		{
			ft_bzero(s, ft_strlen(s));
			i = ft_print_unicodesss(s, *sstr);
			if ((p->precision != -17777 && p->precision >= k + i)
			|| p->precision == -17777)
			{
				ft_strcpy(&str[k], s);
				sstr++;
			}
			else
				break ;
			k += i;
		}
	if (s)
		free(s);
}

int		dododo(t_param *p)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (i++ < p->width)
		if (p->flag[2])
			res += write(1, "0", 1);
		else
			res += write(1, " ", 1);
	return (res);
}

int		ft_print_sss(wchar_t *sstr, t_param *p)
{
	int		i;
	int		res;
	char	*str;
	int		len;

	i = 0;
	res = 0;
	while (sstr && sstr[i])
		i++;
	str = ft_strnew((i + 7) * MB_CUR_MAX);
	get_str(sstr, p, str);
	i = 0;
	len = (p->precision < (int)ft_strlen(str) &&
	p->precision != -17777) ? p->precision : ft_strlen(str);
	if (p->precision == 0)
		res = dododo(p);
	else if (p->precision < 0 && p->precision != -17777)
		while (i-- > p->precision)
			res += write(1, " ", 1);
	else if (len >= p->width)
		res += write(1, str, len);
	else
		return (pr_sxss(str, p, len));
	ft_strdel(&str);
	return (res);
}
