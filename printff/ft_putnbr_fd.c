/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:57:20 by kgrosven          #+#    #+#             */
/*   Updated: 2023/12/04 11:34:23 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	int	p;

	p = 0;
	if (n == -2147483648)
		return (ft_error_w(p, write(fd, "-2147483648", 11)));
	if (n < 0)
	{
		p = ft_error_w(p, ft_putchar_fd('-', fd));
		if (p == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		p = ft_error_w(p, ft_putnbr_fd(n / 10, fd));
		if (p == -1)
			return (-1);
	}
	p = ft_error_w(p, ft_putchar_fd(n % 10 + '0', fd));
	if (p == -1)
		return (-1);
	return (p);
}
