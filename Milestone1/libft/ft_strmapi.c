/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 18:51:07 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/11 18:51:08 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	// lens ? 
	// char nstr
	// malloc nstr + 1
	// loop 0 ~ len
	// 	nstr[i] = f(i,s[i])
	// nstr[len] = '\0'
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
/*
#include <stdio.h>

char	my_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*r1;

	r1 = ft_strmapi("hello", my_upper);
	printf("Test 1: \"%s\"\n", r1);
	free(r1);

	return (0);
}
*/
