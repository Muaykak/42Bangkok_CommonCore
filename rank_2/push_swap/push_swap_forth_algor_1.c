/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_forth_algor_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:54 by srussame          #+#    #+#             */
/*   Updated: 2025/01/27 15:03:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_forth_algor.h"

void	cost_algor(t_list **stack_a, t_list **stack_b);

t_list	*copy_to_fake(t_list *stack_a)
{
	t_list **real_point;
	t_list *fake_stack;

	real_point = 0;
	fake_stack = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		real_point = (t_list **)malloc(sizeof(t_list *));
		if (real_point == 0)
			return (0);
		real_point[0] = stack_a;
		ft_lstadd_back(&fake_stack, ft_lstnew(&real_point[0]));
		real_point = NULL;
		stack_a = stack_a->next;
	}
	return (fake_stack);
	
}

/* show the integer of the value that fake list content it points to*/
int	show_fake_int(t_list *fake_list)
{
	return (*((int *)((*((t_list **)(fake_list->content)))->content)));
}

/* This function is to display the fake stack*/
void	display_fake_stack(t_list *fake_list)
{
	if (!fake_list)
		return ;
	ft_printf("fake: {");
	while (fake_list)
	{
		ft_printf("%d", show_fake_int(fake_list));
		if (fake_list->next != 0)
			ft_printf(", ");
		fake_list = fake_list->next;
	}
	ft_printf("}\n");
}

t_list	*fake_pivot_partition(t_list *fake_head, t_list *fake_tail)
{
	t_list	*pivot;
	t_list	*pre;
	t_list	*curr;
	t_list	*temp;

	pivot = fake_head;
	pre = fake_head;
	curr = fake_head;
	while (curr != fake_tail->next)
	{
		temp = 0;
		if (show_fake_int(curr) < show_fake_int(pivot))
		{
			temp = (t_list *)curr->content;
			curr->content = pre->next->content;
			pre->next->content = temp;
			pre = pre->next;
		}
		curr = curr->next;
	}
	temp = (t_list *)pivot->content;
	pivot->content = (t_list *)pre->content;
	pre->content = (t_list *)temp;
	return (pre);
}

/* use quicksort algorithm to sort the fake_list*/
void	fake_quicksort_sub(t_list *fake_head, t_list *fake_tail)
{
	t_list	*pivot;

	if (!fake_head|| !fake_tail || fake_head == fake_tail)
		return ;
	pivot = fake_pivot_partition(fake_head, fake_tail);
	fake_quicksort_sub(fake_head, pivot);
	fake_quicksort_sub(pivot->next, fake_tail);
}

/* main function of fake quicksort */
t_list	*fake_quicksort(t_list *fake_head)
{
	t_list	*fake_tail;

	fake_tail = ft_lstlast(fake_head);
	fake_quicksort_sub(fake_head, fake_tail);
	return (fake_head);
}

/* free the content in fake_list*/
void	del_fake_content(void *content)
{
	if (content != NULL)
		free(content);
}

/* remove the target content inside the list*/
void	remove_lst_one(t_list **top, t_list *target)
{
	t_list	*head;

	if (!top || !(*top) || !target)
		return ;
	if (target == *top)
	{
		*top = (*top)->next;
		ft_lstdelone(target, &del_fake_content);
		return ;
	}
	head = *top;
	while (*top != 0 && (*top)->next != target)
	{
		*top = (*top)->next;
	}
	if ((*top) == 0)
	{
		*top = head;
		return ;
	}
	(*top)->next = target->next;
	ft_lstdelone(target, &del_fake_content);
	*top = head;
}

/* clear all the sorted fake_list and leave only the last number of each chunk
	(highest number on each chunk) the chunk separated by the 
	CHUNK_SIZE which is defined is the header file */
t_list *chunk_fakelist(t_list **fake_list)
{
	int		chunk_value;
	int		i;
	t_list	*temp;
	t_list	*temp_2;

	if (!fake_list || !(*fake_list))
		return (0);
	if (CHUNK_SIZE >= ft_lstsize(*fake_list))
		return (*fake_list);
	chunk_value = ft_lstsize(*fake_list) / CHUNK_SIZE;
	temp = *fake_list;
	while (temp != 0)
	{
		i = 1;
		while (i < chunk_value && temp->next != 0)
		{
			temp_2 = temp->next;
			remove_lst_one(fake_list, temp);
			temp = temp_2;
			i++;
		}
		temp = temp->next;
	}
	return (*fake_list);
}

/* move all number that need to sort to stack_b until 
	there is only 1 element left */
