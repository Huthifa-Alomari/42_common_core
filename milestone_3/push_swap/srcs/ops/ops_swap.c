/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:36:39 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/30 18:33:16 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **a, t_list **b, char op)
{
	if (op == 'a' && (a && *a && (*a)->next))
	{
		// TODO
		write(1, "sa\n", 3);
	}
	else if (op == 'b' && (b && *b && (*b)->next))
	{
		// TODO
		write(1, "sb\n", 3);
	}
	else if (op == 's' && ((a && *a && (*a)->next) || (b && *b && (*b)->next)))
	{
		ft_swap(a, NULL, 'a');
		ft_swap(NULL, b, 'b');
		write(1, "ss\n", 3);
	}
}

// ft_swap(&stack_a, NULL, 'a');
// ft_swap(NULL, &stack_b, 'b');
// ft_swap(&stack_a, &stack_b, 's');