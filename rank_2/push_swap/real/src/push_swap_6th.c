/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_6th.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:06:59 by srussame          #+#    #+#             */
/*   Updated: 2025/02/12 18:07:07 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_6th.h"

void		sixth_algor(t_list **stack_a, t_list **stack_b);

static int	check_correct_pos_sub1(t_list *before_target, t_list *after_target,
		t_list *target, t_list *top_stack)
{
	if (show_int(target) == low_num(top_stack)
		&& show_int(before_target) == high_num(top_stack))
		return (1);
	if (show_int(target) == high_num(top_stack))
		return (1);
	if (show_int(after_target) > show_int(target))
		return (1);
	return (0);
}

/*Function to check if the target in the stack is in the correct position */
int	check_correct_pos(t_list *top_stack, t_list *target)
{
	t_list	*before_target;
	t_list	*after_target;

	if (!top_stack || !target)
		return (0);
	before_target = top_stack;
	if (top_stack == target)
		before_target = ft_lstlast(top_stack);
	else
	{
		while (before_target->next != target)
			before_target = before_target->next;
	}
	after_target = top_stack;
	if (target->next)
		after_target = target->next;
	if (before_target == after_target || before_target == target
		|| after_target == target)
		return (1);
	return (check_correct_pos_sub1(before_target, after_target, target,
			top_stack));
}

