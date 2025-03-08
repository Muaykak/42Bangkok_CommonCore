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

int	op_swap_b(t_list **unused, t_list **stack, int print_op);
int	op_swap_a(t_list **stack, t_list **unused, int print_op);
int	op_swap_all(t_list **stack_a, t_list **stack_b, int print_op);
int	op_rotate_b(t_list **unused, t_list **stack, int print_op);
int	op_rotate_a(t_list **unused, t_list **stack, int print_op);

int	op_swap_all(t_list **stack_a, t_list **stack_b, int print_op)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return (0);
	op_swap_a(stack_a, stack_b, 0);
	op_swap_b(stack_a, stack_b, 0);
	if (print_op == 1)
		ft_printf("ss\n");
	return (1);
}

int	op_swap_b(t_list **unused, t_list **stack, int print_op)
{
	t_list	*temp;

	(void)unused;
	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
	if (print_op == 1)
		ft_printf("sb\n");
	return (1);
}

int	op_swap_a(t_list **stack, t_list **unused, int print_op)
{
	t_list	*temp;

	(void)unused;
	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
	if (print_op == 1)
		ft_printf("sa\n");
	return (1);
}

int	op_rotate_a(t_list **stack, t_list **unused, int print_op)
{
	t_list	*temp;

	(void)unused;
	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = 0;
	*stack = temp;
	if (print_op == 1)
		ft_printf("ra\n");
	return (1);
}

int	op_rotate_b(t_list **unused, t_list **stack, int print_op)
{
	t_list	*temp;

	(void)unused;
	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack)->next;
	ft_lstadd_back(stack, *stack);
	(*stack)->next = 0;
	*stack = temp;
	if (print_op == 1)
		ft_printf("rb\n");
	return (1);
}
