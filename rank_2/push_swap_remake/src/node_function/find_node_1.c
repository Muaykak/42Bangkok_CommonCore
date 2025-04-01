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

static t_ps_node	*find_node_sub1(t_ps_node *temp, int num_pos)
{
	if (temp->sort_pos < num_pos)
	{
		if (abs(temp->sort_pos - num_pos) < abs(temp->stack->all_num_size - temp->sort_pos) + num_pos)
			while (temp->sort_pos != num_pos)
				temp = temp->target_next;
		else
			while (temp->sort_pos != num_pos)
				temp = temp->target_prev;
	}
	else
	{
		if (abs(temp->sort_pos - num_pos) < abs(temp->stack->all_num_size - temp->sort_pos) + num_pos)
			while (temp->sort_pos != num_pos)
				temp = temp->target_prev;
		else
			while (temp->sort_pos != num_pos)
				temp = temp->target_next;
	}
	return (temp);
}

t_ps_node	*find_node(t_ps_node *node_list, int num_pos)
{
	t_ps_node	*temp;
	if (node_list == NULL || num_pos < 1 
		|| num_pos > node_list->stack->all_num_size)
		return (NULL);
	temp = node_list;
	if (temp->sort_pos == num_pos)
		return (temp);
	temp = find_node_sub1(temp, num_pos);
	return (temp);
}
