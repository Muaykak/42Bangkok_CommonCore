/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_algor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:19:39 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 15:19:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_all(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	push_a_all(t_ps_stack *stack_a, t_ps_stack *stack_b);

void	first_algor(t_ps_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	if (check_stack_asc_sorted(stack_a) == 1)
	{
		easy_rotate(stack_a->stack_min);
		return ;
	}
	push_b_all(stack_a, stack_a->link);
	push_a_all(stack_a, stack_a->link);
	easy_rotate(stack_a->stack_min);
	return ;
}

void	push_a_all(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*target_in_a;
	t_ps_node	*target_b;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	while (stack_b->size > 0)
	{
		target_b = find_closest_to_push_a(stack_b);
		target_in_a = find_target_in_a(target_b);
		easy_both_rotate(target_in_a, target_b);
		op_pa(stack_a, stack_b);
	}
}

void	push_b_all(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*to_push_b;
	t_ps_node	*swap;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	while (stack_b->all_num_size >= 100 && stack_a->size > 4)
		op_pb(stack_a, stack_b);
	while (1)
	{
		to_push_b = find_closest_to_push_b(stack_a);
		if (to_push_b != NULL)
		{
			easy_rotate(to_push_b);
			op_pb(stack_a, stack_b);
		}
		else
		{
			swap = find_closest_to_swap(stack_a);
			if (swap == NULL)
				break ;
			easy_rotate(swap);
			op_sa(stack_a, stack_b);
		}
	}
}
