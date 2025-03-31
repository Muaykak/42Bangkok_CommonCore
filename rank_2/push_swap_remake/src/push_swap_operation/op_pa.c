/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:16:49 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 00:16:59 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_pa_sub1(t_ps_node *temp, t_ps_stack *stack_a)
{
	temp->stack = stack_a;
	if (stack_a->size == 0)
	{
		temp->next = temp;
		temp->prev = temp;
		stack_a->top = temp;
		stack_a->bot = temp;
	}
	else
	{
		temp->next = stack_a->top;
		temp->prev = stack_a->bot;
		stack_a->top->prev = temp;
		stack_a->bot->next = temp;
		stack_a->top = temp;
	}
}

void	op_pa(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*temp;

	if (stack_a == NULL || stack_b == NULL || stack_b->size < 1)
		return ;
	temp = stack_b->top;
	if (stack_b->size == 1)
	{
		stack_b->size = 0;
		stack_b->bot = NULL;
		stack_b->top = NULL;
	}
	else
	{
		stack_b->top = stack_b->top->next;
		stack_b->top->prev = stack_b->bot;
		stack_b->bot->next = stack_b->top;
		stack_b->size--;
	}
	op_pa_sub1(temp, stack_a);
	stack_a->size++;
	if (PS_PRINT_OP == 1)
		ft_printf("pa\n");
	return ;
}
