/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:07:23 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 19:44:16 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	parse_args(&ps, argc, argv);
	ps.disorder = compute_disorder(ps.a);
	if (ps.bench)
		bench_print(&ps);
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}

/*
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

static void	print_stacks(t_ps *ps, char *label)
{
	t_node	*a;
	t_node	*b;

	a = ps->a;
	b = ps->b;
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

int	main(int argc, char **argv)
{
	t_ps	ps = {0};
	int		i;

	i = 1;
	while (i < argc)
		add_back(&ps.a, atoi(argv[i++]));
	print_stacks(&ps, "start");
	op_swap(&ps, 'a');
	print_stacks(&ps, "sa");
	op_push(&ps, 'b');
	op_push(&ps, 'b');
	op_push(&ps, 'b');
	print_stacks(&ps, "pb x3");
	op_rotate(&ps, 'r');
	print_stacks(&ps, "rr");
	op_reverse(&ps, 'r');
	print_stacks(&ps, "rrr");
	op_swap(&ps, 'a');
	print_stacks(&ps, "sa");
	op_push(&ps, 'a');
	op_push(&ps, 'a');
	op_push(&ps, 'a');
	print_stacks(&ps, "pa x3");
	free_stack(&ps.a);
	free_stack(&ps.b);
	return (0);
}*/