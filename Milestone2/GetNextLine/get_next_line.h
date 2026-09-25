/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:06:01 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/25 22:47:11 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFFER_SIZE  42

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	char		*buffer;
	struct	s_list	*next;
}				t_list;

char    *get_next_line(int fd);
char	create_list(t_list **list, int fd);
void	append(t_list **list, char *buffer);
char	*get_line(t_list *list);
int	newlenline(t_list *list);


#endif
