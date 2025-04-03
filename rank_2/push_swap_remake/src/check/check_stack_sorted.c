/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:52:02 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 16:52:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_asc_sorted(t_ps_stack *stack);
int	check_stack_desc_sorted(t_ps_stack *stack);

/*check if the stack is already ascending sorted */
int	check_stack_asc_sorted(t_ps_stack *stack)
{
	t_ps_node	*runner;

	if (stack == NULL)
		return (0);
	if (stack->size <= 2)
		return (1);
	runner = stack->top;
	while (runner->next != stack->top)
	{
		if (runner->st_next != runner->next)
			return (0);
		runner = runner->next;
	}
	if (runner->st_next != runner->next)
		return (0);
	return (1);
}

/*check if the stack is already descending sorted */
int	check_stack_desc_sorted(t_ps_stack *stack)
{
	t_ps_node	*runner;

	if (stack == NULL)
		return (0);
	if (stack->size <= 2)
		return (1);
	runner = stack->top;
	while (runner->next != stack->top)
	{
		if (runner->st_prev != runner->next)
			return (0);
		runner = runner->next;
	}
	if (runner->st_prev != runner->next)
		return (0);
	return (1);
}
