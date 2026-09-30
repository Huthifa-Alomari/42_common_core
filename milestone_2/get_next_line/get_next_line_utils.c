/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:06:06 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/26 13:56:19 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lensub;
	size_t	i;
	size_t	copylen;
	char	*substr;

	lensub = gnl_strlen(s);
	if (start >= lensub)
		copylen = 0;
	else if (len < lensub - start)
		copylen = len;
	else
		copylen = lensub - start;
	substr = malloc(copylen + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < copylen)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*nstr;

	if (!s1)
		return (gnl_substr(s2, 0, gnl_strlen(s2)));
	nstr = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!nstr)
		return (free((char *)s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
		nstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		nstr[j++] = s2[i++];
	nstr[j] = '\0';
	free((char *)s1);
	return (nstr);
}
