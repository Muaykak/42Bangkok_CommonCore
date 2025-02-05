/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_easy_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:44:20 by srussame          #+#    #+#             */
/*   Updated: 2025/01/19 11:44:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_easy_op.h"

/* calculate the distance */
/* have to be on the same stack*/
int		easy_rotate(char c, t_list **stack, t_list *target, int print_op);
int 	(*decide_rotate_b(t_list *stack, t_list *target))
		(t_list **, t_list **, int);
int 	(*decide_rotate_a(t_list *stack, t_list *target))
		(t_list **, t_list **, int);
int		travese_dist(t_list *start, t_list *end);
int		easy_rotate_both(t_list **stack_a, t_list **stack_b,
		 t_list *target_a, t_list *target_b);

int	travese_dist(t_list *start, t_list *end)
{
	int 	i;
	t_list	*top;
	
	i = 0;
	if (!start || !end)
		return (i);
	top = start;
	while (start != 0 && start != end)
	{
		start = start->next;
		i++;
	}
	if ((ft_lstsize(top) + 1) / 2 > i)
		return (i);
	else
		return (ft_lstsize(top) - i);
}

/* decide to rotate or reverse rotate to that target*/
int (*decide_rotate_a(t_list *stack, t_list *target))(t_list **, t_list **, int)
{
	int 	i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (stack != target)
	{
		i++;
		stack = stack->next;
	}
	stack = temp;
	if (i > ((ft_lstsize(stack) + 1) / 2))
		return (&op_reverse_a);
	else
		return (&op_rotate_a);
}

int (*decide_rotate_b(t_list *stack, t_list *target))(t_list **, t_list **, int)
{
	int 	i;
	t_list	*temp;

	i = 0;
	temp = stack;
	while (stack != target)
	{
		i++;
		stack = stack->next;
	}
	stack = temp;
	if (i > ((ft_lstsize(stack) + 1) / 2))
		return (&op_reverse_b);
	else
		return (&op_rotate_b);
}

/* rotate the stack until the top of the stack is the same as target*/
int		easy_rotate(char c, t_list **stack, t_list *target, int print_op)
{
	int		(*decider)(t_list **, t_list **, int);
	int		i;

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

/* rotate both of the stack to given position*/
int		easy_rotate_both(t_list **stack_a, t_list **stack_b,
		 t_list *target_a, t_list *target_b)
{
	int	(*op_a)(t_list **, t_list **, int);
	int	(*op_b)(t_list **, t_list **, int);
	int	i;

	if (!stack_a || !stack_b || !(*stack_a) || !(*stack_b) 
	|| !target_a || !target_b)
		return (0);
	op_a = 0;
	op_b = 0;
	i = 0;
	while (*stack_a != target_a || *stack_b != target_b)
	{
		if (*stack_a != target_a)
			op_a = decide_rotate_a(*stack_a, target_a);
		if (*stack_b != target_b)
			op_b = decide_rotate_b(*stack_b, target_b);
		if (op_a == &op_rotate_a && op_b == &op_rotate_b)
			op_rotate_all(stack_a, stack_b, 1);
		if (op_a == &op_reverse_a && op_b == &op_reverse_b)
			op_reverse_all(stack_a, stack_b, 1);
		else
		{
			if (op_a)
				op_a(stack_a, stack_b, 1);
			if (op_b)
				op_b(stack_a, stack_b, 1);
		}
		op_a = 0;
		op_b = 0;
		i++;
	}
	return (i);
}
