/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:33:12 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 00:33:32 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra_sub1(t_ps_stack *stack_a)
{
	t_ps_node	*temp;

	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->bot = temp;
	return ;
}

void	op_ra(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_a->size < 2)
		return ;
	(void)stack_b;
	op_ra_sub1(stack_a);
	assign_stack_pos(stack_a);
	if (PS_PRINT_OP == 1)
		ft_printf("ra\n");
}
