/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_clearall_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 03:04:12 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 03:04:31 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_node_clearall(t_ps_node **node_list)
{
	t_ps_node	*top;
	t_ps_node	*temp;
	t_ps_node	*bot;

	if (node_list == NULL || *node_list == NULL)
		return ;
	top = (*node_list)->stack->top;
	bot = (*node_list)->stack->bot;
	while (top != bot)
	{
		temp = top->next;
		ps_node_delone(top);
		top = temp;
	}
	free(top->stack);
	top->stack = NULL;
	ps_node_delone(top);
}
