/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:09:42 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/16 00:09:43 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
