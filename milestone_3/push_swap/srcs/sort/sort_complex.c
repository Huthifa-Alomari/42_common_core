/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:33:18 by ayhshala          #+#    #+#             */
/*   Updated: 2026/10/08 15:44:44 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_val;

	max_bits = 0;
	max_val = size - 1;
	while ((max_val >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_ps *ps)
{
	int	bit;
	int	max_bits;
	int	size;
	int	i;

	size = stack_size(ps->a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((ps->a->rank >> bit) & 1) == 0)
				op_push(ps, 'b');
			else
				op_rotate(ps, 'a');
			i++;
		}
		while (ps->b)
			op_push(ps, 'a');
		bit++;
	}
}