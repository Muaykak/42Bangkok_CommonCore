/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:09:38 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 21:09:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sb_sub1(t_ps_stack *stack_b)
{
	t_ps_node	*temp;
	t_ps_node	*second;

	if (stack_b->size == 2)
	{
		temp = stack_b->top;
		stack_b->top = stack_b->bot;
		stack_b->bot = temp;
		return ;
	}
	second = stack_b->top->next;
	temp = second->next;
	second->next = stack_b->top;
	second->prev = stack_b->bot;
	stack_b->top->next = temp;
	stack_b->top->prev = second;
	temp->prev = stack_b->top;
	stack_b->top = second;
	stack_b->bot->next = second;
	assign_node_unsorted(stack_b->top);
	assign_node_unsorted(stack_b->top->next);
	assign_node_unsorted(stack_b->top->next->next);
	assign_node_unsorted(stack_b->bot);
	stack_b->sorted = check_stack_desc_sorted(stack_b);
	return ;
}

void	op_sb(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL || stack_b->size < 2)
		return ;
	(void)stack_a;
	op_sb_sub1(stack_b);
	stack_b->top->stack_pos = 1;
	stack_b->top->next->stack_pos = 2;
	if (PS_PRINT_OP == 1)
		ft_printf("sb\n");
	return ;
}
