/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:05:35 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/27 14:58:42 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while ((!stash || !gnl_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			stash = NULL;
		}
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*nl_pos;
	size_t	line_len;

	nl_pos = gnl_strchr(stash, '\n');
	if (nl_pos)
		line_len = (nl_pos - stash) + 1;
	else
		line_len = gnl_strlen(stash);
	return (gnl_substr(stash, 0, line_len));
}

static char	*update_stash(char *stash)
{
	char	*nl_pos;
	char	*rest;

	nl_pos = gnl_strchr(stash, '\n');
	if (!nl_pos || nl_pos[1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	rest = gnl_substr(stash, (nl_pos - stash) + 1, gnl_strlen(nl_pos + 1));
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647 - 1)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
