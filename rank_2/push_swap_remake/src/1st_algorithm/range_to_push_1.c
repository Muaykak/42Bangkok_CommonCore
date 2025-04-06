/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_to_push_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:06:38 by srussame          #+#    #+#             */
/*   Updated: 2025/04/04 17:06:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range_to_push_b(t_ps_stack *stack_a)
{
	int	chunksize;
	int	range;

	if (stack_a == NULL)
		return (0);
	chunksize = (stack_a->all_num_size / CHUNK_SEP) * 2;
	if (chunksize == 0)
		return (stack_a->all_num_size);
	range = chunksize;
	while (range <= stack_a->stack_min->sort_pos)
		range += chunksize;
	return (range);
}

int	range_to_push_a(t_ps_stack *stack_b)
{
	int chunk_size;
	int	range;

	if (stack_b == NULL)
		return (0);
	chunk_size = stack_b->all_num_size / CHUNK_SEP;
	if (chunk_size == 0)
		return (0);
	range = stack_b->all_num_size;
	while (range + 1 > stack_b->stack_max->sort_pos)
		range = range - chunk_size;
	return (range);
}

/*find closest target in b to be rotate to the top of stack_b then
	push to the stack a so the number is sorted*/
t_ps_node	*find_closest_to_push_a_inrange(t_ps_stack *stack_b)
{
	t_ps_node	*target_b;
	t_ps_node	*target_a;
	t_ps_node	*top;
	int			range;


	if (stack_b == NULL || stack_b->size <= 0 || stack_b->link->sorted != TRUE)
		return (NULL);
	if (stack_b->link->size == 0)
		return (stack_b->top);
	top = stack_b->top;
	target_b = NULL;
	range = range_to_push_a(stack_b);
	while (top->next != stack_b->top)
	{
		target_a = find_target_in_a(top);
		if	(target_a != NULL)
		{
			top->optional = dist_cal(top, target_a);
			if (top->sort_pos >= range && (target_b == NULL || top->optional < target_b->optional))
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