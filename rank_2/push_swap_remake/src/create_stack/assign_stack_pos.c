/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:39:25 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 16:39:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_stack_pos(t_ps_stack *stack)
{
	int			pos;
	t_ps_node	*runner;

	if (stack == NULL || stack->top == NULL)
		return ;
	pos = 1;
	runner = stack->top;
	while (runner->next != stack->top)
	{
		runner->stack_pos = pos++;
		runner = runner->next;
	}
	runner->stack_pos = pos;
	return ;
}
