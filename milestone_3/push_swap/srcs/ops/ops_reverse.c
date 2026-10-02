/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:51 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/02 18:38:21 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  last at the beginning.
static void	op_print(t_ps *ps, char op)
{
	if (op == 'a' && ++ps->count[RRA] && ++ps->count[TOTAL_OPS])
		write(1, "rra\n", 4);
	if (op == 'b' && ++ps->count[RRB] && ++ps->count[TOTAL_OPS])
		write(1, "rrb\n", 4);
	if (op == 'r' && ++ps->count[RRR] && ++ps->count[TOTAL_OPS])
		write(1, "rrr\n", 4);
}

static void	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	op_reverse(t_ps *ps, char op)
{
	if (op == 'a' || op == 'r')
		reverse_rotate(&ps->a);
	if (op == 'b' || op == 'r')
		reverse_rotate(&ps->b);
	op_print(ps, op);
}
