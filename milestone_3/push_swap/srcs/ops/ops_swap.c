/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:36:39 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/05 16:41:21 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[SA]++;
		write(1, "sa\n", 3);
	}
	else if (op == 'b')
	{
		ps->count[SB]++;
		write(1, "sb\n", 3);
	}
	else if (op == 's')
	{
		ps->count[SS]++;
		write(1, "ss\n", 3);
	}
}

static void	swap(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

/*
code logic:
op = a: prints "sa\n" only if stack_a was swapped.
op = b: prints "sb\n" only if stack_b was swapped.
op = s: prints "ss\n" only if both stacks had >= 2 nodes.
op = s: does not prints "sa\n" because stack_b < 2 node.
op = s: does not prints "sb\n" because stack_a < 2 node.
op = random: does not print any thing.

if:
{
	op = s
	ps->a = 1 2 3 4
	ps->b = NULL
}
it will not swap stack_a and will not print any thing because stack_b < 2 node.
*/

void	op_swap(t_ps *ps, char op)
{
	if (!ps)
		return ;
	if (op == 'a' && ps->a && ps->a->next)
	{
		swap(&ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->b && ps->b->next)
	{
		swap(&ps->b);
		op_print(ps, op);
	}
	else if (op == 's' && ps->a && ps->a->next && ps->b && ps->b->next)
	{
		swap(&ps->a);
		swap(&ps->b);
		op_print(ps, op);
	}
}

/*
code logic:
op = a: prints "sa\n" only if stack_a was swapped.
op = b: prints "sb\n" only if stack_b was swapped.
op = s: prints "ss\n" only if both stacks had >= 2 nodes.
op = s: prints "sa\n" only if stack_a was swapped.
op = s: prints "sb\n" only if stack_b was swapped.
op = random: does not print any thing.

if:
{
	op = s
	ps->a = 1 2 3 4
	ps->b = NULL
}
it will swap stack_a and only prints "sa\n".
*/

void	op_swap(t_ps *ps, char op)
{
	int	s;

	s = 0;
	if (!ps)
		return ;
	if ((op == 'a' || op == 's') && ps->a && ps->a->next)
	{
		swap(&ps->a);
		s += 1;
	}
	if ((op == 'b' || op == 's') && ps->b && ps->b->next)
	{
		swap(&ps->b);
		s += 2;
	}
	if (s == 1)
		op_print(ps, 'a');
	else if (s == 2)
		op_print(ps, 'b');
	else if (s == 3)
		op_print(ps, 's');
}
