/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:36:39 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 16:25:24 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_print(t_ps *ps, char op)
{
	if (op == 'a' && ++ps->count[SA] && ++ps->count[TOTAL_OPS])
		write(1, "sa\n", 3);
	if (op == 'b' && ++ps->count[SB] && ++ps->count[TOTAL_OPS])
		write(1, "sb\n", 3);
	if (op == 's' && ++ps->count[SS] && ++ps->count[TOTAL_OPS])
		write(1, "ss\n", 3);
}

void	op_swap(t_ps *ps, char op)
{
	t_node	*tmp;
	int		s;

	s = 0;
	if ((op == 'a' || op == 's') && ps->a && ps->a->next && ++s)
	{
		tmp = ps->a->next;
		ps->a->next = tmp->next;
		tmp->next = ps->a;
		ps->a = tmp;
	}
	if ((op == 'b' || op == 's') && ps->b && ps->b->next && ++s)
	{
		tmp = ps->b->next;
		ps->b->next = tmp->next;
		tmp->next = ps->b;
		ps->b = tmp;
	}
	op_print(ps, op);
}
