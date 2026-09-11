/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 18:51:05 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/11 18:51:06 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*nstr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	nstr = malloc((len1 + len2) + 1);
	if (!nstr)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		nstr[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		nstr[i] = s2[i - len1];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strjoin("Hello World", "Huthifa"));
	return (0);
}
