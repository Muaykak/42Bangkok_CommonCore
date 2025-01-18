/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_my_algor_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:50:08 by srussame          #+#    #+#             */
/*   Updated: 2025/01/18 17:50:09 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_my_algor.h"

void	sorting_stack(t_list **stack_a, t_list **stack_b, int min, int max);
void	pivot_to_stack(t_list **stack_a, t_list **stack_b);
void	push_pivot(t_list **stack_a, t_list **stack_b, int min, int max);

/* *************************************************************** */
/* *************************************************************** */
/* *************************************************************** */

void	sorting_stack(t_list **stack_a, t_list **stack_b, int min, int max)
{
	push_pivot(stack_a, stack_b, min, max);
	if (*stack_b == 0)
		return ;
	if (((int *)((*stack_b)->content))[0] == max)
	{
		while (((int *)((*stack_a)->content))[0] != min)
			op_handler(stack_a, stack_b, &op_rotate_a, PRINT_OP);
		op_handler(stack_a, stack_b, &op_push_a, PRINT_OP);
		return ;
	}
	pivot_to_stack(stack_a, stack_b);
	return ;
}

/* Put the number that pushed to b back to a to the next position which 
	has higher number that the pivot number */
void	pivot_to_stack(t_list **stack_a, t_list **stack_b)
{
	while (((int *)((*stack_a)->content))[0] \
	< ((int *)((*stack_b)->content))[0])
		op_handler(stack_a, stack_b, &op_rotate_a, PRINT_OP);
	op_handler(stack_a, stack_b, &op_push_a, PRINT_OP);
}

/* Find the first number That its value is more than next one in the list 
	and will push it to stack b
	will not do anything if both numbers are min and max number */
void	push_pivot(t_list **stack_a, t_list **stack_b, int min, int max)
{
	if (((int *)((*stack_a)->content))[0] > ((int *)((*stack_a)->next->content))[0])
	{
		if (((int *)((*stack_a)->content))[0] == max && \
		((int *)((*stack_a)->next->content))[0] == min)
			return ;
		op_handler(stack_a, stack_b, &op_push_b, PRINT_OP);
	}
}

/* *************************************************************** */
/* *************************************************************** */
/* *************************************************************** */

