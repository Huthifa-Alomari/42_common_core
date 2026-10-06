/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:16:21 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/06 13:49:54 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_ops(t_ps *ps)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < TOTAL_OPS)
	{
		total += ps->count[i];
		i++;
	}
	return (total);
}

static char	*strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

void	bench_print(t_ps *ps)
{
	ft_dprintf(2, "[bench] disorder: %f%%\n", ps->disorder * 100);
	ft_dprintf(2, "[bench] strategy: %s / %s\n",
		strategy_name(ps->strategy), ps->strategy_chosen);
	ft_dprintf(2, "[bench] total_ops: %d\n", total_ops(ps));
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ps->count[SA], ps->count[SB], ps->count[SS],
		ps->count[PA], ps->count[PB]);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ps->count[RA], ps->count[RB], ps->count[RR],
		ps->count[RRA], ps->count[RRB], ps->count[RRR]);
}
