/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_addfront_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:42:55 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 21:43:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_node_addfront(t_ps_node **node_list, t_ps_node *node)
{
	if (node_list == NULL || node == NULL)
		return ;
	if (*node_list == NULL)
	{
		*node_list = node;
		node->stack = (*node_list)->stack;
		(*node_list)->next = node;
		(*node_list)->prev = node;
		(*node_list)->stack->top = node;
		(*node_list)->stack->bot = node;
		(*node_list)->stack->size = 1;
		return ;
	}
	node->stack = (*node_list)->stack;
	node->next = (*node_list)->stack->top;
	node->prev = (*node_list)->stack->bot;
	(*node_list)->stack->bot->next = node;
	(*node_list)->stack->top->prev = node;
	(*node_list)->stack->top = node;
	(*node_list)->stack->size++;
	return ;
}
