/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_easy_op_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:59:38 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 21:59:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_easy_op.h"

int		easy_rotate(char c, t_list **stack, t_list *target, int print_op);
int		(*decide_rotate_b(t_list *stack, t_list *target))(t_list **,
			t_list **, int);
int		(*decide_rotate_a(t_list *stack, t_list *target))(t_list **,
			t_list **, int);

/* decide to rotate or reverse rotate to that target*/
int	(*decide_rotate_a(t_list *stack, t_list *target))
	(t_list **stack_a, t_list **stack_b, int print_op)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (stack != target)
	{
		i++;
		stack = stack->next;
	}
	stack = temp;
	if (i >= ((ft_lstsize(stack) + 1) / 2))
		return (&op_reverse_a);
	else
		return (&op_rotate_a);
}

int	(*decide_rotate_b(t_list *stack, t_list *target))
	(t_list **stack_a, t_list **stack_b, int print_op)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (stack != target)
	{
		i++;
		stack = stack->next;
	}
	stack = temp;
	if (i >= ((ft_lstsize(stack) + 1) / 2))
		return (&op_reverse_b);
	else
		return (&op_rotate_b);
}

/* rotate the stack until the top of the stack is the same as target*/
int	easy_rotate(char c, t_list **stack, t_list *target, int print_op)
{
	int	(*decider)(t_list **, t_list **, int);
	int	i;

	if (*stack == target || (*stack)->next == 0 || !target)
		return (0);
	if (c == 'a')
		decider = decide_rotate_a(*stack, target);
	else if (c == 'b')
		decider = decide_rotate_b(*stack, target);
	i = 0;
	while ((*stack) != target)
	{
		i++;
		decider(stack, stack, print_op);
	}
	return (i);
}
