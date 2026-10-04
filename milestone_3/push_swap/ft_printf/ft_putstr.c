/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:27:55 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/04 14:06:41 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	len;

	if (!s)
		return (write(fd, "(null)", 6));
	len = 0;
	while (s[len])
	{
		write(fd, &s[len], 1);
		len++;
	}
	return (len);
}
