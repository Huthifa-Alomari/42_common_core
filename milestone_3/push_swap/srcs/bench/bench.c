/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:16:21 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 19:50:29 by hal-omar         ###   ########.fr       */
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

void	bench_print(t_ps *ps)
{
	const char	*strategy[4] = {
		"Adaptive",
		"Simple",
		"Medium",
		"Complex"
	};
	const char	*bigo[4] = {
		"O(n^2)",
		"O(n^2)",
		"O(n√n)",
		"O(nlogn)"
	};

	ft_printf("[bench] disorder: %.2f%%\n", ps->disorder);
	ft_printf("[bench] strategy: %s / %s\n",
		strategy[ps->strategy], bigo[ps->strategy]);
	ft_printf("[bench] total_ops: %d\n", ps->count);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		ps->count[SA], ps->count[SB], ps->count[SS],
		ps->count[PA], ps->count[PB]);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		ps->count[RA], ps->count[RB], ps->count[RR],
		ps->count[RRA], ps->count[RRB], ps->count[RRR]);
}
