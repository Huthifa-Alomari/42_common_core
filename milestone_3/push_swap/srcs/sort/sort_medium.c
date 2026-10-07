/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 21:33:42 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/07 19:08:21 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	#phase_1
		if top A is in chunk(for each chunk)
			PB
		else 
			RA
	#phase_2
		if max B in half top
			RB
		else 
			RRB
		PA	

#include "push_swap.h"

static void	chunk_sort(t_ps *a, t_ps *b)
{
	int	chunk;

	chunk = int_sqrt(a->size) * 14 / 10;
	push_chunks(a, b, chunk);
	pull_back(a, b);
}
*/