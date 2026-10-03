/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:11:00 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/21 18:11:01 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_recursive(unsigned long addr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (addr >= 16)
		count += ft_ptr_recursive(addr / 16);
	count += ft_putchar(base[addr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	count += ft_ptr_recursive(addr);
	return (count);
}
