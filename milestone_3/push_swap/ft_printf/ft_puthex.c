/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:11:10 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/04 14:07:42 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, const char format, int fd)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format, fd);
	}
	count += ft_putchar(base[n % 16], fd);
	return (count);
}
