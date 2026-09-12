/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 18:51:01 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/11 18:51:02 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_split(char **res, size_t word_i)
{
	size_t	j;

	j = 0;
	while (j < word_i)
	{
		free(res[j]);
		j++;
	}
	free(res);
}

static void	find_word(char const *s, char c, size_t *i, size_t *start)
{
	while (s[*i] == c)
		(*i)++;
	*start = *i;
	while (s[*i] != '\0' && s[*i] != c)
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	size_t	nword;
	size_t	i;
	size_t	start;
	size_t	word_i;
	char	**res;

	nword = word_count(s, c);
	res = malloc((nword + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	word_i = 0;
	while (word_i < nword)
	{
		find_word(s, c, &i, &start);
		res[word_i] = ft_substr(s, start, i - start);
		if (!res[word_i])
		{
			free_split(res, word_i);
			return (NULL);
		}
		word_i++;
	}
	res[nword] = NULL;
	return (res);
}
/*
#include <stdio.h>

int    main(void)
{
    char    **result;
    int        i;

    result = ft_split("the,quick,brown,fox", ',');
    i = 0;
    while (result[i])
    {
        printf("[%s]\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}*/
