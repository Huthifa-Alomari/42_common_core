/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:06:01 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/26 00:52:43 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
void	append(t_list **list, char *buffer);
char	*get_line(t_list *list);
int		newlenline(t_list *list);
void	ft_strcpy(t_list *list, char *str);
int		found_new_line(t_list *list);
t_list	*find_last_node(t_list *list);
void	polish_list(t_list **list);
void	dealloc(t_list **list, t_list *clean_node, char *buffer);

#endif
