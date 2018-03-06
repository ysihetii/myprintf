/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:18:08 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 14:18:09 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>


int mod(long long int a)
{
	return (a > 0 ? a : -a);
}

int	dow(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}


char	*ft_strnew(size_t size)
{
	char	*q;
	size_t	i;

	q = (char*)malloc((int)size + 1);
	i = 0;
	if (q)
	{
		q[size] = '\0';
		while (i < size)
			q[i++] = 0;
		return (q);
	}
	else
		return (0);
}

char		*ft_itoa(int n)
{
	int		l;
	int		zn;
	char	*res;

	zn = 0;
	if (n < 0)
		zn = 1;
	l = dow(n) + zn;
	res = ft_strnew(l);
	if (!res)
		return (0);
	if (zn)
		res[0] = '-';
	while (l > zn)
	{
		res[l - 1] = '0' + mod(n % 10);
		n /= 10;
		l--;
	}
	return (res);
}

int	ft_atoi(const char *a)
{
	int i;
	int zn;
	int res;

	i = 0;
	zn = 1;
	res = 0;
	while (a[i])
	{
		if ((a[i] >= 9 && a[i] <= 13) || a[i] == ' ')
		{
			i++;
			continue;
		}
		if (a[i] == '-')
			zn = -1;
		if (a[i] == '+' || a[i] == '-')
			i++;
		while (a[i] >= '0' && a[i] <= '9')
			res = res * 10 + zn * (a[i++] - '0');
		return (res);
	}
	return (0);
}
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s2[j] && j + i < n && s1[i + j])
		{
			if (s1[i + j] == s2[j])
				++j;
			else
				break ;
		}
		if (j == (size_t)strlen((char*)s2))
			return (&((char*)s1)[i]);
		i++;
	}
	return (0);
}
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *q;

	q = (char*)malloc(len + 1);
	q[len] = '\0';
	if (!q || !s)
		return (0);
	q = strncpy(q, &(s[start]), len);
	return (q);
}