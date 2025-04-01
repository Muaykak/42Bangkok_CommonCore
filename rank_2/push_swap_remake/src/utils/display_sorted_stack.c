/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sorted_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:16:35 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 15:16:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_sorted_stack(t_ps_stack *stack)
{
	t_ps_node	*runner;

	if (stack == NULL)
		return ;
	runner = stack->min;
	ft_printf("sorted stack\n");
	while (runner->target_next != stack->min)
	{
		ft_printf("[%d]: %d\n", runner->sort_pos, runner->number);
		runner = runner->target_next;
	}
	ft_printf("[%d]: %d\n", runner->sort_pos, runner->number);
	return ;
}