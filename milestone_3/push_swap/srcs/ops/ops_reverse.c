/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:51 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 19:53:23 by hal-omar         ###   ########.fr       */
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

static int	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return (0);
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
	return (1);
}

void	op_reverse(t_ps *ps, char op)
{
	int	moved;

	moved = 0;
	if (op == 'a' || op == 'r')
		moved += reverse_rotate(&ps->a);
	if (op == 'b' || op == 'r')
		moved += reverse_rotate(&ps->b);
	if (moved)
		op_print(ps, op);
}
