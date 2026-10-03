/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:29:36 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 18:59:50 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdouble(double nb)
{
	long	i;
	int		len;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	i = (long)nb;
	ft_putnbr(i);
	while (i >= 10 && (i /= 10))
		len++;
	len += ft_putchar('.');
	i = 6;
	while (i--)
	{
		nb = (nb - (long)nb) * 10;
		len += ft_putchar((int)nb + '0');
	}
	return (len + 1);
}
