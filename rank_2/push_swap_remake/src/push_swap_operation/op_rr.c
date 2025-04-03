/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:42:15 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 00:42:25 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rr(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL
		|| stack_a->size < 2 || stack_b->size < 2)
		return ;
	op_ra_sub1(stack_a);
	op_rb_sub1(stack_b);
	assign_stack_pos(stack_b);
	assign_stack_pos(stack_a);
	if (PS_PRINT_OP == 1)
		ft_printf("rr\n");
	return ;
}