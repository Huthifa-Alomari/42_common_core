/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:06:12 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/10 19:54:10 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest <= src)// 1) no overlap || 2) overlap with dest lower than src || 3) dest == src 
	{
		i = 0;
		while(i < n)
		{	
			d[i] = s[i];
			i++;
		}
	}
	else // dest > src ==> 1) normal || 2) union 
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
int main(void)
{
    // Test 1: Overlap where dest is ahead of src (tricky case)
    char str1[] = "123456789";
    ft_memmove(str1 + 2, str1, 5);
    printf("Overlap (dest > src): %s (Expected: 121234589)\n", str1);

    // Test 2: Overlap where dest is behind src
    char str2[] = "123456789";
    ft_memmove(str2, str2 + 2, 5);
    printf("Overlap (dest < src): %s (Expected: 345676789)\n", str2);

    // Test 3: Normal copy without overlap
    char src1[] = "Hello";
    char dest1[] = "abcdefghij";
    ft_memmove(dest1 + 5, src1, 5);
    printf("Normal non-overlap:   %s (Expected: abcdeHello)\n", dest1);

    // Test 4: Zero bytes requested
    char src2[] = "Don't copy";
    char dest2[] = "Keep me";
    ft_memmove(dest2, src2, 0);
    printf("Zero bytes check:     %s (Expected: Keep me)\n", dest2);

    // Test 5: Double NULL guard
    void *res = ft_memmove(NULL, NULL, 5);
    printf("Double NULL guard:    %s\n", res == NULL ? "OK" : "CRASH/FAIL");

    return (0);
}*/
