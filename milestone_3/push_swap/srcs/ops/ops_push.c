/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:05:50 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 21:32:38 by hal-omar         ###   ########.fr       */
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

void	op_push(t_ps *ps, char op)
{
	t_node	*tmp;

	if (op == 'a' && ps->b)
	{
		tmp = ps->b;
		ps->b = ps->b->next;
		tmp->next = ps->a;
		ps->a = tmp;
		op_print(ps, op);
	}
	else if (op == 'b' && ps->a)
	{
		tmp = ps->a;
		ps->a = ps->a->next;
		tmp->next = ps->b;
		ps->b = tmp;
		op_print(ps, op);
	}
}
