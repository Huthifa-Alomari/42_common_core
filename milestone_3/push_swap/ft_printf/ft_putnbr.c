/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:39:40 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/04 14:10:50 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int fd)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10, fd);
	}
	count += ft_putchar((nb % 10) + '0', fd);
	return (count);
}
