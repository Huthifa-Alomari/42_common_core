/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:40:27 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 21:40:20 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	TOTAL_OPS
}	t_op;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_ps
{
	t_node		*a;
	t_node		*b;
	int			bench;
	double		disorder;
	t_strategy	used;
	t_strategy	strategy;
	int			count[TOTAL_OPS];
}	t_ps;

void	op_swap(t_ps *ps, char op);
void	op_push(t_ps *ps, char op);
void	op_rotate(t_ps *ps, char op);
void	op_reverse(t_ps *ps, char op);
void	parse_args(t_ps *ps, int argc, char **argv);
void	parse_flags(t_ps *ps, char *flag);
int		parse_number(char *str, int *value);
int		is_duplicate(t_node *stack, int value);
int		add_back(t_node **stack, int value);
void	free_stack(t_node **stack);
void	error_exit(t_ps *ps, char **words);
void	free_split(char **words);
int		stack_size(t_node *stack);
double	compute_disorder(t_node *stack);
void	bench_print(t_ps *ps);

#endif
