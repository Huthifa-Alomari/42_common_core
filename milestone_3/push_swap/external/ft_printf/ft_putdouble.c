/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:29:36 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/02 19:35:22 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdouble(double nb)
{
	long	int_part;
	double	frac_part;
	int		precision;

	precision = 6;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	int_part = (long)nb;
	frac_part = nb - (double)int_part;
	ft_putnbr(int_part);
	ft_putchar('.');
	while (precision--)
	{
		frac_part *= 10;
		ft_putchar((int)frac_part + '0');
		frac_part -= (int)frac_part;
	}
	return (0);
}
