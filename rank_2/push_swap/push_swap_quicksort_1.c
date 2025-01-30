/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:22:01 by srussame          #+#    #+#             */
/*   Updated: 2025/01/25 09:22:03 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_quicksort.h"

void	quicksort_main(t_list *top, t_list *bottom,
		 t_list **stack_a, t_list **stack_b);

/* to check if the pivot is in the right position*/
int check_pivot(t_list *pivot, t_list *stack)
{
	if (!pivot || !stack)
		return (0);
	while (stack != 0 && stack != pivot)
	{
		if (*((int *)stack->content) > 
		*((int *)pivot->content))
			return (0);
		stack = stack->next;
	}
	if (stack == 0 || (stack->next == 0 && stack == pivot))
		return (1);
	while (stack != 0)
	{
		if (*((int *)stack->content) <
		 *((int *)pivot->content))
		 	return (0);
		stack = stack->next;
	}
	return (1);
}

/* return the position the should rotate the pivot to*/
 t_list	*pivot_end_pos(t_list *pivot, t_list *stack)
{
	if (!pivot || !stack || pivot == stack || check_pivot(pivot, stack) == 1)
		return (0);
	while (stack->next != 0)
	{
		if (*((int *)stack->content) >= *((int *)pivot->content) &&
		 *((int *)stack->next->content) < *((int *)pivot->content))
		 	return (stack->next);
		stack = stack->next;
	}
	return (0);
}

/*check if from the top to the right 
if there are any number that less that the pivot*/
int	check_push_left(t_list *stack, t_list *right, t_list *pivot)
{
	if (!stack || !right || !pivot)
		return (0);
	while (stack != right)
	{
		if (*((int *)stack->content) < *((int *)pivot->content))
			return (1);
		stack = stack->next;
	}
	if (*((int *)stack->content) < *((int *)pivot->content))
		return (1);
	else
		return (0);
}

/* give new right position */
t_list	*new_right(t_list *stack_a, t_list *right)
{
	t_list	*top;

	if (!stack_a || !right)
		return (0);
	top = stack_a;
	while (stack_a != 0 && stack_a != right)
	{
		if (stack_a == right)
			return (right);
		stack_a = stack_a->next;
	}
	if (stack_a == right)
		return (right);
	else
		return (ft_lstlast(top));
}

