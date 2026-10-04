/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:18 by ayhshala          #+#    #+#             */
/*   Updated: 2026/10/04 22:04:38 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(t_ps *ps, int num, char **arg)
{
	int	i;
	int	allow_flags;

	i = 1;
	allow_flags = 2;
	ps->strategy = ADAPTIVE;
	while (i < num)
	{
		if (arg[i][0] == '-' && arg[i][1] == '-')
			parse_flags(arg[i], ps, &allow_flags);
		else
		{
			allow_flags = 0;
			parse_number(arg[i], ps);
		}
		i++;
	}
	if (!ps->a)
		error(ps);
}
