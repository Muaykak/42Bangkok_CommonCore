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

int				move_to_b(t_list **stack_a, t_list **stack_b,
					t_list *fake_list);
t_list			*find_closest_value(t_list *stack_a, t_list *to_find);

static t_list	*move_to_b_sub1(t_list *stack_a, t_list *fake_list)
{
	t_list	*target;
	t_list	*top;
	t_list	*temp;

	top = stack_a;
	target = 0;
	while (fake_list != 0 && show_fake_int(fake_list) <= low_num(stack_a))
		fake_list = fake_list->next;
	if (fake_list->next == 0)
		temp = fake_list;
	else
		temp = fake_list->next;
	while (stack_a != 0 && temp != 0)
	{
		if (show_int(stack_a) < show_fake_int(temp)
			&& (target == 0 || travese_dist(top, stack_a)
				< travese_dist(top, target)))
			target = stack_a;
		stack_a = (stack_a)->next;
	}
	return (target);
}

/* move all number that need to sort to stack_b until 
	there is only 1 element left */
int	move_to_b(t_list **stack_a, t_list **stack_b,
	t_list *fake_list)
{
	t_list	*target;

	if (!stack_a || !stack_b || !(*stack_a) || !fake_list)
		return (0);
	if (ft_lstsize(*stack_a) < 2)
		return (0);
	target = move_to_b_sub1(*stack_a, fake_list);
	if (target == 0)
		return (0);
	if (target != *stack_a && decide_rotate_a(*stack_a, target) == &op_rotate_a
		&& ft_lstsize(*stack_b) >= 2
		&& show_int(*stack_b) < show_fake_int(fake_list))
		op_rotate_all(stack_a, stack_b, 1);
	else if (ft_lstsize(*stack_b) >= 2
		&& show_int(*stack_b) < show_fake_int(fake_list))
		op_rotate_b(stack_a, stack_b, 1);
	easy_rotate('a', stack_a, target, 1);
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
