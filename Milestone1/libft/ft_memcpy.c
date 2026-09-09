/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:06:10 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/09 20:36:20 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    // Test 1: Basic string copy
    char src1[] = "42 School";
    char dest1[20] = {0};
    ft_memcpy(dest1, src1, 9);
    printf("Basic copy:        %s (Expected: 42 School)\n", dest1);

    // Test 2: Zero bytes requested
    char src2[] = "Do not copy";
    char dest2[] = "Initial Value";
    ft_memcpy(dest2, src2, 0);
    printf("Zero bytes check:  %s (Expected: Initial Value)\n", dest2);

    // Test 3: Raw binary / embedded null bytes data
    char src3[] = "A\0B\0C";
    char dest3[] = "XXXXXXXXX";
    ft_memcpy(dest3, src3, 5);
    printf("Binary elements:   dest[2] = %c, dest[4] = %c (Expected: B, C)\n", dest3[2], dest3[4]);

    // Test 4: Non-char block copying (integer arrays)
    int src_ints[] = {42, 1337, 2026};
    int dest_ints[3] = {0};
    ft_memcpy(dest_ints, src_ints, sizeof(src_ints));
    printf("Int array copy:    %d, %d, %d (Expected: 42, 1337, 2026)\n", dest_ints[0], dest_ints[1], dest_ints[2]);

    // Test 5: Double NULL guard
    void *res = ft_memcpy(NULL, NULL, 5);
    printf("Double NULL guard: %s\n", res == NULL ? "OK" : "CRASH/FAIL");

    return (0);
}*/
