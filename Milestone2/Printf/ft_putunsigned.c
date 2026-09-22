/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:33:03 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/21 17:33:04 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
