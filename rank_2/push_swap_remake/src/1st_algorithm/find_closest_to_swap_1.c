/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_to_swap_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:11:32 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 16:11:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_node	*find_closest_to_swap(t_ps_stack *stack)
{
	t_ps_node	*temptop;
	t_ps_node	*tempbot;

	if (stack == NULL || stack->size <= 2 || stack->sorted == TRUE)
		return (NULL);
	temptop = stack->top;
	tempbot = stack->bot;
	while (1)
	{
		if (temptop->swap_top == TRUE && temptop->unorder == TRUE)
			return (temptop);
		if (tempbot->swap_top == TRUE && tempbot->unorder == TRUE)
			return (tempbot);
		temptop = temptop->next;
		if (temptop == tempbot)
			break ;
		tempbot = tempbot->prev;
	}
	return (NULL);
}
