/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 18:51:12 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/11 18:51:15 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lensub;
	size_t	i;
	size_t	copylen;
	char	*substr;

	lensub = ft_strlen(s);
	if (start >= lensub)
		copylen = 0;
	else if (len < lensub - start)
		copylen = len;
	else
		copylen = lensub - start;
	substr = malloc(copylen + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < copylen)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*r1;
	char	*r2;
	char	*r3;
	char	*r4;

	r1 = ft_substr("Hello World", 6, 5);
	printf("%s \n", r1);
	r2 = ft_substr("Hi", 0, 100);
	printf("%s \n", r2);
	r3 = ft_substr("Hi", 10, 5);
	printf("%s \n", r3);
	r4 = ft_substr("Hello", 0, 0);
	printf("%s \n", r4);
	return (0);
}*/
