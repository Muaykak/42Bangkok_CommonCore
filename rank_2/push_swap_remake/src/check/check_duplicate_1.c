/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:40:45 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 20:40:58 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_ps_stack *stack_a)
{
	t_ps_node	*runner;
	t_ps_node	*check;

	if (stack_a == NULL || stack_a->top == NULL)
		return (0);
	check = stack_a->top;
	while (check->next != stack_a->top)
	{
		runner = check->next;
		while (runner != check)
		{
			if (check->number == runner->number)
				return (0);
			runner = runner->next;
		}
		check = check->next;
	}
	runner = check->next;
	while (runner != check)
	{
		if (check->number == runner->number)
			return (0);
		runner = runner->next;
	}
	return (1);
}