/* find the number that is not in correct order*/
t_list	*find_unorder(t_list *top, t_list *stack)
{
	if (!stack)
		return (0);
	while (stack != 0)
	{
		if (check_correct_pos(top, stack) == 0)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

static int	unsorted_list_sub1(t_list *top, t_list ***real_point,
		t_list **fake_stack, t_list *stack_a)
{
	if (check_correct_pos(top, stack_a) == 0)
	{
		*real_point = (t_list **)malloc(sizeof(t_list *));
		if (*real_point == 0)
		{
			if (*fake_stack)
				ft_lstclear(fake_stack, &del_fake_content);
			return (0);
		}
		(*real_point)[0] = stack_a;
		ft_lstadd_back(fake_stack, ft_lstnew(&(*real_point)[0]));
		*real_point = NULL;
	}
	return (1);
}

/* create a unrelated fake stack to store all the unsorted
number on the stack
	** ALLOCATE MEM ** */
t_list	*unsorted_list(t_list *stack_a)
{
	t_list	**real_point;
	t_list	*fake_stack;
	t_list	*top;

	real_point = 0;
	fake_stack = 0;
	if (!stack_a)
		return (0);
	top = stack_a;
	while (stack_a)
	{
		//		if (check_correct_pos(top, stack_a) == 0)
		//		{
		//			real_point = (t_list **)malloc(sizeof(t_list *));
		//			if (real_point == 0)
		//			{
		//				if (fake_stack)
		//					ft_lstclear(&fake_stack, &del_fake_content);
		//				return (0);
		//			}
		//			real_point[0] = stack_a;
		//			ft_lstadd_back(&fake_stack, ft_lstnew(&real_point[0]));
		//			real_point = NULL;
		//		}
		if (unsorted_list_sub1(top, &real_point, &fake_stack, stack_a) == 0)
			return (stack_a = stack_a->next);
	}
	return (fake_stack);
}

/* Find the closest in unsorted list to move to the top of stack a
	return the target and free the fake list*/
t_list	*find_close_unsorted(t_list *top_stack_a, t_list **fake_list)
{
	t_list	*target;
	t_list	*fake_run;

	if (!top_stack_a || !fake_list || !(*fake_list))
		return (0);
	target = 0;
	fake_run = *fake_list;
	while (fake_run)
	{
		if (target == 0 || travese_dist(top_stack_a,
				(*((t_list **)(fake_run->content)))) < travese_dist(top_stack_a,
				target))
			target = *((t_list **)(fake_run->content));
		fake_run = fake_run->next;
	}
	ft_lstclear(fake_list, &del_fake_content);
	return (target);
}

/* find the closest number of the target_a in the stack */
t_list	*find_target_to_sort(t_list *stack, t_list *target_a)
{
	t_list	*point_sort;

	if (!stack || !target_a)
		return (0);
	point_sort = find_min_number(stack);
	if (low_num(stack) == show_int(target_a))
		return (find_max_number(stack));
	while (stack)
	{
		if ((show_int(stack) < show_int(target_a))
			&& (show_int(stack) > show_int(point_sort)))
			point_sort = stack;
		stack = stack->next;
	}
	return (point_sort);
}

/* find what number in stack b need to move to the top
	to correctly sorted when the target from stack a pushes
	to stack_b
	this function will be called from other function
	so doesn't need to check the arguments
	NOTE : the reason for this is for the case that if
	that unsorted number need only swap and dont need to push to stack b
	in that case this function will return NULL*/
t_list	*find_b(t_list *stack_a, t_list *stack_b, t_list *target_a)
{
	t_list	*target_b;

	if (target_a->next && find_target_to_sort(stack_a,
			target_a) == target_a->next)
		return (0);
	if (!target_a->next && find_target_to_sort(stack_a, target_a) == stack_a)
		return (0);
	target_b = find_min_number(stack_b);
	if (show_int(target_a) < show_int(target_b))
		return (find_max_number(stack_b));
	while (stack_b)
	{
		if (show_int(stack_b) < show_int(target_a)
			&& show_int(stack_b) > show_int(target_b))
			target_b = stack_b;
		stack_b = stack_b->next;
	}
	return (target_b);
}

/* return the amount of move from target_a to stack_b on correct order*/
int	cal_dist(t_list *stack_a, t_list *stack_b, t_list *target_a)
{
	if (!stack_a || !stack_b || !target_a)
		return (0);
	if (find_b(stack_a, stack_b, target_a) == 0)
		return (-1);
	return (traverse_dist_both(stack_a, target_a, stack_b, find_b(stack_a,
				stack_b, target_a)));
	//	op_a = decide_rotate_a(stack_a, target_a);
	//	op_b = decide_rotate_b(stack_b, find_b(stack_a, stack_b, target_a));
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

/* This function take the fake_list from 'unsorted_list' function
	return the target that has the lowest moves */
t_list	*find_least_move(t_list *stack_a, t_list *stack_b)
{
	t_list	*fake;
	t_list	*fake_list;
	t_list	*target;
	int		dist;

	if (!stack_a)
		return (0);
	fake_list = unsorted_list(stack_a);
	if (!fake_list)
		return (0);
	if (ft_lstsize(stack_b) < 2)
		return (find_close_unsorted(stack_a, &fake_list));
	fake = fake_list;
	target = 0;
	while (fake)
	{
		dist = cal_dist(stack_a, stack_b, *((t_list **)(fake->content)));
		if (dist != -1 && (target == 0 || dist < cal_dist(stack_a, stack_b,
					target)))
			target = *((t_list **)(fake->content));
		fake = fake->next;
	}
	ft_lstclear(&fake_list, &del_fake_content);
	return (target);
}

/* check if the top of stack_a is swap-able*/
int	check_swap(t_list *stack_a)
{
	if (!stack_a)
		return (0);
	if (ft_lstsize(stack_a) < 3)
		return (0);
	if (show_int(stack_a) == high_num(stack_a) && ft_lstsize(stack_a) >= 3
		&& stack_a->next && show_int(stack_a->next) == low_num(stack_a))
		return (0);
	if (show_int(stack_a) == low_num(stack_a) && ft_lstsize(stack_a) >= 3
		&& stack_a->next && show_int(stack_a->next) == high_num(stack_a))
		return (1);
	if (find_target_to_sort(stack_a, stack_a) == stack_a->next)
		return (1);
	return (0);
}

/* find the closest lower number in order in stack_a*/

t_list	*find_close_order(t_list *stack_a, t_list *top_b, t_list *high_num,
		t_list *low_num)
{
	t_list	*result;
	t_list	*top_a;

	if (!stack_a || !top_b)
		return (0);
	result = 0;
	if (show_int(top_b) == show_int(high_num))
		return (low_num);
	top_a = stack_a;
	while (stack_a)
	{
		if ((check_correct_pos(top_a, stack_a) == 1)
			&& show_int(stack_a) > show_int(top_b))
		{
			if (result == 0)
				result = stack_a;
			if (show_int(result) > show_int(stack_a))
				result = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (result);
}

void	one_move_op(t_list **stack_a, t_list **stack_b, t_list *target_push_b,
		t_list *move_b)
{
	int	(*op_a)(t_list **, t_list **, int);
	int	(*op_b)(t_list **, t_list **, int);

	op_a = 0;
	op_b = 0;
	if (*stack_a != target_push_b)
		op_a = decide_rotate_a(*stack_a, target_push_b);
	if (*stack_b != move_b)
		op_b = decide_rotate_b(*stack_b, move_b);
	if ((op_b == &op_rotate_b && op_a == &op_rotate_a) || (op_b == &op_reverse_b
			&& op_a == &op_reverse_a))
	{
		if (op_b == &op_rotate_b)
			op_rotate_all(stack_a, stack_b, 1);
		if (op_b == &op_reverse_b)
			op_reverse_all(stack_a, stack_b, 1);
		return ;
	}
	if (op_b)
		op_b(stack_a, stack_b, 1);
	if (op_a)
		op_a(stack_a, stack_b, 1);
	return ;
}

void	one_move_op_all(t_list **stack_a, t_list **stack_b, t_list *target_a,
		t_list *target_b)
{
	int	result[3];

	if (!stack_a || !stack_b || !target_a || !target_b)
		return ;
	result[0] = trav_top(*stack_a, target_a);
	if (trav_top(*stack_b, target_b) > result[0])
		result[0] = trav_top(*stack_b, target_b);
	result[1] = trav_bot(*stack_a, target_a);
	if (trav_bot(*stack_b, target_b) > result[1])
		result[1] = trav_bot(*stack_b, target_b);
	result[2] = travese_dist(*stack_a, target_a) + travese_dist(*stack_b,
			target_b);
	if (result[0] < result[1] && result[0] < result[2])
	{
		if (*stack_a != target_a && *stack_b != target_b)
			op_rotate_all(stack_a, stack_b, 1);
		else if (*stack_a != target_a && *stack_b == target_b)
			op_rotate_a(stack_a, stack_b, 1);
		else if (*stack_a == target_a && *stack_b != target_b)
			op_rotate_b(stack_a, stack_b, 1);
		return ;
	}
	if (result[1] < result[0] && result[1] < result[2])
	{
		if (*stack_a != target_a && *stack_b != target_b)
			op_reverse_all(stack_a, stack_b, 1);
		else if (*stack_a != target_a && *stack_b == target_b)
			op_reverse_a(stack_a, stack_b, 1);
		else if (*stack_a == target_a && *stack_b != target_b)
			op_reverse_b(stack_a, stack_b, 1);
		return ;
	}
	one_move_op(stack_a, stack_b, target_a, target_b);
}

/* Each iteration of this sorting algorithm
	check many conditions
	one iteration will return 1 if ends in push or swap
		and will return 0 if ends with no swap or push */
int	sort_iter(t_list **stack_a, t_list **stack_b)
{
	t_list	*target_push_b;
	t_list	*move_b;

	if (!stack_a || !(*stack_a) || !stack_b)
		return (0);
	if (!find_unorder(*stack_a, *stack_a))
		return (0);
	if (check_swap(*stack_a) == 1)
	{
		op_swap_a(stack_a, stack_b, 1);
		return (1);
	}
	target_push_b = find_least_move(*stack_a, *stack_b);
	move_b = 0;
	if (target_push_b)
		move_b = find_b(*stack_a, *stack_b, target_push_b);
	if (move_b == 0)
	{
		if (target_push_b != *stack_a)
			decide_rotate_a(*stack_a, target_push_b)(stack_a, stack_b, 1);
		else if (target_push_b == *stack_a)
			op_push_b(stack_a, stack_b, 1);
		return (1);
	}
	if (target_push_b == *stack_a && move_b == *stack_b)
	{
		op_push_b(stack_a, stack_b, 1);
		return (1);
	}
	one_move_op_all(stack_a, stack_b, target_push_b, move_b);
	return (1);
}

/* find closest higher number on stack a*/
t_list	*find_closest(t_list *target, t_list *stack)
{
	t_list	*result;

	if (!stack || !target)
		return (0);
	if (show_int(target) >= high_num(stack))
		return (find_min_number(stack));
	result = find_max_number(stack);
	while (stack)
	{
		if (show_int(stack) > show_int(target)
			&& show_int(stack) < show_int(result))
			result = stack;
		stack = stack->next;
	}
	return (result);
}

/* find if the closest higher number in on both if not
	return NULL*/
t_list	*find_closest_on_both(t_list *stack_a, t_list *stack_b, t_list *target)
{
	t_list	*result_a;
	t_list	*result_b;

	if (!stack_a || !stack_b || !target)
		return (0);
	result_a = find_closest(target, stack_a);
	result_b = find_closest(target, stack_b);
	if (show_int(result_b) == low_num(stack_b))
		return (result_a);
	if (result_b && result_a && show_int(result_b) < show_int(result_a))
		return (0);
	return (result_a);
}

/* return the posotion in b so that stack b will move the shortest path */
t_list	*find_few(t_list *stack_a, t_list *stack_b)
{
	t_list	*result;
	t_list	*temp[2];
	t_list	*top_b;

	if (!stack_a || !stack_b)
		return (0);
	result = 0;
	top_b = stack_b;
	while (stack_b)
	{
		temp[0] = 0;
		temp[1] = 0;
		temp[0] = find_closest_on_both(stack_a, top_b, stack_b);
		temp[1] = find_closest_on_both(stack_a, top_b, result);
		if (temp[0] && result == 0)
			result = stack_b;
		if (temp[0] && temp[1] && result)
		{
			if (traverse_dist_both(stack_a, temp[0], top_b,
					stack_b) < traverse_dist_both(stack_a, temp[1], top_b,
					result))
				result = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (result);
}

/* This algorrithm I bring the good techniques from my previous algorithm
	The big difference is that this one will not push the whole stack to
	the temporary stack. It will push only the element that is unsorted in
	main stack. In the meantime also push number back to main stack in correct
	possition if posible */
void	sixth_algor(t_list **stack_a, t_list **stack_b)
{
	t_list *move_b;
	t_list *min;

	if (!stack_a || !stack_b || !(*stack_a) || check_stack_sorted(*stack_a))
		return ;
	min = find_min_number(*stack_a);
	while (1)
	{
		if (sort_iter(stack_a, stack_b) == 0)
			break ;
	}
	while (*stack_b)
	{
		move_b = find_few(*stack_a, *stack_b);
		easy_rotate_all(stack_a, stack_b, find_closest(move_b, *stack_a),
			move_b);
		op_push_a(stack_a, stack_b, 1);
	}
	easy_rotate('a', stack_a, min, 1);
	return ;
}