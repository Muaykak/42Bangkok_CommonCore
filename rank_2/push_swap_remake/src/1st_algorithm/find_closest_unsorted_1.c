/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_unsorted_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:31:02 by srussame          #+#    #+#             */
/*   Updated: 2025/04/03 13:31:12 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the closest unsorted number to push to the top of the stack */
t_ps_node	*find_closest_unsorted(t_ps_stack *stack)
{
	t_ps_node	*top;
	t_ps_node	*bot;

	if (stack == NULL || stack->size <= 2 || stack->sorted == TRUE)
		return (NULL);
	top = stack->top;
	bot = stack->bot;
	while (1)
	{
		if (top->unorder == TRUE)
			return (top);
		if (bot->unorder == TRUE)
			return (bot);
		top = top->next;
		if (top == bot)
			break ;
		bot = bot->prev;
	}
	return (NULL);
}
