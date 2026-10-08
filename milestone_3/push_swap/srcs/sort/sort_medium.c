/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:33:42 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/08 21:00:13 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	return (r);
}

static int	max_pos(t_node *stack)
{
	int	pos;
	int	best_pos;
	int	max;

	pos = 0;
	best_pos = 0;
	max = stack->rank;
	while (stack)
	{
		if (stack->rank > max)
		{
			max = stack->rank;
			best_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best_pos);
}

static void	push_chunks(t_ps *ps, int chunk)
{
	int	pushed;

	pushed = 0;
	while (ps->a)
	{
		if (ps->a->rank <= pushed)
		{
			op_push(ps, 'b');
			if (ps->b->next)
				op_rotate(ps, 'b');
			pushed++;
		}
		else if (ps->a->rank <= pushed + chunk)
		{
			op_push(ps, 'b');
			pushed++;
		}
		else
			op_rotate(ps, 'a');
	}
}

static void	pull_back(t_ps *ps, int size_b)
{
	int	pos;

	while (size_b > 0)
	{
		pos = max_pos(ps->b);
		if (pos <= size_b / 2)
		{
			while (pos-- > 0)
				op_rotate(ps, 'b');
		}
		else
		{
			while (pos++ < size_b)
				op_reverse(ps, 'b');
		}
		op_push(ps, 'a');
		size_b--;
	}
}

void	sort_medium(t_ps *ps)
{
	int	size;
	int	chunk;

	size = stack_size(ps->a);
	chunk = int_sqrt(size) * 1.4;
	push_chunks(ps, chunk);
	pull_back(ps, size);
}
