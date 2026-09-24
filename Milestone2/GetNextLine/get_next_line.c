/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:05:35 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/24 21:17:29 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *stash;
    ssize_t bytes_read;
    char           buffer[BUFFER_SIZE + 1];
    
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0)
        return (NULL);
    if (bytes_read == 0)
        return (0);
    buffer[bytes_read] = '\0';
}
