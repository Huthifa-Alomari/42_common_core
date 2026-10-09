/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:07:23 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/08 23:28:54 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	parse_args(&ps, argc, argv);
	initialize_ranks(ps.a);
	ps.disorder = compute_disorder(ps.a);
	sort_adaptive(&ps);
	if (ps.bench)
		bench_print(&ps);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}

/*

- strategy.c: add run_strategy; a flag forces its sort, otherwise
  adaptive picks by disorder (< 0.2 simple, < 0.5 medium, else
  complex); sets strategy_chosen for bench before the sorted check

- sort_medium.c: chunk sort O(n√n), window = sqrt(n) * 1.4

- ranks.c: normalize_ranks moved here and enabled

- stack_utils.c: add is_sorted

- main.c: ranks -> disorder (before any move) -> run_strategy -> bench

- push_swap.h: add strategy_set to t_ps; add prototypes for
  sort_medium, sort_complex, run_strategy, normalize_ranks, is_sorted

- parse_flags.c: use strategy_set (int) instead of strategy_chosen;
  fixes crash with --bench + strategy flag

- ft_putdouble.c: round to 2 decimals (49.93% no longer prints 49.92%)

- Makefile: remove deleted files

- norminette fixes
*/
