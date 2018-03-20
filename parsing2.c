/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:04:53 by ysihetii          #+#    #+#             */
/*   Updated: 2018/03/19 21:04:55 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_param		*ft_new_p(t_param *p)
{
	int i;

	i = 0;
	p->param = -1;
	while (i < 5)
	{
		p->flag[i] = 0;
		i++;
	}
	p->width = 0;
	p->precision = -17777;
	p->modificator[2] = '\0';
	ft_strcpy(p->modificator, "ww");
	p->type[2] = '\0';
	ft_strcpy(p->type, "ww");
	return (p);
}

int			prosto_function(char format, int n, char *this)
{
	if (!not_alph(format) && n != 5)
	{
		*this = 'q';
		return (1);
	}
	return (0);
}

void		do_manipulations(char **format, t_param **p, int is_valid)
{
	char *ss;

	ss = ft_strsub(*format, 1, is_valid - 1);
	ft_work_with_param(ss, *p);
	free(ss);
	*format += is_valid;
}

void		ft_preludiya(t_param **p, int *res)
{
	*p = (t_param*)malloc(sizeof(t_param));
	*res = 0;
}

int			chtototamneto(int is_valid, char **format)
{
	if (is_valid < 0)
	{
		while (not_alph(**format) && **format)
			(*format)++;
		return (1);
	}
	return (0);
}
