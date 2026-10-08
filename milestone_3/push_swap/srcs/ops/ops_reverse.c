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

/*
code logic:
op = a: prints "rra\n" only if stack_a was reverse rotated.
op = b: prints "rrb\n" only if stack_b was reverse rotated.
op = r: prints "rrr\n" only if both stacks had >= 2 nodes.
op = r: does not prints "rra\n" because stack_b < 2 node.
op = r: does not prints "rrb\n" because stack_a < 2 node.
op = random: does not print any thing;

if:
{
	op = r
	ps->a = 1 2 3 4
	ps->b = NULL
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
------------------
code logic:
op = a: prints "rra\n" only if stack_a was reverse rotated.
op = b: prints "rrb\n" only if stack_b was reverse rotated.
op = r: prints "rrr\n" only if both stacks had >= 2 nodes.
op = r: prints "rra\n" only if stack_a was reverse rotated.
op = r: prints "rrb\n" only if stack_b was reverse rotated.
op = random: does not print any thing.

if:
{
	op = r
	ps->a = 1 2 3 4
	ps->b = NULL
}
it will reverse rotate stack_a and only prints "rra\n".
*/

void	op_reverse(t_ps *ps, char op)
{
	int	rr;

	rr = 0;
	if (!ps)
		return ;
	if ((op == 'a' || op == 'r') && ps->a && ps->a->next)
	{
		reverse(&ps->a);
		rr += 1;
	}
	if ((op == 'b' || op == 'r') && ps->b && ps->b->next)
	{
		reverse(&ps->b);
		rr += 2;
	}
	if (rr == 1)
		op_print(ps, 'a');
	else if (rr == 2)
		op_print(ps, 'b');
	else if (rr == 3)
		op_print(ps, 'r');
}
