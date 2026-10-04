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

static void	add_number(char *str, char **res, t_ps *ps)
{
	int		err;
	long	num;
	t_node	*node;

	if (!is_valid_syntax(str))
	{
		free_split(res);
		error(ps);
	}
	err = 0;
	val = parse_atoi(str, &err);
	if (err || is_duplicate(ps->a, (int)num))
	{
		free_split(res);
		error(ps);
	}
	node = new_node((int)num);
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
		add_number(res[i++], res, ps);
	free_split(res);
}
