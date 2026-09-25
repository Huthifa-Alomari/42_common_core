/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:05:35 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/25 22:47:07 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int	str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);

	str_len	= new_len(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);

	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));

	if (new_node == NULL)
		return ;

	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;

	new_node->str_buffer = buffer;
	new_node->next = NULL;

}

char	create_list(t_list **list, int fd)
{
	int	char_read;
	char	*buffer;

	while (!found_new_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;

		char_read = read(fd, buffer, BUFFER_SIZE);

		if (!char_read)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		append(list, buffer);
	}
}

char    *get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	list = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	return (NULL);

	create_list(&list, fd);

	if (list == NULL)
	return (NULL);

	next_line = get_line(list);

	polist_list(&list);
	return (next_line);
}
