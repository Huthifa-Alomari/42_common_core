/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 00:10:02 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/16 00:10:04 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	trim(char const *s1, char *set, size_t *start, size_t *end)
{
	*start = 0;
	while (s1[*start] && in_set(s1[*start], set))
		(*start)++;
	*end = ft_strlen(s1);
	if (*end > 0)
		(*end)--;
	while (*end > *start && in_set(s1[*end], set))
		(*end)--;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	start;
	size_t	end;
	size_t	i;

	if (set[0] == '\0')
		return (ft_strdup(s1));
	trim(s1, (char *)set, &start, &end);
	if (!s1[start] || in_set(s1[start], (char *)set))
		return (ft_strdup(""));
	string = malloc(end - start + 2);
	if (!string)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		string[i] = s1[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
