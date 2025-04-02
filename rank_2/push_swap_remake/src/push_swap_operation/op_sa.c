/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:00:25 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 20:00:26 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa_sub1(t_ps_stack *stack_a)
{
	t_ps_node	*temp;
	t_ps_node	*second;

	if (stack_a->size == 2)
	{
		temp = stack_a->top;
		stack_a->top = stack_a->bot;
		stack_a->bot = temp;
		return ;
	}
	second = stack_a->top->next;
	temp = second->next;
	second->next = stack_a->top;
	second->prev = stack_a->bot;
	stack_a->top->next = temp;
	stack_a->top->prev = second;
	temp->prev = stack_a->top;
	stack_a->top = second;
	stack_a->bot->next = second;
	return ;
}

void	op_sa(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_a->size < 2)
		return ;
	(void)stack_b;
	op_sa_sub1(stack_a);
	stack_a->top->stack_pos = 1;
	stack_a->top->next->stack_pos = 2;
	if (PS_PRINT_OP == 1)
		ft_printf("sa\n");
	return ;
}
