/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:28 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 16:40:16 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flags(char *flag, t_ps *ps, int *ok)
{
	flag += 2;
	if (ok == 0)
		error(ps);
	if (!ft_strcmp(flag, "adaptive"))
		ps->strategy = ADAPTIVE;
	else if (!ft_strcmp(flag, "simple"))
		ps->strategy = SIMPLE;
	else if (!ft_strcmp(flag, "medium"))
		ps->strategy = MEDIUM;
	else if (!ft_strcmp(flag, "complex"))
		ps->strategy = COMPLEX;
	else if (!ft_strcmp(flag, "bench"))
		ps->bench = 1;
	else
		error(ps);
	*ok--;
}
