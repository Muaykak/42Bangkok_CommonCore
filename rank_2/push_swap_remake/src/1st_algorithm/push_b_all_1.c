/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_all_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:36:47 by srussame          #+#    #+#             */
/*   Updated: 2025/04/05 22:36:57 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_all(t_ps_stack *stack_a, t_ps_stack *stack_b);

static void	push_b_all_medium(t_ps_stack *stack_a, t_ps_stack *stack_b);
static void	push_b_all_small_size(t_ps_stack *stack_a, t_ps_stack *stack_b);
void	push_b_all_large_size(t_ps_stack *stack_a, t_ps_stack *stack_b);

void	push_b_all(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (stack_a->all_num_size < 100)
		push_b_all_small_size(stack_a, stack_b);
	else if (stack_a->all_num_size >= 100 && stack_a->all_num_size < 500)
		push_b_all_medium(stack_a, stack_b);
	else
		push_b_all_large_size(stack_a, stack_b);
}

static void	push_b_all_medium(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*swap;

	while (stack_a->size > 3)
		op_pb(stack_a, stack_b);
	swap = find_closest_to_swap(stack_a);
	if (swap == NULL)
		return ;
	easy_rotate(swap);
	op_sa(stack_a, stack_b);
}

static void push_b_all_large_size_sub1(t_ps_stack *stack_a,t_ps_stack *stack_b)
{
	t_ps_node	*swap;
	swap = find_closest_to_swap(stack_a);
	if (swap == NULL)
		return ;
	easy_rotate(swap);
	op_sa(stack_a, stack_b);

}

void	push_b_all_large_size(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*target_a;
	void		(*op_a)(t_ps_stack *, t_ps_stack *);
	void		(*op_b)(t_ps_stack *, t_ps_stack *);

	target_a = find_to_push_b_inrange(stack_a);
	while (target_a != NULL)
	{
		op_a = rotate_decider(target_a);
		op_b = decide_b_in_range(stack_a, stack_b);
		if (op_b == &op_rb && op_a == &op_ra)
			op_rr(stack_a, stack_b);
		else if (op_b == &op_rb && op_a != &op_ra)
			op_rb(stack_a, stack_b);
		if (op_a != NULL)
			op_a(stack_a, stack_b);
		else
			{
				op_pb(stack_a, stack_b);
				target_a = find_to_push_b_inrange(stack_a);
			}
	}
	push_b_all_large_size_sub1(stack_a, stack_b);
}

static void	push_b_all_small_size(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*to_push_b;
	t_ps_node	*swap;

	if (stack_a == NULL || stack_b == NULL)
		return ;
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
