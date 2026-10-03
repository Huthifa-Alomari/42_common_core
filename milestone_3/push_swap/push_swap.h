/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:40:27 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 18:13:45 by hal-omar         ###   ########.fr       */
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
	t_strategy	strategy;
	int			stra[5];
	int			count[TOTAL_OPS];
}	t_ps;

void	op_swap(t_ps *ps, char op);
void	op_push(t_ps *ps, char op);
void	op_rotate(t_ps *ps, char op);
void	op_reverse(t_ps *ps, char op);

#endif
