/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:18 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/02 22:06:26 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_ps ps, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		// "1 2 3 4 5" ???
		// 
		if (argv[i][0] == '-' && argv[i][1] == '-')
			parse_flags(&argv[i]);
		else if (argv[i] == ft_isdigit(argv[i]))
			parse_number(&argv[i]);
		else if (argv[i] == ft_isalpha(argv[i]))
			error(argv[i]);
		// 
		i++;
	}
}
