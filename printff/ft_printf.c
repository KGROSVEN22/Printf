/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:40:40 by kgrosven          #+#    #+#             */
/*   Updated: 2023/12/04 12:02:32 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_error_w(int print_count, int write_return)
{
	if (print_count < 0 || write_return < 0)
		return (-1);
	else
		return (print_count + write_return);
}

int	ft_check_arguments(char c, va_list args)
{
	int	p;

	p = 0;
	if (c == '%')
		p = ft_error_w(p, ft_putchar_fd('%', 1));
	if (c == 'c')
		p = ft_error_w(p, ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		p = ft_error_w(p, ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		p = ft_error_w(p, ft_putptr_fd(va_arg(args, unsigned long), 1));
	if (c == 'd' || c == 'i')
		p = ft_error_w(p, ft_putnbr_fd(va_arg(args, int), 1));
	if (c == 'u')
		p = ft_error_w(p, ft_putnbr_fd_uns(va_arg(args, int), 1));
	if (c == 'x')
		p = ft_error_w(p, ft_putnbr_fd_hex(va_arg(args, unsigned int), 1, 0));
	if (c == 'X')
		p = ft_error_w(p, ft_putnbr_fd_hex(va_arg(args, unsigned int), 1, 1));
	if (p == -1)
		return (-1);
	return (p);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		p;

	va_start(args, str);
	p = 0;
	while (*str)
	{
		if (*str == '%')
		{
			p = ft_error_w(p, ft_check_arguments(*(++str), args));
			if (p == -1)
				return (-1);
		}
		else
		{
			p = ft_error_w(p, write(1, str, 1));
			if (p == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (p);
}
