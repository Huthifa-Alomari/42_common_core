/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:05:12 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/07 19:05:52 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Normalizes every node's value to its sorted rank (0 to size - 1)
void	normalize_ranks(t_node *stack)
{
	t_node	*curr;
	t_node	*compare;
	int		count;

	curr = stack;
	while (curr)
	{
		count = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < curr->value)
				count++;
			compare = compare->next;
		}
		curr->rank = count;
		curr = curr->next;
	}
}
