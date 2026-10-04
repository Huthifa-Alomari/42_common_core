/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 22:23:48 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/04 14:10:10 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char specifier, int fd)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar(va_arg(args, int), fd);
	else if (specifier == 's')
		len += ft_putstr(va_arg(args, char *), fd);
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args, int), fd);
	else if (specifier == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int), fd);
	else if (specifier == 'x' || specifier == 'X')
		len += ft_puthex(va_arg(args, unsigned int), specifier, fd);
	else if (specifier == 'p')
		len += ft_putptr(va_arg(args, void *), fd);
	else if (specifier == 'f')
		len += ft_putdouble(va_arg(args, double), fd);
	else if (specifier == '%')
		len += write(fd, "%", 1);
	return (len);
}
