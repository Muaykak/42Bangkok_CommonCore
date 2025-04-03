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

	if (target_b == NULL || target_b->stack->stack == A
		|| target_b->stack->link->size == 0)
		return (NULL);
	stack_min = target_b->stack->link->stack_min;
	if (target_b->sort_pos > target_b->stack->link->stack_max->sort_pos)
	{
		if (stack_min->prev == stack_min->stack->stack_max)
			return (stack_min);
		else
			return (NULL);
	}
	if (target_b->sort_pos < target_b->stack->link->stack_min->sort_pos)
	{
		if (stack_min->prev == stack_min->stack->stack_max)
			return (stack_min);
		else
			return (NULL);
	}
	sort_pos = target_b->target_next;
	while (1)
	{
		if (stack_min->sort_pos > target_b->sort_pos)
		{
			if (stack_min->prev == stack_min->st_prev)
				return (stack_min);
			else
				return (NULL);
		}
		if (sort_pos->stack->stack == A)
		{
			if (sort_pos->prev == sort_pos->st_prev)
				return (sort_pos);
			else
				return (NULL);
		}
		stack_min = stack_min->st_next;
		if (stack_min == stack_min->stack->stack_max || (sort_pos->stack
			->stack == A && sort_pos->sort_pos > stack_min->sort_pos))
			break ;
		sort_pos = sort_pos->target_next;
	}
	return (NULL);
}

/*find closest target in b to be rotate to the top of stack_b then
	push to the stack a so the number is sorted*/
t_ps_node	*find_closest_to_push_a(t_ps_stack *stack_b)
{
	t_ps_node	*target_b;
	t_ps_node	*target_a;
	t_ps_node	*top;


	if (stack_b == NULL || stack_b->size <= 0)
		return (NULL);
	if (stack_b->link->size == 0)
		return (stack_b->top);
	top = stack_b->top;
	target_b = NULL;
	while (top->next != stack_b->top)
	{
		target_a = find_target_in_a(top);
		if	(target_a != NULL)
		{
			top->optional = dist_cal(top, target_a);
			if (target_b == NULL || top->optional < target_b->optional)
				target_b = top;
		}
		top = top->next;
	}
	target_a = find_target_in_a(top);
	if	(target_a != NULL)
	{
		top->optional = dist_cal(top, find_target_in_a(top));
		if (target_b == NULL || top->optional < target_b->optional)
			target_b = top;
	}
	return (target_b);
}
