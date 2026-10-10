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
