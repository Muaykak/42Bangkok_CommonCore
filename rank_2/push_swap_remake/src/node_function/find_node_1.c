/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:15:51 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 14:16:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ps_node	*find_node_sort_pos_sub1(t_ps_node *temp, int sort_pos)
{
	if (temp->sort_pos < sort_pos)
	{
		if (abs(temp->sort_pos - sort_pos) < abs(temp->stack->all_num_size
			- temp->sort_pos) + sort_pos)
			while (temp->sort_pos != sort_pos)
				temp = temp->target_next;
		else
			while (temp->sort_pos != sort_pos)
				temp = temp->target_prev;
	}
	else
	{
		if (abs(temp->sort_pos - sort_pos) < abs(temp->stack->all_num_size
			- temp->sort_pos) + sort_pos)
			while (temp->sort_pos != sort_pos)
				temp = temp->target_prev;
		else
			while (temp->sort_pos != sort_pos)
				temp = temp->target_next;
	}
	return (temp);
}

t_ps_node	*find_node_sort_pos(t_ps_node *node_list, int sort_pos)
{
	t_ps_node	*temp;
	if (node_list == NULL || sort_pos < 1 
		|| sort_pos > node_list->stack->all_num_size)
		return (NULL);
	temp = node_list;
	if (temp->sort_pos == sort_pos)
		return (temp);
	temp = find_node_sort_pos_sub1(temp, sort_pos);
	return (temp);
}

/* find the lower node in the same stack */
t_ps_node	*find_lower_node(t_ps_node *target)
{
	t_ps_node	*lower;

	if (target == NULL || target->stack->size < 2)
		return (NULL);
	lower = target->target_prev;
	while (lower->sort_pos > 1)
	{
		if (lower->stack->stack == target->stack->stack)
			return (lower);
		lower = lower->target_prev;
	}
	if (lower->stack->stack == target->stack->stack)
		return (lower);
	return (NULL);
}

t_ps_node	*find_higher_node(t_ps_node *target)
{
	t_ps_node	*higher;

	if (target == NULL || target->stack->size < 2)
		return (NULL);
	higher = target->target_next;
	while (higher->sort_pos < higher->stack->all_num_size)
	{
		if (higher->stack->stack == target->stack->stack)
			return (higher);
		higher = higher->target_next;
	}
	if (higher->stack->stack == target->stack->stack)
		return (higher);
	return (NULL);
}