/* check if left side is on stack b*/
int	check_left_stack_b(t_list *stack_b, t_list *left)
{
	if (!stack_b || !left)
		return (0);
	while (stack_b != 0)
	{
		if (stack_b == left)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}

/* check if pivot is in the stack b*/
int	check_pivot_in_b(t_list *stack_b, t_list *pivot)
{
	if (!stack_b || !pivot)
		return (0);
	while (stack_b != 0)
	{
		if (stack_b == pivot)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}
/* find the number that is equal or more than the pivot that is not the pivot
	and that number needs to be the number that has the fewest moves to push to stack a*/
t_list *find_close_pivot(t_list *stack_b, t_list *pivot)
{
	int		distance;
	t_list	*top;
	t_list	*target;

	if (!stack_b || !pivot || check_pivot_in_b(stack_b, pivot) == 0)
		return (0);
	distance = 0;
	target = 0;
	top = stack_b;
	while (stack_b != 0)
	{
		if (stack_b != pivot && *((int *)stack_b->content) >= *((int *)pivot->content))
		{
			if (target == 0)
			{
				target = stack_b;
				distance = travese_dist(top, target);
			}
			else
			{
				if (distance > travese_dist(top, stack_b))
				{
					distance = travese_dist(top, stack_b);
					target = stack_b;
				}
			}
		}
		stack_b = stack_b->next;
	}
	return (target);
}

void	easy_push_pivot(t_list **stack_a, t_list **stack_b,
		 t_list *pivot, t_list **left)
{
	int	(*decider)(t_list **, t_list **, int);
	int flag;

	if (check_pivot_in_b(*stack_b, pivot) == 0)
		return ;
	decider = 0;
	flag = 0;
	while (find_close_pivot(*stack_b, pivot) != 0)
	{
//		sleep(1);
//		ft_printf("left= %d\ntop= %d\nclose_pivot= %d\npivot= %d\n", *((int *)((*left)->content)), *((int *)((*stack_b)->content)),
//		 *((int *)(find_close_pivot(*stack_b, pivot)->content)), *((int *)pivot->content));
//		stack_display(*stack_a, *stack_b);
		decider = decide_rotate_b(*stack_b, find_close_pivot(*stack_b, pivot));
		if (find_close_pivot(*stack_b, pivot) != *stack_b)
		{
				if (decider == &op_rotate_b && flag == 0)
				{	
					flag = 1;
					*left = *stack_b;
				}
				decider(stack_a, stack_b, 1);
		}
		if (find_close_pivot(*stack_b, pivot) == *stack_b)		
			op_push_a(stack_a, stack_b, 1);
	}
	easy_rotate('b', stack_b, pivot, 1);
	op_push_a(stack_a, stack_b, 1);
}

t_list	*quicksort_partition(t_list **left, t_list **right,
		 t_list **stack_a, t_list **stack_b)
{
	t_list	*pivot;
	t_list	*new_left;
//	t_list	*before_easy;

	pivot = *left;
	if (!left || !right || !(*left) 
	|| !(*right) || *left == *right)
		return (pivot);
	while (check_pivot_in_b(*stack_b, pivot))
//	while (*stack_b)
		op_push_a(stack_a, stack_b, 1);
//	before_easy = *left;
//	easy_push_pivot(stack_a, stack_b, pivot, left);
	if (check_pivot(*left, *stack_a) == 1 && *stack_b == 0)
		return (pivot);
//	ft_printf("left= %d\nright= %d\n", *((int *)((*left)->content)), *((int *)((*right)->content)));
//	stack_display(*stack_a, *stack_b);
//	easy_rotate('a', stack_a, *left, 1);
//	op_rotate_a(stack_a, stack_b, 1);
	new_left = 0;
	while ((*stack_a) != *right && check_push_left(*stack_a, *right, pivot) != 0)
	{
		if (*((int *)((*stack_a)->content)) < *((int *)pivot->content))
		{
			op_push_b(stack_a, stack_b, 1);
			if (new_left == 0)
				new_left = (*stack_b);
		}
		else
			op_rotate_a(stack_a, stack_b, 1);
	}
	if (*((int *)((*stack_a)->content)) < *((int *)pivot->content))
	{
		op_push_b(stack_a, stack_b, 1);
		if (new_left == 0)
			new_left = (*stack_b);
	}
	*right = new_right(*stack_a, *right);
	easy_rotate('a', stack_a, pivot, 1);
//	while (*stack_b != 0)
//		op_push_a(stack_a, stack_b ,1);
	if (new_left == 0)
		*left = (*stack_a);
	else if (new_left != 0)
		*left = new_left;
	easy_rotate('a', stack_a, pivot, 1);
	return (pivot);
}

void	quicksort_main(t_list *left, t_list *right,
		 t_list **stack_a, t_list **stack_b)
{
	t_list		*pivot;
	t_list		*top;
	t_list		*bottom;

	if (!stack_a || !stack_b || !(*stack_a) 
	|| !left || !right || left == right)
		return ;
	if (check_stack_sorted(*stack_a, *stack_b))
		return ;
//	stack_display(*stack_a, *stack_b);
	pivot = quicksort_partition(&left, &right, stack_a, stack_b);
	if (pivot == 0)
		return ;
	top = left;
	(void)top;
	bottom = right;
//	ft_printf("left= %d\nright= %d\n", *((int *)(top->content)), *((int *)bottom->content));
//	sleep(1);
	quicksort_main(pivot->next, bottom, stack_a, stack_b);
//	quicksort_main(top, pivot, stack_a, stack_b);
}