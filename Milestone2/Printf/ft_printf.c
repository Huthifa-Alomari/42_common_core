/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 21:12:31 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/20 14:28:17 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			total_len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			total_len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (total_len);
}
