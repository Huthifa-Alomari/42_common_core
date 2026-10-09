/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:33:57 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/08 23:25:39 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	pick_sort(t_ps *ps)
{
	if (ps->strategy != ADAPTIVE)
		return (ps->strategy);
	if (ps->disorder < 0.2)
		return (SIMPLE);
	if (ps->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_adaptive(t_ps *ps)
{
	t_strategy	sort;

	sort = pick_sort(ps);
	if (sort == SIMPLE)
		ps->strategy_chosen = "O(n²)";
	else if (sort == MEDIUM)
		ps->strategy_chosen = "O(n√n)";
	else
		ps->strategy_chosen = "O(n log n)";
	if (is_sorted(ps->a))
		return ;
	if (sort == SIMPLE)
		sort_simple(ps);
	else if (sort == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}
