/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 00:43:00 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 00:43:12 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra_sub1(t_ps_stack *stack_a)
{
	t_ps_node	*temp;

	temp = stack_a->bot;
	stack_a->bot = stack_a->bot->prev;
	stack_a->top = temp;
}

void	op_rra(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_a->size < 2)
		return ;
	(void)stack_b;
	op_rra_sub1(stack_a);
	assign_stack_pos(stack_a);
	if (PS_PRINT_OP == 1)
		ft_printf("rra\n");
}
