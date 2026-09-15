/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:08:17 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/16 00:08:19 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				j;
	unsigned char		*d;
	const unsigned char	*s;

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
