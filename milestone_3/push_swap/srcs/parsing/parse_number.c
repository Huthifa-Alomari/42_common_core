/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:25 by hal-omar          #+#    #+#             */
/*   Updated: 2026/10/03 16:23:39 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_number(char *arg, int *ok)
{
	// split ==> is_digit ==> atoi ==> add front
	char	**res;

	res = ft_split(arg,' ');
	while (res[i])
	{
		ft_atoi(res[i++]);
	}
}
