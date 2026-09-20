/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 22:23:48 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/19 22:24:29 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_eval(va_list args, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		; // Call ft_print_char(va_arg(args, int))
	else if (specifier == 's')
		; // Call ft_print_str(va_arg(args, char *))
	else if (specifier == 'd' || specifier == 'i')
		; // Call ft_print_nbr(va_arg(args, int))
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
