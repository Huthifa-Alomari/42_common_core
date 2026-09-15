/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 18:50:46 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/15 14:55:57 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	fill(char *str, size_t i, int n,int neg)
{
	if (n == 0)
	{
		str[i] = '0';
		return;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*str;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_digit(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	neg = (n < 0);
	if (neg)
		n = -n;
	i = len - 1;
	fill(str, i, n,neg);
	return (str);
}
