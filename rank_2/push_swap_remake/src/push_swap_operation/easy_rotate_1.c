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
