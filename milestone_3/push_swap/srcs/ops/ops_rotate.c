/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:55 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/02 01:56:00 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_ps *ps, char op)
{
	/*
	t_node	**s;
	t_node	*last;
	int		r;

	r = 0;
	s = &ps->a;
	while (r++ < 2)
	{
		if ((op == 'r' || op == 'a' + r - 1) && *s && (*s)->next)
		{
			last = *s;
			while (last->next)
				last = last->next;
			last->next = *s;
			*s = (*s)->next;
			last->next->next = NULL;
			if (op == 'a' && ++ps->count[RA] && ++ps->count[TOTAL_OPS])
				write(1, "ra\n", 3);
			if (op == 'b' && ++ps->count[RB] && ++ps->count[TOTAL_OPS])
				write(1, "rb\n", 3);
		}
		s = &ps->b;
	}
	if (op == 'r' && (ps->a || ps->b) && ++ps->count[RR] && ++ps->count[TOTAL_OPS])
		write(1, "rr\n", 3);
	*/
}
