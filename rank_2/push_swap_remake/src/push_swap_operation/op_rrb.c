/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:43:33 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 00:43:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrb_sub1(t_ps_stack *stack_b)
{
	t_ps_node	*temp;

	temp = stack_b->bot;
	stack_b->bot = stack_b->bot->prev;
	stack_b->top = temp;
}

void	op_rrb(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_b->size < 2)
		return ;
	(void)stack_a;
	op_rrb_sub1(stack_b);
	assign_stack_pos(stack_b);
	if (PS_PRINT_OP == 1)
		ft_printf("rrb\n");
}
