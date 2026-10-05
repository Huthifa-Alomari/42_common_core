/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:05:50 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/05 16:41:22 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_print(t_ps *ps, char op)
{
	if (op == 'a')
	{
		ps->count[PA]++;
		write(1, "pa\n", 3);
	}
	else if (op == 'b')
	{
		ps->count[PB]++;
		write(1, "pb\n", 3);
	}
}

static void	push(t_node **from_stack, t_node **to_stack)
{
	t_node	*tmp;

	tmp = *from_stack;
	*from_stack = (*from_stack)->next;
	tmp->next = *to_stack;
	*to_stack = tmp;
}

/*
code logic:
op = a: prints "pa\n" only if stack_b had >= 1 nods.
op = b: prints "pb\n" only if stack_a had >= 1 nods.
op = random: does not print any thing;
*/

void	op_push(t_ps *ps, char op)
{
	if (op == 'a' && ps->b)
	{
		push(&ps->b, &ps->a);
		op_print(ps, op);
	}
	else if (op == 'b' && ps->a)
	{
		push(&ps->a, &ps->b);
		op_print(ps, op);
	}
}
