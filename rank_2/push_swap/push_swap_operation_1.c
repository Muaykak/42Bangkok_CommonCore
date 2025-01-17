/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:23 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 14:07:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	op_swap_a(t_list **stack_a, t_list **stack_b);
void	op_swap_b(t_list **stack_a, t_list **stack_b);
void	op_swap_ss(t_list **stack_a, t_list **stack_b);
void	operation_handler(t_list **stack_a, t_list **stack_b, \
		void (*operation)(t_list **, t_list **));

void	operation_handler(t_list **stack_a, t_list **stack_b, \
		void (*operation)(t_list **, t_list **))
{
	(*operation)(stack_a, stack_b);
	if (operation == &op_swap_a)
		ft_printf("sa\n");
	else if (operation == &op_swap_b)
		ft_printf("sb\n");
	else if (operation == &op_swap_ss)
		ft_printf("ss\n");
	else if (operation == &op_push_a)
		ft_printf("pa\n");
	else if (operation == &op_push_b)
		ft_printf("pb\n");
	else if (operation == &op_rotate_a)
		ft_printf("ra\n");
	else if (operation == &op_rotate_b)
		ft_printf("rb\n");
	else if (operation == &op_rotate_rr)
		ft_printf("rr\n");
	else if (operation == &op_reverse_a)
		ft_printf("rra\n");
	else if (operation == &op_reverse_b)
		ft_printf("rrb\n");
	else if (operation == &op_reverse_rrr)
		ft_printf("rrr\n");
}

void	op_swap_ss(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a != 0 && (*stack_a)->next != 0) \
	&& (*stack_b != 0 && (*stack_b)->next != 0))
		return ;
	op_swap_a(stack_a, stack_b);
	op_swap_b(stack_a, stack_b);
}

void	op_swap_a(t_list **stack_a, t_list **stack_b)
{
	t_list	**swap_stack;
	t_list	*temp;

	(void)(stack_b);
	if (*stack_a != 0 && (*stack_a)->next != 0)
	{
		swap_stack = stack_a;
		temp = (*swap_stack)->next;
		(*swap_stack)->next = (*swap_stack)->next->next;
		temp->next = (*swap_stack);
		*stack_a = temp;
	}
}

void	op_swap_b(t_list **stack_a, t_list **stack_b)
{
	t_list	**swap_stack;
	t_list	*temp;

	(void)(stack_a);
	if (*stack_b != 0 && (*stack_b)->next != 0)
	{
		swap_stack = stack_b;
		temp = (*swap_stack)->next;
		(*swap_stack)->next = (*swap_stack)->next->next;
		temp->next = (*swap_stack);
		*stack_b = temp;
	}
}
