/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:06:55 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 19:52:19 by hal-omar         ###   ########.fr       */
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

static int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	op_rotate(t_ps *ps, char op)
{
	int	moved;

	moved = 0;
	if (op == 'a' || op == 'r')
		moved += rotate(&ps->a);
	if (op == 'b' || op == 'r')
		moved += rotate(&ps->b);
	if (moved)
		op_print(ps, op);
}
