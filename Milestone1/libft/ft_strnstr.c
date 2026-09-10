/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:07:17 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/10 17:31:13 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t    i;
    size_t    j;

    if (little[0] == '\0')
        return ((char *)big);
    i = 0;
    while (big[i] != '\0' && i < len)
    {
        j = 0;
        while (big[i + j] == little[j] && big[i + j] && little[j] && i + j < len)
        {

            j++;
        }
        if (little[j] == '\0')
            return ((char *)big + i);
        i++;
    }
    if (j == '\0')
        return ((char *)big + i);
}


#include <stdio.h>
#include <string.h>

int main(void)
{
    char    *result;

    /* 1. Normal match at beginning */
    result = ft_strnstr("Hello World", "Hello", 11);
    printf("1: %s\n", result);

    /* 2. Match in middle */
    result = ft_strnstr("Hello World", "World", 11);
    printf("2: %s\n", result);

    /* 3. Match at end */
    result = ft_strnstr("Hello World", "ld", 11);
    printf("3: %s\n", result);

    /* 4. No match */
    result = ft_strnstr("Hello World", "Cat", 11);
    printf("4: %s\n", result);

    /* 5. Partial match, but not complete */
    result = ft_strnstr("Hello", "Help", 5);
    printf("5: %s\n", result);

    /* 6. little is empty */
    result = ft_strnstr("Hello World", "", 11);
    printf("6: %s\n", result);

    /* 7. big is empty */
    result = ft_strnstr("", "Hello", 5);
    printf("7: %s\n", result);

    /* 8. little longer than big */
    result = ft_strnstr("Hi", "Hello", 2);
    printf("8: %s\n", result);

    /* 9. len is too small to reach the match */
    result = ft_strnstr("Hello World", "World", 5);
    printf("9: %s\n", result);

    /* 10. len cuts through a possible match */
    result = ft_strnstr("Hello World", "World", 8);
    printf("10: %s\n", result);

    /* 11. len exactly allows the match */
    result = ft_strnstr("Hello World", "World", 11);
    printf("11: %s\n", result);

    /* 12. len == 0 */
    result = ft_strnstr("Hello", "H", 0);
    printf("12: %s\n", result);

    /* 13. Multiple occurrences */
    result = ft_strnstr("Hello Hello", "Hello", 11);
    printf("13: %s\n", result);

    /* 14. Single character */
    result = ft_strnstr("Hello", "l", 5);
    printf("14: %s\n", result);

    return (0);
}
