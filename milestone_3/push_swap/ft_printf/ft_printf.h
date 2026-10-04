/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 21:50:28 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/04 14:02:37 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_format(va_list args, const char specifier, int fd);
int	ft_putchar(char c, int fd);
int	ft_puthex(unsigned int n, const char format, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_putstr(char *s, int fd);
int	ft_putunsigned(unsigned int n, int fd);
int	ft_putdouble(double nb, int fd);

#endif
