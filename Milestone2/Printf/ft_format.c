/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 22:23:48 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/21 13:46:53 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar(va_arg(args,int));
	else if (specifier == 's')
		len += ft_putchar(va_arg(args,int));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr(va_arg(args,int));
	else if (specifier == 'u')
		; // Call ft_print_unsigned(va_arg(args, unsigned int))
	else if (specifier == 'x' || specifier == 'X')
		; // Call ft_print_hex(va_arg(args, unsigned int), specifier)
	else if (specifier == 'p')
		; // Call ft_print_ptr(va_arg(args, void *))
	else if (specifier == '%')
		len += write(1, "%", 1);
	return (len);
}
