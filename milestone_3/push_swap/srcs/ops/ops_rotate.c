/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:55 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/06 13:49:51 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[RA]++;
		write(1, "ra\n", 3);
	}
	else if (op == 'b')
	{
		ps->count[RB]++;
		write(1, "rb\n", 3);
	}
	else if (op == 'r')
	{
		ps->count[RR]++;
		write(1, "rr\n", 3);
	}
}

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

/*
code logic:
op = a: prints "ra\n" only if stack_a was rotated.
op = b: prints "rb\n" only if stack_b was rotated.
op = r: prints "rr\n" only if both stacks had >= 2 nodes.
op = r: does not prints "ra\n" because stack_b < 2 node.
op = r: does not prints "rb\n" because stack_a < 2 node.
op = random: does not print any thing.

if:
{
	op = r
	ps->a = 1 2 3 4
	ps->b = NULL
}
it will not rotate stack_a and will not print any thing because stack_b < 2 node.

void	op_rotate(t_ps *ps, char op)
{
	if (!ps)
		return ;
	if (op == 'a' && ps->a && ps->a->next)
	{
		rotate(&ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->b && ps->b->next)
	{
		rotate(&ps->b);
		op_print(ps, op);
	}
	else if (op == 'r' && ps->a && ps->a->next && ps->b && ps->b->next)
	{
		rotate(&ps->a);
		rotate(&ps->b);
		op_print(ps, op);
	}
}
------------------
code logic:
op = a: prints "ra\n" only if stack_a was rotated.
op = b: prints "rb\n" only if stack_b was rotated.
op = r: prints "rr\n" only if both stacks had >= 2 nodes.
op = r: prints "ra\n" only if stack_a was rotated.
op = r: prints "rb\n" only if stack_b was rotated.
op = random: does not print any thing.

if:
{
	op = r
	ps->a = 1 2 3 4
	ps->b = NULL
}
it will rotate stack_a and only prints "ra\n".
*/

void	op_rotate(t_ps *ps, char op)
{
	int	r;

	r = 0;
	if (!ps)
		return ;
	if ((op == 'a' || op == 'r') && ps->a && ps->a->next)
	{
		rotate(&ps->a);
		r += 1;
	}
	if ((op == 'b' || op == 'r') && ps->b && ps->b->next)
	{
		rotate(&ps->b);
		r += 2;
	}
	if (r == 1)
		op_print(ps, 'a');
	else if (r == 2)
		op_print(ps, 'b');
	else if (r == 3)
		op_print(ps, 'r');
}
