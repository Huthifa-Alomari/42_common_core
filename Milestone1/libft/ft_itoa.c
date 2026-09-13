/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 18:50:46 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/11 18:50:47 by hal-omar         ###   ########.fr       */
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

static void	fill(char *str, size_t i, int n)
{
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
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
	{
		n = -n;
		str[0] = '-';
	}
	i = len - 1;
	fill(str, i, n);
	return (str);
}
/*
#include <stdio.h>


int	main(void)
{
	char	*r1;
	char	*r2;
	char	*r3;
	char	*r4;
	char	*r5;

	r1 = ft_itoa(123);
	printf("Test 1: \"%s\"\n", r1);
	free(r1);

	r2 = ft_itoa(-123);
	printf("Test 2: \"%s\"\n", r2);
	free(r2);

	r3 = ft_itoa(0);
	printf("Test 3: \"%s\"\n", r3);
	free(r3);

	r4 = ft_itoa(2147483647);
	printf("Test 4: \"%s\"\n", r4);
	free(r4);

	r5 = ft_itoa(-2147483648);
	printf("Test 5: \"%s\"\n", r5);
	free(r5);

	return (0);
}*/
