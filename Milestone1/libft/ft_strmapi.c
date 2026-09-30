/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:08:40 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/16 00:22:42 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*nstr;

	len = ft_strlen(s);
	nstr = malloc(len + 1);
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[len] = '\0';
	return (nstr);
}
