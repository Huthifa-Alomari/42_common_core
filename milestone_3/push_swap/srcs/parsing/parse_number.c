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


#include "push_swap.h"

/* Helper to free the array returned by ft_split */
void	free_split(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

static void	process_token(char *token, char **res, t_ps *ps)
{
	int		err;
	long	val;
	t_node	*node;

	err = 0;
	if (!is_valid_syntax(token))
	{
		free_split(res);
		error(ps);
	}
	val = parse_atol(token, &err);
	if (err || is_duplicate(ps->a, (int)val))
	{
		free_split(res);
		error(ps);
	}
	node = new_node((int)val);
	if (!node)
	{
		free_split(res);
		error(ps);
	}
	stack_add_bottom(&ps->a, node);
}

void	parse_number(char *arg, t_ps *ps)
{
	char	**res;
	int		i;

	res = ft_split(arg, ' ');
	if (!res || !res[0])
	{
		free_split(res);
		error(ps);
	}
	i = 0;
	while (res[i])
	{
		process_token(res[i], res, ps);
		i++;
	}
	free_split(res);
}
