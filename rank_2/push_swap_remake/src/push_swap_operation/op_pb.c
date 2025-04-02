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

static void		op_pb_sub2(t_ps_stack *stack_a);
static void		op_pb_sub1(t_ps_node *temp, t_ps_stack *stack_b);

/* Push from stack a to stack b */
void	op_pb(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*temp;

	if (stack_a == NULL || stack_b == NULL || stack_a->size < 1)
		return ;
	temp = stack_a->top;
	op_pb_sub2(stack_a);
	op_pb_sub1(temp, stack_b);
	stack_b->size++;
	assign_stack_pos(stack_a);
	assign_stack_pos(stack_b);
	if (PS_PRINT_OP == 1)
		ft_printf("pb\n");
	return ;
}

static void	op_pb_sub1(t_ps_node *temp, t_ps_stack *stack_b)
{
	temp->stack = stack_b;
	if (stack_b->size == 0)
	{
		temp->next = temp;
		temp->prev = temp;
		stack_b->top = temp;
		stack_b->bot = temp;
		stack_b->stack_min = temp;
		stack_b->stack_max = temp;
	}
	else
	{
		temp->next = stack_b->top;
		temp->prev = stack_b->bot;
		stack_b->top->prev = temp;
		stack_b->bot->next = temp;
		stack_b->top = temp;
		if (stack_b->top->number > stack_b->stack_max->number)
			stack_b->stack_max = stack_b->top;
		else if (stack_b->top->number < stack_b->stack_min->number)
			stack_b->stack_min = stack_b->top;
	}
}

static	void	op_pb_sub2(t_ps_stack *stack_a)
{
	if (stack_a->size <= 1)
	{
		stack_a->size = 0;
		stack_a->bot = NULL;
		stack_a->top = NULL;
		stack_a->stack_max = NULL;
		stack_a->stack_min = NULL;
	}
	else
	{
		if (stack_a->top == stack_a->stack_max)
			stack_a->stack_max = find_lower_node(stack_a->stack_max);
		else if (stack_a->top == stack_a->stack_min)
			stack_a->stack_min = find_higher_node(stack_a->stack_min);
		stack_a->top = stack_a->top->next;
		stack_a->top->prev = stack_a->bot;
		stack_a->bot->next = stack_a->top;
		stack_a->size--;
	}
}
