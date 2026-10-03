/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:55 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 16:46:40 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// first at the end.
static void	op_print(t_ps *ps, char op)
{
	if (op == 'a' && ++ps->count[RA] && ++ps->count[TOTAL_OPS])
		write(1, "ra\n", 3);
	if (op == 'b' && ++ps->count[RB] && ++ps->count[TOTAL_OPS])
		write(1, "rb\n", 3);
	if (op == 'r' && ++ps->count[RR] && ++ps->count[TOTAL_OPS])
		write(1, "rr\n", 3);
}

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	op_rotate(t_ps *ps, char op)
{
	if (op == 'a' || op == 'r')
		rotate(&ps->a);
	if (op == 'b' || op == 'r')
		rotate(&ps->b);
	if (!ps->a || !ps->a->next || !ps->b || !ps->b->next)
		op_print(ps, op);	
}
