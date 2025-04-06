/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack_unsorted_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:04:51 by srussame          #+#    #+#             */
/*   Updated: 2025/04/03 12:05:06 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_node_unsorted_b(t_ps_node *node)
{
	if (node == NULL)
		return ;
	if (node->stack->size <= 2 || (node->prev == node->st_next
			&& (node->next == node->st_prev)))
		node->unorder = FALSE;
	else
		node->unorder = TRUE;
	if (check_swapable(node) == 1)
		node->swap_able = TRUE;
	else
		node->swap_able = FALSE;
	if (node->st_next == node->next)
		node->swap_top = TRUE;
	else
		node->swap_top = FALSE;
}

void	assign_node_unsorted_a(t_ps_node *node)
{
	if (node == NULL)
		return ;
	if (node->stack->size <= 2 || ((node->next == node->st_next)
			&& (node->prev == node->st_prev)))
		node->unorder = FALSE;
	else
		node->unorder = TRUE;
	if (check_swapable(node) == 1)
		node->swap_able = TRUE;
	else
		node->swap_able = FALSE;
	if (node->st_prev == node->next)
		node->swap_top = TRUE;
	else
		node->swap_top = FALSE;
}

void	assign_node_unsorted(t_ps_node *node)
{
	if (node->stack->stack == A)
		assign_node_unsorted_a(node);
	else
		assign_node_unsorted_b(node);
}

void	assign_stack_unsorted(t_ps_stack *stack)
{
	t_ps_node	*top;

	if (stack == NULL || stack->size <= 2)
		return ;
	top = stack->top;
	while (top->next != stack->top)
	{
		assign_node_unsorted(top);
		top = top->next;
	}
	assign_node_unsorted(top);
}
