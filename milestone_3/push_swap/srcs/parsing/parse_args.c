/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:18 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 16:28:54 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_ps *ps, int num, char **arg)
{
	int	i;
	int	ok;

	i = 1;
	ok = 2;
	ps->strategy = ADAPTIVE;
	while (i < num)
	{
		if (arg[i][0] == '-' && arg[i][1] == '-')
			parse_flags(arg[i], ps, &ok);
		else
		{
			ok = 0;
			parse_number(&arg[i]);
		}
		i++;
	}
}
