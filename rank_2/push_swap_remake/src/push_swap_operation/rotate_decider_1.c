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

static void	(*rotate_a_decider(t_ps_node *target))(t_ps_stack *, t_ps_stack *)
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

static void	(*rotate_b_decider(t_ps_node *target))(t_ps_stack *, t_ps_stack *)
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

void	(*rotate_decider(t_ps_node *target))(t_ps_stack *, t_ps_stack *)
{
	if (target == NULL || target->stack->top == target)
		return (NULL);
	if (target->stack->stack == A)
		return (rotate_a_decider(target));
	else
		return (rotate_b_decider(target));
}