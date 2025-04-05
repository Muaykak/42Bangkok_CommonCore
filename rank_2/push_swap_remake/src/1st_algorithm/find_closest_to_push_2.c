/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_to_push_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:26 by srussame          #+#    #+#             */
/*   Updated: 2025/04/04 14:08:38 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get the target_a to push b from find_closest_to_push_b */
t_ps_node	*find_to_top_b(t_ps_node *target_a)
{
	t_ps_node	*stack_max;
	t_ps_node	*sort_pos;

	if (target_a == NULL || target_a->stack->stack != A
		|| target_a->stack->link->size <= 0)
		return (NULL);
	stack_max = target_a->stack->link->stack_max;
	if (target_a->sort_pos < stack_max->stack->stack_min->sort_pos)
		return (stack_max);
	if (target_a->sort_pos > stack_max->sort_pos)
		return (stack_max);
	sort_pos = target_a->target_prev;
	while (1)
	{
		if (stack_max->sort_pos < target_a->sort_pos)
			return (stack_max);
		if (sort_pos->stack->stack == B)
			return (sort_pos);
		stack_max = stack_max->st_prev;
		if (sort_pos->sort_pos < stack_max->sort_pos)
			break ;
		sort_pos = sort_pos->target_prev;
	}
	return (NULL);
}
