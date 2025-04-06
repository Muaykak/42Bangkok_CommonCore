/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_decider_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:00:28 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 17:00:36 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op_funct	rotate_a_decider(t_ps_node *target)
{
	int	rotate_dist;
	int	reverse_dist;

	rotate_dist = dist_cal_rotate(target, target->stack->top);
	reverse_dist = target->stack->size - rotate_dist;
	if (reverse_dist < rotate_dist)
		return (&op_rra);
	else
		return (&op_ra);
}

static t_op_funct	rotate_b_decider(t_ps_node *target)
{
	int	rotate_dist;
	int	reverse_dist;

	rotate_dist = dist_cal_rotate(target, target->stack->top);
	reverse_dist = target->stack->size - rotate_dist;
	if (reverse_dist < rotate_dist)
		return (&op_rrb);
	else
		return (&op_rb);
}

t_op_funct	rotate_decider(t_ps_node *target)
{
	if (target == NULL || target->stack->top == target)
		return (NULL);
	if (target->stack->stack == A)
		return (rotate_a_decider(target));
	else
		return (rotate_b_decider(target));
}

t_op_funct	both_rotate_decider(t_ps_node *target_a, t_ps_node *target_b)
{
	int	rotate_dist;
	int	reverse_dist;
	int	temp;

	if ((target_a == NULL && target_b == NULL) || (target_a->stack->size < 2
			&& target_b->stack->size < 2))
		return (NULL);
	if (target_a == target_a->stack->top && target_b != NULL)
		return (rotate_decider(target_b));
	if (target_a != NULL && target_b == target_b->stack->top)
		return (rotate_decider(target_a));
	rotate_dist = dist_cal_rotate(target_a, target_a->stack->top);
	temp = dist_cal_rotate(target_b, target_b->stack->top);
	if (temp > rotate_dist)
		rotate_dist = temp;
	reverse_dist = dist_cal_reverse(target_a, target_a->stack->top);
	temp = dist_cal_reverse(target_b, target_b->stack->top);
	if (temp > reverse_dist)
		reverse_dist = temp;
	if (reverse_dist < rotate_dist)
		return (&op_rrr);
	return (&op_rr);
}
