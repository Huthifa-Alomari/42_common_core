/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 19:05:50 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/30 19:55:53 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}
