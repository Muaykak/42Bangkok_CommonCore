/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_all_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 00:22:23 by srussame          #+#    #+#             */
/*   Updated: 2025/04/06 00:22:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_all_small(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	push_a_all_large(t_ps_stack *stack_a, t_ps_stack *stack_b);

void	push_a_all(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL && stack_b == NULL)
		return ;
	if (stack_a->all_num_size < 500)
		push_a_all_small(stack_a, stack_b);
	else
		push_a_all_large(stack_a, stack_b);
}

void	push_a_all_large(t_ps_stack *stack_a, t_ps_stack *stack_b)
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

void	push_a_all_small(t_ps_stack *stack_a, t_ps_stack *stack_b)
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