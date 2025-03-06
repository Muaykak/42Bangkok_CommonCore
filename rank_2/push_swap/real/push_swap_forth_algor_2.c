/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_forth_algor_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:01:30 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 21:01:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_forth_algor.h"

void		cost_algor(t_list **stack_a, t_list **stack_b);
t_list		*find_to_push_a(t_list *stack_a, t_list *stack_b,
				t_list **fake_list);
int			in_range(t_list *stack_b, t_list *target, t_list **fake_list);
int			to_a_dist(t_list *stack_a, t_list *stack_b, t_list *to_move_b);

static void	cost_algor_sub1(t_list **stack_a, t_list **stack_b,
				t_list **fake_a);

/* calculate the distance from a list in stack b to move and push 
	to stack a with
	correct order. if both stack a and stack b use the similar operation
	like 'rotate' or 'reverse rotate' it considers both stacks move at
	the same time
	using 'rr' or 'rrr' */
int	to_a_dist(t_list *stack_a, t_list *stack_b, t_list *to_move_b)
{
	if (!stack_a || !stack_b || !to_move_b)
		return (0);
	return (traverse_dist_both(stack_a,
			find_closest_value(stack_a, to_move_b), stack_b, to_move_b));
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
		else if (in_range(top, stack_b, fake_list) && target != 0
			&& to_a_dist(stack_a, top, stack_b)
			< to_a_dist(stack_a, top, target))
			target = stack_b;
		stack_b = stack_b->next;
	}
	if (target == 0)
		remove_lst_one(fake_list, ft_lstlast(*fake_list));
	return (target);
}

static void	cost_algor_sub1(t_list **stack_a, t_list **stack_b,
			t_list **fake_a)
{
	*fake_a = fake_quicksort(copy_to_fake(*stack_a));
	chunk_fakelist(fake_a, CHUNK_SIZE);
	while (ft_lstsize(*stack_a) > 2)
	{
		if (move_to_b(stack_a, stack_b, *fake_a) == 0)
			break ;
	}
	if (ft_lstsize(*stack_a) == 2
		&& show_int(*stack_a) > show_int((*stack_a)->next))
		op_rotate_a(stack_a, stack_b, 1);
}

/* this algorithm cares about the cost of rotating around*/
void	cost_algor(t_list **stack_a, t_list **stack_b)
{
	t_list	*fake_a;
	t_list	*closest_value;
	t_list	*to_push_a;

	if (!stack_a || !(*stack_a))
		return ;
	cost_algor_sub1(stack_a, stack_b, &fake_a);
	while (*stack_b != 0)
	{
		to_push_a = find_to_push_a(*stack_a, *stack_b, &fake_a);
		if (to_push_a)
		{
			closest_value = find_closest_value(*stack_a, to_push_a);
			easy_rotate_all(stack_a, stack_b, closest_value, to_push_a);
			op_push_a(stack_a, stack_b, 1);
		}
	}
	ft_lstclear(&fake_a, &del_fake_content);
	easy_rotate('a', stack_a, find_min_number(*stack_a), 1);
}
