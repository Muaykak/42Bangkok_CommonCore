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

t_ps_node	*find_closest_to_swap_a(t_ps_stack *stack_a)
{
	t_ps_node	*temptop;
	t_ps_node	*tempbot;

	if (stack_a == NULL || stack_a->size == 0
		|| check_stack_asc_sorted(stack_a) == 1)
		return (NULL);
	temptop = stack_a->top;
	tempbot = stack_a->bot;
	while (1)
	{
		if (temptop->st_prev == temptop->next)
			return (temptop);
		if (tempbot->next == tempbot->st_prev)
			return (tempbot);
		temptop = temptop->next;
		if (temptop == tempbot)
			break ;
		tempbot = tempbot->prev;
	}
	return (NULL);
}
