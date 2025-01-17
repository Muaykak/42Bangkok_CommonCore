/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:31:57 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 17:31:59 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	op_reverse_a(t_list **stack_a, t_list **stack_b);
void	op_reverse_b(t_list **stack_a, t_list **stack_b);
void	op_reverse_rrr(t_list **stack_a, t_list **stack_b);

void	op_reverse_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a == 0 || (*stack_a)->next == 0) || \
	(*stack_b == 0 || (*stack_b)->next == 0))
		return ;
	op_reverse_a(stack_a, stack_b);
	op_reverse_b(stack_a, stack_b);
}

void	op_reverse_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	(void)stack_b;
	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	temp = *stack_a;
	while (temp->next->next != 0)
		temp = temp->next;
	ft_lstadd_front(stack_a, ft_lstlast(*stack_a));
	temp->next = 0;
}

void	op_reverse_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	(void)stack_a;
	if (*stack_b == 0 || (*stack_b)->next == 0)
		return ;
	temp = *stack_b;
	while (temp->next->next != 0)
		temp = temp->next;
	ft_lstadd_front(stack_b, ft_lstlast(*stack_b));
	temp->next = 0;
}
