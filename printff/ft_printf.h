/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:12:33 by kgrosven          #+#    #+#             */
/*   Updated: 2023/12/04 13:50:38 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_check_arguments(char c, va_list args);
int	ft_error_w(int print_count, int write_return);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_fd_uns(unsigned int n, int fd);
int	ft_putnbr_fd_hex(unsigned long n, int fd, int uppercase);
int	ft_putptr_fd(unsigned long ptr, int fd);

#endif
