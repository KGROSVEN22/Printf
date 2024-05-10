/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:16:39 by kgrosven          #+#    #+#             */
/*   Updated: 2023/12/04 11:16:43 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(unsigned long ptr, int fd)
{
	int		p;

	p = 0;
	p = ft_error_w(p, ft_putstr_fd("0x", fd));
	if (p == -1)
		return (-1);
	p = ft_error_w(p, ft_putnbr_fd_hex(ptr, fd, 0));
	if (p == -1)
		return (-1);
	return (p);
}
