/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:34:08 by ayhshala          #+#    #+#             */
/*   Updated: 2026/10/04 22:05:55 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->rank = 0;
	return (node);
}

void	stack_add_bottom(t_node **stack, t_node *node)
{
	t_node	*tmp;

	if (!stack || !node)
		return ;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/*
Normalizes every node's value to its sorted rank (0 to size - 1)
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
*/