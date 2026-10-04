/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhshala <ayham.shalabi@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:56:10 by ayhshala          #+#    #+#             */
/*   Updated: 2026/10/04 22:03:38 by ayhshala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_node *stack, int val)
{
	while (stack)
	{
		if (stack->value == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long	parse_atol(char *str, int *err)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > 2147483647L) || (sign == -1 && res > 2147483648L))
		{
			*err = 1;
			return (0);
		}
		i++;
	}
	return (res * sign);
}