/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-omar <hal-omar@student.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:39:27 by hal-omar          #+#    #+#             */
/*   Updated: 2026/09/30 17:31:52 by hal-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	*head)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = head;
	tmp2 = head;
	while (tmp1)
		tmp1 = tmp1->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp1->next = tmp2->next;
	
}
