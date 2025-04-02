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
		stack_a->stack_min = temp;
		stack_a->stack_max = temp;
	}
	else
	{
		temp->next = stack_a->top;
		temp->prev = stack_a->bot;
		stack_a->top->prev = temp;
		stack_a->bot->next = temp;
		stack_a->top = temp;
		if (stack_a->top->number > stack_a->stack_max->number)
			stack_a->stack_max = stack_a->top;
		else if (stack_a->top->number < stack_a->stack_min->number)
			stack_a->stack_min = stack_a->top;
	}
}

static void	op_pa_sub2(t_ps_stack *stack_b)
{
	if (stack_b->size == 1)
	{
		stack_b->size = 0;
		stack_b->bot = NULL;
		stack_b->top = NULL;
	}
	else
	{
		if (stack_b->top == stack_b->stack_max)
			stack_b->stack_max = find_lower_node(stack_b->stack_max);
		else if (stack_b->bot == stack_b->stack_min)
			stack_b->stack_min = find_higher_node(stack_b->stack_min);
		stack_b->top = stack_b->top->next;
		stack_b->top->prev = stack_b->bot;
		stack_b->bot->next = stack_b->top;
		stack_b->size--;
	}
}

void	op_pa(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*temp;

	if (stack_a == NULL || stack_b == NULL || stack_b->size < 1)
		return ;
	temp = stack_b->top;
	op_pa_sub2(stack_b);
	op_pa_sub1(temp, stack_a);
	stack_a->size++;
	assign_stack_pos(stack_a);
	assign_stack_pos(stack_b);
	if (PS_PRINT_OP == 1)
		ft_printf("pa\n");
	return ;
}
