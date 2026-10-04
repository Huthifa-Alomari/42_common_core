/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:28 by ayhshala          #+#    #+#             */
/*   Updated: 2026/10/04 22:04:22 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flags(char *flag, t_ps *ps, int *allowd_flags)
{
	flag += 2;
	if (*allowd_flags == 0)
		error(ps);
	else if (!ft_strncmp(flag, "bench", 6) && !ps->bench)
		ps->bench = 1;
	else if (ps->strategy_chosen)
		error(ps);
	else if (!ft_strncmp(flag, "adaptive", 9) && ++ps->strategy_chosen)
		ps->strategy = ADAPTIVE;
	else if (!ft_strncmp(flag, "simple", 7) && ++ps->strategy_chosen)
		ps->strategy = SIMPLE;
	else if (!ft_strncmp(flag, "medium", 7) && ++ps->strategy_chosen)
		ps->strategy = MEDIUM;
	else if (!ft_strncmp(flag, "complex", 8) && ++ps->strategy_chosen)
		ps->strategy = COMPLEX;
	else
		error(ps);
	(*allowd_flags)--;
}
