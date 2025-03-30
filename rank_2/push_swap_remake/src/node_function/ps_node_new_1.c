/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_new_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:43:22 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 22:43:33 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*ps_node_new(t_ps_stack *stack, int num)
{
	t_ps_node	*new_node;

	if (stack == NULL)
		return (NULL);
	new_node = (t_ps_node *)ft_calloc(1, sizeof(t_ps_node));
	if (new_node == NULL)
		return (NULL);
	new_node->number = num;
	new_node->stack = stack;
	return (new_node);
}
