/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:10:54 by kgrosven          #+#    #+#             */
/*   Updated: 2023/12/04 12:29:50 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	p;

	p = 0;
	if (!s)
	{
		p = ft_error_w(p, ft_putstr_fd("(null)", 1));
		if (p == -1)
			return (-1);
		return (6);
	}
	while (*s)
	{
		p = ft_error_w(p, write(fd, s, 1));
		if (p == -1)
			return (-1);
		s++;
	}
	return (p);
}
