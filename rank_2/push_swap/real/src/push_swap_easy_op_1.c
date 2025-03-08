/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_easy_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:44:20 by srussame          #+#    #+#             */
/*   Updated: 2025/01/19 11:44:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_easy_op.h"

void		easy_rotate_all(t_list **stack_a, t_list **stack_b,
				t_list *target_a, t_list *target_b);

static void	easy_rotate_all_sub1(t_list **stack_a, t_list **stack_b,
				t_list *target_a, t_list *target_b);
static void	easy_rotate_all_sub2(t_list **stack_a, t_list **stack_b,
				t_list *target_a, t_list *target_b);
static void	easy_rotate_all_sub3(t_list **stack_a, t_list **stack_b,
				t_list *target_a, t_list *target_b);

static void	easy_rotate_all_sub1(t_list **stack_a, t_list **stack_b,
		t_list *target_a, t_list *target_b)
{
	while (*stack_a != target_a && *stack_b != target_b)
		op_rotate_all(stack_a, stack_b, 1);
	while (*stack_a != target_a && *stack_b == target_b)
		op_rotate_a(stack_a, stack_b, 1);
	while (*stack_a == target_a && *stack_b != target_b)
		op_rotate_b(stack_a, stack_b, 1);
}

static void	easy_rotate_all_sub2(t_list **stack_a, t_list **stack_b,
		t_list *target_a, t_list *target_b)
{
	while (*stack_a != target_a && *stack_b != target_b)
		op_reverse_all(stack_a, stack_b, 1);
	while (*stack_a != target_a && *stack_b == target_b)
		op_reverse_a(stack_a, stack_b, 1);
	while (*stack_a == target_a && *stack_b != target_b)
		op_reverse_b(stack_a, stack_b, 1);
}

/* rotate both of the stack to given position*/
static void	easy_rotate_all_sub3(t_list **stack_a, t_list **stack_b,
			t_list *target_a, t_list *target_b)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b)
		|| !target_a || !target_b)
		return ;
	while (*stack_a != target_a)
		decide_rotate_a(*stack_a, target_a)(stack_a, stack_b, 1);
	while (*stack_b != target_b)
		decide_rotate_b(*stack_b, target_b)(stack_a, stack_b, 1);
	return ;
}

void	easy_rotate_all(t_list **stack_a, t_list **stack_b,
		t_list *target_a, t_list *target_b)
{
	int	result[3];

	if (!stack_a || !stack_b || !target_a || !target_b)
		return ;
	result[0] = trav_top(*stack_a, target_a);
	if (trav_top(*stack_b, target_b) > result[0])
		result[0] = trav_top(*stack_b, target_b);
	result[1] = trav_bot(*stack_a, target_a);
	if (trav_bot(*stack_b, target_b) > result[1])
		result[1] = trav_bot(*stack_b, target_b);
	result[2] = travese_dist(*stack_a, target_a)
		+ travese_dist(*stack_b, target_b);
	if (result[0] < result[1] && result[0] < result[2])
	{
		easy_rotate_all_sub1(stack_a, stack_b, target_a, target_b);
		return ;
	}
	if (result[1] < result[0] && result[1] < result[2])
	{
		easy_rotate_all_sub2(stack_a, stack_b, target_a, target_b);
		return ;
	}
	easy_rotate_all_sub3(stack_a, stack_b, target_a, target_b);
}
