/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 00:33:24 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/26 01:26:54 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
	cd tests && cc -Wall -Wextra -Werror ../get_next_line*.c main.c
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
*/

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%d ->%s", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}
