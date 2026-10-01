/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:07:23 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/01 20:53:26 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	add_back(t_node **stack, int value)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->value = value;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
}

static void	print_stacks(t_node *ps, char *label)
{
	t_node	*a = ps->a;
	t_node	*b = ps->b;

	fprintf(stderr, "--- %s ---\n", label);
	while (a || b)
	{
		if (a)
			fprintf(stderr, "%d", a->value);
		fprintf(stderr, "\t");
		if (b)
			fprintf(stderr, "%d", b->value);
		fprintf(stderr, "\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	fprintf(stderr, "-\t-\na\tb\n\n");
}

static void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(void)
{
	t_ps	ps = {0};

	add_back(&ps.a, 3);
	add_back(&ps.a, 1);
	add_back(&ps.a, 2);
	print_stacks(&ps, "start");
	op_swap(&ps, 'a');
	print_stacks(&ps, "after sa");
	op_push(&ps, 'b');
	op_push(&ps, 'b');
	print_stacks(&ps, "after pb pb");
	op_swap(&ps, 'b');
	print_stacks(&ps, "after sb");
	op_rotate(&ps, 'r');
	print_stacks(&ps, "after rr");
	op_push(&ps, 'a');
	op_push(&ps, 'a');
	op_push(&ps, 'a');
	print_stacks(&ps, "after pa x3 (one extra, b empty)");
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}