int	move_to_b(t_list **stack_a, t_list **stack_b,
	 t_list *fake_list)
{
	int		i;
	int		cost;
	t_list	*top;
	t_list	*target;

	if (!stack_a || !stack_b || !(*stack_a) || !fake_list)
		return (0);
	if (ft_lstsize(*stack_a) < 2)
		return (0);
	top = *stack_a;
	cost = -1;
	i = show_int(find_min_number(*stack_a));
	while(fake_list != 0 && show_fake_int(fake_list) <= i)
		fake_list = fake_list->next;
	while (*stack_a != 0 && fake_list != 0)
	{
		if (show_int(*stack_a) < show_fake_int(fake_list)
		&& (cost == -1 || travese_dist(top, *stack_a) < cost))
		{
			target = *stack_a;
			cost = travese_dist(top, *stack_a);
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = top;
	if (cost == -1)
		return (0);
	while (*stack_a != target)
		(decide_rotate_a(*stack_a, target))(stack_a, stack_b ,1);
	op_push_b(stack_a, stack_b, 1);
	return (1);
}

/* find closest value number on stack a*/
t_list	*find_closest_value(t_list *stack_a, t_list *to_find)
{
	t_list	*target;

	if (!stack_a || !to_find)
		return (0);
	target = 0;
	while (stack_a != 0)
	{
		if (show_int(stack_a) >= show_int(to_find))
		{
			if (target == 0)
				target = stack_a;
			else if (target != 0 && show_int(stack_a) < show_int(target))
				target = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (target);
}

/* calculate the distance from a list in stack b to move and push to stack a with
	correct order. if both stack a and stack b use the similar operation
	like 'rotate' or 'reverse rotate' it considers both stacks move at the same time
	using 'rr' or 'rrr' */
int	to_a_dist(t_list *stack_a, t_list *stack_b, t_list *to_move_b)
{
	int	distance_a;
	int	distance_b;
	int	(*op_a)(t_list **, t_list **, int);
	int	(*op_b)(t_list **, t_list **, int);

	if (!stack_a || !stack_b || !to_move_b)
		return (0);
	distance_a = travese_dist(stack_a, find_closest_value(stack_a, to_move_b));
	distance_b = travese_dist(stack_b, to_move_b);
	op_a = decide_rotate_a(stack_a, find_closest_value(stack_a, to_move_b));
	op_b = decide_rotate_b(stack_b, to_move_b);
	if ((op_a == &op_rotate_a && op_b == &op_rotate_b) 
	|| (op_a == &op_reverse_a && op_b == &op_reverse_b))
	{
		if (distance_a < distance_b)
			return (distance_b);
		else
			return (distance_a);
	}
	return (distance_a + distance_b);
}

/* check if target is in the range*/
int	in_range(t_list *stack_b, t_list *target, t_list **fake_list)
{
	int		min;
	int		max;
	t_list	*top;

	if (!target || !fake_list || !stack_b || !(*fake_list))
		return (0);
	if ((*fake_list)->next == 0)
	{
		min = show_int(find_min_number(stack_b));
		max = show_fake_int(*fake_list);
		if (show_int(target) >= min && show_int(target) <= max)
			return (1);
		return (0);
	}
	top = *fake_list;
	while ((*fake_list)->next->next != 0)
		*fake_list = (*fake_list)->next;
	min = show_fake_int(*fake_list);
	max = show_fake_int((*fake_list)->next);
	*fake_list = top;
		if (show_int(target) >= min && show_int(target) <= max)
			return (1);
		return (0);
}

/* find the number on the list of stack_b 
	that has the lowest possible moves to push to stack a*/
t_list	*find_to_push_a(t_list *stack_a, t_list *stack_b, t_list **fake_list)
{
	t_list	*target;
	t_list	*top;

	if (!stack_a || !stack_b)
		return (0);
	target = 0;
	top = stack_b;
	while (stack_b != 0)
	{
		if (in_range(top, stack_b, fake_list) && target == 0)
			target = stack_b;
		else if (in_range(top, stack_b, fake_list) && target != 0 &&
		 to_a_dist(stack_a, top, stack_b) < to_a_dist(stack_a, top, target))
		 	target = stack_b;
		stack_b = stack_b->next;
	}
	if (target == 0)
		remove_lst_one(fake_list, ft_lstlast(*fake_list));
	return (target);
}

/* this algorithm cares about the cost of rotating around*/
void	cost_algor(t_list **stack_a, t_list **stack_b)
{
	t_list	*fake_a;
	t_list	*closest_value;
	t_list	*to_push_a;
	
	if (!stack_a || !(*stack_a))
		return ;
	fake_a = fake_quicksort(copy_to_fake(*stack_a));
	chunk_fakelist(&fake_a);
//	(void)fake_a;
	while (ft_lstsize(*stack_a) > 2)
	{
		if (move_to_b(stack_a, stack_b, fake_a) == 0)
			break ;
	}
//	while (ft_lstsize(*stack_a) > 2)
//	{
//		if (show_int(*stack_a) == high_num(*stack_a))
//			op_rotate_a(stack_a, stack_b, 1);
//		else
//			op_push_b(stack_a, stack_b, 1);
//	}
	if (ft_lstsize(*stack_a) == 2 
	&& show_int(*stack_a) > show_int((*stack_a)->next))
		op_rotate_a(stack_a, stack_b, 1);
	while (*stack_b != 0)
	{
		to_push_a = find_to_push_a(*stack_a, *stack_b, &fake_a);
		if (to_push_a)
		{
			closest_value = find_closest_value(*stack_a, to_push_a);
			easy_rotate_both(stack_a, stack_b, closest_value, to_push_a);
			op_push_a(stack_a, stack_b, 1);
		}
	}
	ft_lstclear(&fake_a, &del_fake_content);
	easy_rotate('a', stack_a, find_min_number(*stack_a), 1);
}

//void fifth_algor(t_list	**stack_a, t_list *stack_b)
//{
//	t_list	*fake_a;
//
//	if (!stack_a || !(*stack_a) || !stack_b)
//		return ;
//	fake_a = fake_quicksort(*stack_a);
//
//}