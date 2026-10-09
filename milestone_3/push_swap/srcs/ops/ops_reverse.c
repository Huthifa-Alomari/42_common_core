/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:51 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/08 23:19:43 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[RRA]++;
		write(1, "rra\n", 4);
	}
	else if (op == 'b')
	{
		ps->count[RRB]++;
		write(1, "rrb\n", 4);
	}
	else if (op == 'r')
	{
		ps->count[RRR]++;
		write(1, "rrr\n", 4);
	}
}

static void	reverse(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

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
	if (!ps)
		return ;
	if (op == 'a' && ps->a && ps->a->next)
	{
		reverse(&ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->b && ps->b->next)
	{
		reverse(&ps->b);
		op_print(ps, op);
	}
	else if (op == 'r' && ps->a && ps->a->next && ps->b && ps->b->next)
	{
		reverse(&ps->a);
		reverse(&ps->b);
		op_print(ps, op);
	}
}
