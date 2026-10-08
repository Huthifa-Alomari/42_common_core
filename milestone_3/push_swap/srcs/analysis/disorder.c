/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:27:05 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/08 22:57:10 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total_pairs;
	long	size;

	size = stack_size(stack);
	if (size < 2)
		return (0.0);
	mistakes = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	total_pairs = (size * (size - 1)) / 2;
	return (mistakes / total_pairs);
}
