/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_to_push_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:39:06 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 17:39:16 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the closest unsorted number in stack that is not swapable */
t_ps_node	*find_closest_to_push_b(t_ps_stack *stack)
{
	t_ps_node	*top;
	t_ps_node	*bot;

	if (stack == NULL || stack->size < 4 || stack->sorted == TRUE)
		return (NULL);
	top = stack->top;
	bot = stack->bot;
	while (1)
	{
		if (top->unorder == TRUE && top->swap_able == FALSE)
			return (top);
		if (bot->unorder == TRUE && bot->swap_able == FALSE)
			return (bot);
		top = top->next;
		if (top == bot)
			break ;
		bot = bot->prev;
	}
	return (NULL);
}

/* find the number that need to be on
the top of stack_a to push the target back then it's sorted
	the target need to be on stack_b*/
t_ps_node	*find_target_in_a(t_ps_node *target_b)
{
	t_ps_node	*stack_min;
	t_ps_node	*sort_pos;

	if (target_b == NULL || target_b->stack->link->size == 0)
		return (NULL);
	stack_min = target_b->stack->link->stack_min;
	if (target_b->sort_pos > target_b->stack->link->stack_max->sort_pos)
		return (stack_min);
	if (target_b->sort_pos < target_b->stack->link->stack_min->sort_pos)
		return (stack_min);
	sort_pos = target_b->target_next;
	while (1)
	{
		if (stack_min->sort_pos > target_b->sort_pos)
			return (stack_min);
		if (sort_pos->stack->stack == A)
			return (sort_pos);
		stack_min = stack_min->st_next;
		if (stack_min == stack_min->stack->stack_max
			|| (sort_pos->stack->stack == A
				&& sort_pos->sort_pos > stack_min->sort_pos))
			break ;
		sort_pos = sort_pos->target_next;
	}
	return (NULL);
}

static void	find_closest_to_push_a_sub1(t_ps_node *top, t_ps_node **target_b)
{
	t_ps_node	*target_a;

	target_a = find_target_in_a(top);
	if (target_a != NULL)
	{
		top->optional = dist_cal(top, target_a);
		if (*target_b == NULL || top->optional < (*target_b)->optional)
			(*target_b) = top;
	}
}

/*find closest target in b to be rotate to the top of stack_b then
	push to the stack a so the number is sorted*/
t_ps_node	*find_closest_to_push_a(t_ps_stack *stack_b)
{
	t_ps_node	*target_b;
	t_ps_node	*top;

	if (stack_b == NULL || stack_b->size <= 0 || stack_b->link->sorted != TRUE)
		return (NULL);
	if (stack_b->link->size == 0)
		return (stack_b->top);
	top = stack_b->top;
	target_b = NULL;
	while (top->next != stack_b->top)
	{
		find_closest_to_push_a_sub1(top, &target_b);
		top = top->next;
	}
	find_closest_to_push_a_sub1(top, &target_b);
	return (target_b);
}
