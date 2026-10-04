/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:29:36 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/04 14:17:15 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdouble(double nb, int fd)
{
	long	int_part;
	int		len;
	int		i;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-', fd);
		nb = -nb;
	}
	int_part = (long)nb;
	len += ft_putnbr(int_part, fd);
	len += ft_putchar('.', fd);
	nb = nb - int_part;
	i = 2;
	while (i--)
	{
		nb = nb * 10;
		len += ft_putchar((int)nb + '0', fd);
		nb = nb - (int)nb;
	}
	return (len);
}
