/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:07:12 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/09 20:36:46 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t                  dest_size;
	size_t                  src_size;
	size_t			i;

	src_size = ft_strlen(src);
	i = 0;

	if (size == 0)
		return (src_size);
        dest_size = ft_strlen(dst);

	if (dest_size >= size)
		return (size + src_size);
	if (size >= (dest_size + src_size))
	{
		while (src[i] && (dest_size + i < size - 1))
		{
			dst[dest_size + i] = src[i];
			i++;
		}
		dst[dest_size + i] = '\0';
	}
	else
	{
		while (src[i] && (dest_size + i < size - 1))
                {
                        dst[dest_size + i] = src[i];
                        i++;
                }
		dst[dest_size + i] = '\0';
		return (dest_size + src_size);
	}
	return (dest_size + src_size);
}
/*
#include <stdio.h>
int main(void) {
    char buf[8] = "42";
    printf("Return: %zu | Buf: %s\n", ft_strlcat(buf, "Network", 8), buf);
    return (0);
}

*/
