/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:07:07 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/09 20:37:11 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char		*d;
	const unsigned char		*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	j = ft_strlen(src);

	if (size == 0)
	{
		return (j);
	}
	while (s[i] && i < size - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (j);
}
/*
#include <stdio.h>

int main(void)
{
    // 1. Normal Copy
    char dst1[10] = "XXXXXXXXX";
    size_t ret1 = ft_strlcpy(dst1, "Hello", 10);
    printf("Test 1 (Normal): String = \"%s\", Return = %zu (Expected: \"Hello\", 5)\n", dst1, ret1);

    // 2. Exact Fit
    char dst2[3] = "XXX";
    size_t ret2 = ft_strlcpy(dst2, "42", 3);
    printf("Test 2 (Exact):  String = \"%s\", Return = %zu (Expected: \"42\", 2)\n", dst2, ret2);

    // 3. Truncation
    char dst3[5] = "XXXXX";
    size_t ret3 = ft_strlcpy(dst3, "Lancaster", 5);
    printf("Test 3 (Trunc):  String = \"%s\", Return = %zu (Expected: \"Lanc\", 9)\n", dst3, ret3);

    // 4. Size Zero (Buffer should remain untouched)
    char dst4[10] = "Untouched";
    size_t ret4 = ft_strlcpy(dst4, "Norminette", 0);
    printf("Test 4 (Size 0): String = \"%s\", Return = %zu (Expected: \"Untouched\", 10)\n", dst4, ret4);

    // 5. Size One
    char dst5[5] = "XXXXX";
    size_t ret5 = ft_strlcpy(dst5, "Pool", 1);
    printf("Test 5 (Size 1): String = \"%s\", Return = %zu (Expected: \"\", 4)\n", dst5, ret5);

    // 6. Empty Source
    char dst6[5] = "XXXXX";
    size_t ret6 = ft_strlcpy(dst6, "", 5);
    printf("Test 6 (Empty):  String = \"%s\", Return = %zu (Expected: \"\", 0)\n", dst6, ret6);

    return (0);
}
*/
