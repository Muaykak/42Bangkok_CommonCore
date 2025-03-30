/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_addback_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:29:33 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 01:29:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_node_addback(t_ps_node **node_list, t_ps_node *node)
{
	t_ps_stack	*stack;

	if (node_list == NULL || node == NULL)
		return ;
	if (*node_list == NULL)
	{
		*node_list = node;
		(*node_list)->next = node;
		(*node_list)->prev = node;
		(*node_list)->stack->top = node;
		(*node_list)->stack->bot = node;
		(*node_list)->stack->size = 1;
		return ;
	}
	stack = (*node_list)->stack;
	node->stack = stack;
	node->next = stack->top;
	node->prev = stack->bot;
	stack->bot->next = node;
	stack->top->prev = node;
	stack->bot = node;
	stack->size++;
}
