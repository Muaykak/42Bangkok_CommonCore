/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5th.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:59:33 by srussame          #+#    #+#             */
/*   Updated: 2025/02/06 15:59:36 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_5th.h"

void	fifth_algor(t_list **stack_a, t_list **stack_b);

/* find closest value number on stack b*/
t_list	*find_closest_value_b(t_list *stack_b, t_list *to_find, t_list *lowest)
{
	t_list	*target;

	if (!stack_b || !to_find || !lowest)
		return (0);
	target = 0;
	(void)lowest;
	if (show_int(to_find) < low_num(stack_b))
		return (find_max_number(stack_b));
	while (stack_b != 0)
	{
		if (show_int(stack_b) < show_int(to_find))
		{
			if (target == 0)
				target = stack_b;
			else if (target != 0 && show_int(stack_b) > show_int(target))
				target = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (target);
}

/* calculate the distance from a list in stack a to move and push to stack b with
	correct order. if both stack a and stack b use the similar operation
	like 'rotate' or 'reverse rotate' it considers both stacks move at the same time
	using 'rr' or 'rrr' */
int	to_b_dist(t_list *stack_a, t_list *stack_b, t_list *to_move_a, t_list *lowest)
{
	if (!stack_a || !stack_b || !to_move_a || !lowest)
		return (0);
	return (traverse_dist_both(stack_a, to_move_a,
	 stack_b, find_closest_value_b(stack_b, to_move_a, lowest)));
//	op_a = decide_rotate_a(stack_a, to_move_a);
//	op_b = decide_rotate_b(stack_b, find_closest_value_b(stack_b, to_move_a, lowest));
//	if ((op_a == &op_rotate_a && op_b == &op_rotate_b) 
//	|| (op_a == &op_reverse_a && op_b == &op_reverse_b))
//	{
//		if (distance_a < distance_b)
//			return (distance_b);
//		else
//			return (distance_a);
//	}
//	return (distance_a + distance_b);
}

/* find the number on the list of stack_a 
	that has the lowest possible moves to push to stack b*/
t_list	*find_to_push_b(t_list *stack_a, t_list *stack_b, t_list *lowest)
{
	t_list	*target;
	t_list	*top;

	if (!stack_a || !stack_b || !lowest)
		return (0);
	target = 0;
	top = stack_a;
	while (stack_a != 0)
	{
		if (target == 0)
			target = stack_a;
		else if (target != 0 &&
		 to_b_dist(top, stack_b, stack_a, lowest) < to_b_dist(top, stack_b, target, lowest))
		 	target = stack_a;
		stack_a = stack_a->next;
	}
	return (target);
}

/*this algorithm use to sort small numbers less or equal 100 numbers*/
void	fifth_algor(t_list **stack_a, t_list **stack_b)
{
	t_list	*closest_value;
	t_list	*to_push_b;
	t_list	*lowest;

	if (!stack_a || !stack_b || !(*stack_a) 
	|| check_stack_sorted(*stack_a, *stack_b))
		return ;
	lowest = find_min_number(*stack_a);
	while(*stack_a && ft_lstsize(*stack_b) < 2)
		op_push_b(stack_a, stack_b , 1);
	if (ft_lstsize(*stack_b) == 2 
	&& show_int(*stack_b) < show_int((*stack_b)->next))
		op_rotate_b(stack_a, stack_b, 1);
	while (*stack_a != 0)
	{
		to_push_b = find_to_push_b(*stack_a, *stack_b, lowest);
		if (to_push_b)
		{
			closest_value = find_closest_value_b(*stack_b, to_push_b, lowest);
			easy_rotate_all(stack_a, stack_b, to_push_b, closest_value);
			op_push_b(stack_a, stack_b, 1);
		}
	}
	easy_rotate('b', stack_b, find_max_number(*stack_b), 1);
	while (*stack_b != 0)
		op_push_a(stack_a, stack_b, 1);
}
