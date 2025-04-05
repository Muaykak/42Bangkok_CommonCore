/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_rotate_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:15:23 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 23:15:33 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_both_rotate(t_ps_node *target_a, t_ps_node *target_b)
{
	void	(*op_all)(t_ps_stack *, t_ps_stack *);

	if (target_a == NULL || target_b == NULL)
		return ;
	op_all = both_rotate_decider(target_a, target_b);
	if (op_all == NULL)
		return ;
	if (op_all == &op_rr || op_all == &op_rrr)
	{
		while (target_a != target_a->stack->top
			&& target_b != target_b->stack->top)
				op_all(target_a->stack, target_b->stack);
	}
	while (target_a != target_a->stack->top)
		(rotate_decider(target_a))(target_a->stack, target_b->stack);
	while (target_b != target_b->stack->top)
		(rotate_decider(target_b))(target_a->stack, target_b->stack);
}

/* decide to rotate or reverse the target to the top stack */
void	easy_rotate(t_ps_node *target)
{
	if (target == NULL || target == target->stack->top)
		return ;
	if (dist_cal_reverse(target, target->stack->top)
		< dist_cal_rotate(target, target->stack->top))
	{
		if (target->stack->stack == A)
			while (target != target->stack->top)
				op_rra(target->stack, target->stack->link);
		else
			while (target != target->stack->top)
				op_rrb(target->stack->link, target->stack);
	}
	else
	{
		if (target->stack->stack == A)
			while (target != target->stack->top)
				op_ra(target->stack, target->stack->link);
		else
			while (target != target->stack->top)
				op_rb(target->stack->link, target->stack);
	}
	return ;
}
