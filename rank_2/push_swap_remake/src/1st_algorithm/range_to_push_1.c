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
	chunksize = stack_a->max->sort_pos / CHUNK_SEP;
	if (chunksize == 0)
		return (stack_a->max->sort_pos);
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
	chunk_size = stack_b->max->sort_pos / CHUNK_SEP;
	if (chunk_size == 0)
		return (0);
	range = stack_b->max->sort_pos;
	while (range >= stack_b->stack_max->sort_pos)
		range = range - chunk_size;
	return (range);
}
