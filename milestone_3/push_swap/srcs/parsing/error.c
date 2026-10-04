/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:07 by ayhshala          #+#    #+#             */
/*   Updated: 2026/10/04 22:04:52 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_ps *ps)
{
	if (ps)
	{
		free_stack(&ps->a);
		free_stack(&ps->b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}