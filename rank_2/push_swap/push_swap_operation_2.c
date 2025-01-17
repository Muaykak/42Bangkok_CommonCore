/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:33:21 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 15:33:48 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	op_push_b(t_list **stack_a, t_list **stack_b);
void	op_push_a(t_list **stack_a, t_list **stack_b);

void	op_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_a) == 0)
		return ;
	temp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = temp;
}

void	op_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_b) == 0)
		return ;
	temp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp;
}

void	op_rotate_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	(void)(stack_b);
	if (*stack_a == 0)
		return ;
	
}
