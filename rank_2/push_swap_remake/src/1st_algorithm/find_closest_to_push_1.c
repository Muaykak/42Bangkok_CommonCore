/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_to_push_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:39:06 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 17:39:16 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the closest unsorted number in stack that is not swapable */
t_ps_node	*find_closest_to_push_b(t_ps_stack *stack)
{
	t_ps_node	*top;
	t_ps_node	*bot;

	if (stack == NULL || stack->size < 4)
		return (NULL);
	top = stack->top;
	bot = stack->bot;
	while (1)
	{
		if (check_unsorted(top) == 1 && check_swapable(top) == 0)
			return (top);
		if (check_unsorted(bot) == 1 && check_swapable(bot) == 0)
			return (bot);
		top = top->next;
		if (top == bot)
			break ;
		bot = bot->prev;
	}
	ft_printf("reach here\n");
	return (NULL);
}
