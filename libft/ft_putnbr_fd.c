/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihetii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:42:14 by ysihetii          #+#    #+#             */
/*   Updated: 2017/11/12 21:42:15 by ysihetii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < -9 || n > 9)
	{
		ft_putnbr_fd(mod(n / 10), fd);
		ft_putchar_fd(mod(n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(mod(n % 10) + '0', fd);
}
