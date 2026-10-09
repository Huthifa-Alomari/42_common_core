/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:40:27 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/08 22:29:53 by hal-omar         ###   ########.fr       */
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
	char		*strategy_chosen;
	int			strategy_set;
	t_strategy	strategy;
	int			count[TOTAL_OPS];
}	t_ps;

void	op_swap(t_ps *ps, char op);
void	op_push(t_ps *ps, char op);
void	op_rotate(t_ps *ps, char op);
void	op_reverse(t_ps *ps, char op);
void	parse_args(t_ps *ps, int num, char **arg);
void	parse_flags(char *flag, t_ps *ps, int *allowd_flags);
void	parse_number(char *arg, t_ps *ps);
int		is_valid_syntax(char *str);
int		is_duplicate(t_node *stack, int val);
long	parse_atol(char *str, int *err);
void	error(t_ps *ps);
t_node	*new_node(int value);
void	stack_add_bottom(t_node **stack, t_node *node);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
double	compute_disorder(t_node *stack);
void	bench_print(t_ps *ps);

void	sort_simple(t_ps *ps);
void	sort_medium(t_ps *ps);
void	initialize_ranks(t_node *stack);
int		is_sorted(t_node *stack);
void	sort_complex(t_ps *ps);
void	sort_adaptive(t_ps *ps);

#endif
