/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:36:38 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 21:36:58 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_pb_sub1(t_ps_node *temp, t_ps_stack *stack_b)
{
	temp->stack = stack_b;
	if (stack_b->size == 0)
	{
		temp->next = temp;
		temp->prev = temp;
		stack_b->top = temp;
		stack_b->bot = temp;
	}
	else
	{
		temp->next = stack_b->top;
		temp->prev = stack_b->bot;
		stack_b->top->prev = temp;
		stack_b->bot->next = temp;
		stack_b->top = temp;
	}
}

/* Push from stack a to stack b */
void	op_pb(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*temp;

	if (stack_a == NULL || stack_b == NULL || stack_a->size < 1)
		return ;
	temp = stack_a->top;
	if (stack_a->size == 1)
	{
		stack_a->size = 0;
		stack_a->bot = NULL;
		stack_a->top = NULL;
	}
	else
	{
		stack_a->top = stack_a->top->next;
		stack_a->top->prev = stack_a->bot;
		stack_a->bot->next = stack_a->top;
		stack_a->size--;
	}
	op_pb_sub1(temp, stack_b);
	stack_b->size++;
	if (PS_PRINT_OP == 1)
		ft_printf("pb\n");
	return ;
}
