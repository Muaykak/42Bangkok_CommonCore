/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_my_algor_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:50:46 by srussame          #+#    #+#             */
/*   Updated: 2025/01/22 17:50:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_my_algor.h"

/* find and return the highest num position on the stack*/
t_list	*find_highest_num(t_list *stack)
{
	t_list	*target;

	if (!stack)
		return (0);
	target = stack;
	while (stack != 0)
	{
		if (*((int *)stack->content) > 
		*((int *)target->content))
			target = stack;
		stack = stack->next;
	}
	return (target);
}

/* find and return the lowest num position on the stack*/
t_list	*find_lowest_num(t_list *stack)
{
	t_list	*target;

	if (!stack)
		return (0);
	target = stack;
	while (stack != 0)
	{
		if (*((int *)stack->content) < 
		*((int *)target->content))
			target = stack;
		stack = stack->next;
	}
	return (target);
}

/* find the closest higher num of the top number */
t_list	*find_close_high(t_list *stack)
{
	int		top_num;
	t_list	*close;

	if (!stack)
		return (0);
	top_num = *((int *)stack->content);
	close = find_highest_num(stack);
	while (stack != 0)
	{
		if (*((int *)stack->content) > top_num &&
		*((int *)stack->content) < *((int *)close->content))
			close = stack;
		stack = stack->next;
	}
	return (close);
}

/* find the closest lower num of the top number */
t_list	*find_close_low(t_list *stack)
{
	int		top_num;
	t_list	*close;

	if (!stack)
		return (0);
	top_num = *((int *)stack->content);
	close = find_lowest_num(stack);
	while (stack != 0)
	{
		if (*((int *)stack->content) < top_num &&
		*((int *)stack->content) > *((int *)close->content))
			close = stack;
		stack = stack->next;
	}
	return (close);
}

/* move the top of a to be on top of the closest higher number*/
int	move_stack_a(t_list **stack_a, t_list **stack_b, int print_op)
{
	t_list *target;

	if (!stack_a || !stack_b || !(*stack_a))
		return (0);
	if (*((int *)((*stack_a)->content)) == high_num(*stack_a))
	{
		op_push_b(stack_a, stack_b, print_op);
		easy_rotate('a', stack_a, find_lowest_num(*stack_a), print_op);
		op_push_a(stack_a, stack_b, print_op);
		return (1);
	}
	target = find_close_high(*stack_a);
	if (target == (*stack_a)->next)
	{
		op_swap_a(stack_a, stack_b, print_op);
	}
	op_push_b(stack_a, stack_b, print_op);
	easy_rotate('a', stack_a, target, print_op);
	op_push_a(stack_a, stack_b, print_op);
	return (1);
}

/* move the top of a to be on top of the closest lower number*/
int	move_stack_b(t_list **stack_a, t_list **stack_b, int print_op)
{
	t_list *target;

	if (!stack_b || !stack_a || !(*stack_b))
		return (0);
	if (*((int *)((*stack_b)->content)) == low_num(*stack_b))
	{
		op_push_a(stack_a, stack_b, print_op);
		easy_rotate('b', stack_b, find_highest_num(*stack_b), print_op);
		op_push_b(stack_a, stack_b, print_op);
		return (1);
	}
	target = find_close_low(*stack_b);
	if (target == (*stack_b)->next)
	{
		op_swap_b(stack_a, stack_b, print_op);
	}
	op_push_a(stack_a, stack_b, print_op);
	easy_rotate('b', stack_b, target, print_op);
	op_push_b(stack_a, stack_b, print_op);
	return (1);
}

/* check if value lowest to highest */
int	check_ascending_stack(t_list *stack)
{
	int i;

	if (!stack)
		return (0);
	i = *((int *)stack->content);
	while (stack != 0)
	{
		if (i > *((int *)stack->content))
			return (0);
		else
			i = *((int *)stack->content);
		stack = stack->next;
	}
	return (1);
}

/* check if value lowest to highest */
int	check_descending_stack(t_list *stack)
{
	int i;

	if (!stack)
		return (0);
	i = *((int *)stack->content);
	while (stack != 0)
	{
		if (i < *((int *)stack->content))
			return (0);
		else
			i = *((int *)stack->content);
		stack = stack->next;
	}
	return (1);
}

/* Return the pointer that points to the funciton that will operate*/
int	(*sort_stack_a(t_list *stack_a))(t_list **, t_list **, int)
{
	if (!stack_a || !stack_a->next)
		return (0);
	if (check_ascending_stack(stack_a) == 1)
		return (0);
	if (*((int *)stack_a->content) > *((int *)stack_a->next->content))
	{
		if (*((int *)stack_a->content) == high_num(stack_a) &&
		*((int *)stack_a->next->content) == low_num(stack_a))
			return (&op_rotate_a);
		else
			return (&op_swap_a);
	}
	else
		return (&op_rotate_a);
}

/* Return the pointer that points to the funciton that will operate*/
int	(*sort_stack_b(t_list *stack_b))(t_list **, t_list **, int)
{
	if (!stack_b || !stack_b->next)
		return (0);
	if (check_descending_stack(stack_b) == 1)
		return (0);
	if (*((int *)stack_b->content) < *((int *)stack_b->next->content))
	{
		if (*((int *)stack_b->content) == low_num(stack_b) &&
		*((int *)stack_b->next->content) == high_num(stack_b))
			return (&op_rotate_b);
		else
			return (&op_swap_b);
	}
	else
		return (&op_rotate_b);
}

void	my_algor(t_list **stack_a, t_list **stack_b, int print_op)
{
	int		i;
	int		(*a_op)(t_list **, t_list **, int);
	int		(*b_op)(t_list **, t_list **, int);
	int		maxmin[2];

	if (check_stack_sorted(*stack_a, *stack_b) == 1)
		return ;
	i = ft_lstsize(*stack_a);
	maxmin[0] = low_num(*stack_a);
	maxmin[1] = high_num(*stack_a);
	while (ft_lstsize(*stack_b) < i / 2)
	{
		if (maxmin[1] - *((int *)((*stack_a)->content)) <=
		*((int *)((*stack_a)->content)) - maxmin[0])
			op_rotate_a(stack_a, stack_b, print_op);
		else
			op_push_b(stack_a, stack_b, print_op);
	}
	a_op = 0;
	b_op = 0;
	i = 0;
	while ((check_ascending_stack(*stack_a) != 1 
	|| check_descending_stack(*stack_b) != 1))
	{
			a_op = sort_stack_a(*stack_a);
			b_op = sort_stack_b(*stack_b);
		if (a_op == &op_rotate_a && b_op == &op_rotate_b)
			op_rotate_all(stack_a, stack_b, print_op);
		else if (a_op == &op_swap_a && b_op == &op_swap_b)
			op_swap_all(stack_a, stack_b, print_op);
		else
		{
			if (a_op != 0)
				a_op(stack_a, stack_b, print_op);
			if (b_op != 0)
				b_op(stack_a, stack_b, print_op);
			i++;
		}
	}
}