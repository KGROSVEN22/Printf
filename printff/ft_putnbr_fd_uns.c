/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:55:40 by kgrosven          #+#    #+#             */
/*   Updated: 2023/12/04 11:28:52 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_uns(unsigned int n, int fd)
{
	int		p;

	p = 0;
	if (n >= 10)
	{
		p = ft_error_w(p, ft_putnbr_fd_uns(n / 10, fd));
		if (p == -1)
			return (-1);
	}
	p = ft_error_w(p, ft_putchar_fd(n % 10 + '0', fd));
	if (p == -1)
		return (-1);
	return (p);
}
