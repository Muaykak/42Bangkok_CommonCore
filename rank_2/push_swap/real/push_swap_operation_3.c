/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:27:18 by srussame          #+#    #+#             */
/*   Updated: 2025/01/24 15:27:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	op_reverse_a(t_list **stack, t_list **unused, int print_op);
int	op_rotate_all(t_list **stack_a, t_list **stack_b, int print_op);
int	op_reverse_b(t_list **unused, t_list **stack, int print_op);
int	op_reverse_all(t_list **stack_a, t_list **stack_b, int print_op);
int	op_push_a(t_list **push, t_list **stack, int print_op);

int	op_push_a(t_list **push, t_list **stack, int print_op)
{
	t_list	*new;

	if (!push || !stack || (*stack) == 0)
		return (0);
	new = *stack;
	*stack = (*stack)->next;
	ft_lstadd_front(push, new);
	if (print_op == 1)
		ft_printf("pa\n");
	return (1);
}

int	op_reverse_all(t_list **stack_a, t_list **stack_b, int print_op)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return (0);
	op_reverse_a(stack_a, stack_b, 0);
	op_reverse_b(stack_a, stack_b, 0);
	if (print_op == 1)
		ft_printf("rrr\n");
	return (1);
}

int	op_reverse_b(t_list **unused, t_list **stack, int print_op)
{
	t_list	*temp;

	(void)unused;
	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack);
	while (temp->next->next != 0)
		temp = temp->next;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	temp->next = 0;
	if (print_op == 1)
		ft_printf("rrb\n");
	return (1);
}

int	op_reverse_a(t_list **stack, t_list **unused, int print_op)
{
	t_list	*temp;

	(void)unused;
	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack);
	while (temp->next->next != 0)
		temp = temp->next;
	ft_lstadd_front(stack, ft_lstlast(*stack));
	temp->next = 0;
	if (print_op == 1)
		ft_printf("rra\n");
	return (1);
}

int	op_rotate_all(t_list **stack_a, t_list **stack_b, int print_op)
{
	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b))
		return (0);
	op_rotate_a(stack_a, stack_b, 0);
	op_rotate_b(stack_a, stack_b, 0);
	if (print_op == 1)
		ft_printf("rr\n");
	return (1);
}
