/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_push_in_range_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:07:35 by srussame          #+#    #+#             */
/*   Updated: 2025/04/05 23:07:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_funct	decide_b_in_range(t_ps_stack *stack_a, t_ps_stack *stack_b);

t_op_funct	decide_b_in_range(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	int	range;

	if (stack_b->size < 2)
		return (NULL);
	range = range_to_push_b(stack_a) - (stack_a->all_num_size / CHUNK_SEP);
	if (stack_b->top->sort_pos < range)
		return (&op_rb);
	return (NULL);
}

t_ps_node	*find_to_push_b_inrange(t_ps_stack *stack_a)
{
	int			range;
	t_ps_node	*top;
	t_ps_node	*bot;

	if (stack_a->size <= 3)
		return (NULL);
	if (stack_a->size == 4)
		return (stack_a->top);
	range = range_to_push_b(stack_a);
	top = stack_a->top;
	bot = stack_a->bot;
	while (1)
	{
		if (top->sort_pos <= range)
			return (top);
		if (bot->sort_pos <= range)
			return (bot);
		top = top->next;
		if (top == bot)
			break ;
		bot = bot->prev;
		if (top == bot)
			break ;
	}
	return (NULL);
}
