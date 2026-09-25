/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:06:06 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/26 01:01:26 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_new_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buffer;
	int		i;
	int		k;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buffer || !clean_node)
	{
		free(buffer);
		free(clean_node);
		return ;
	}
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buffer[k++] = last_node->buffer[i];
	buffer[k] = '\0';
	clean_node->buffer = buffer;
	clean_node->next = NULL;
	dealloc(list, clean_node, buffer);
}

int	newlenline(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			len++;
			if (list->buffer[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_strcpy(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->buffer[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}
