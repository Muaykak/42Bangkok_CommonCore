/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:41:44 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 00:42:04 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rb_sub1(t_ps_stack *stack_b)
{
	t_ps_node	*temp;
	
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->bot = temp;
	return ;
}

void op_rb(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_b->size < 2)
		return ;
	(void)stack_a;
	op_ra_sub1(stack_b);
	assign_stack_pos(stack_b);
	stack_b->top->stack_pos = 1;
	stack_b->top->next->stack_pos = 2;
	assign_stack_pos(stack_b);
	if (PS_PRINT_OP == 1)
		ft_printf("rb\n");
}
