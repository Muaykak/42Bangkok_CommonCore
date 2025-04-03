/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_algor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:19:39 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 15:19:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*stack_a_decider(t_ps_stack *stack_a))(t_ps_stack *, t_ps_stack *);
void	(*stack_b_decider(t_ps_stack *stack_b))(t_ps_stack *, t_ps_stack *);
int		sort_iter(t_ps_stack *stack_a, t_ps_stack *stack_b);

void	first_algor(t_ps_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	if (check_stack_asc_sorted(stack_a) == 1)
	{
		easy_rotate(stack_a->stack_min);
		return ;
	}
	while (1)
	{
		if (sort_iter(stack_a, stack_a->link) == 0)
			break ;
	}
	easy_rotate(stack_a->stack_min);
	return ;
}

int	sort_iter(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	void	(*stack_a_op)(t_ps_stack *, t_ps_stack *);
	void	(*stack_b_op)(t_ps_stack *, t_ps_stack *);

	if (stack_a->sorted == TRUE && stack_b->size <= 0)
		return (0);
	stack_a_op = stack_a_decider(stack_a);
	stack_b_op = stack_b_decider(stack_b);
	if (stack_a_op == NULL && stack_b_op == NULL)
	{
		return (0);
	}
	if (stack_a_op != NULL && stack_b_op == NULL)
	{

		return (stack_a_op(stack_a, stack_b), 1);
	}
	if (stack_b_op != NULL && stack_a_op == NULL)
		return (stack_b_op(stack_a, stack_b), 1);
	if (stack_a_op == &op_sa && stack_b_op == &op_sb)
		return (op_ss(stack_a, stack_b), 1);
	if (stack_a_op == &op_ra && stack_b_op == &op_rb)
		return (op_rr(stack_a, stack_b), 1);
	if (stack_a_op == &op_rra && stack_b_op == &op_rrb)
		return (op_rrr(stack_a, stack_b), 1);
	if (stack_a_op == &op_sa && stack_b_op == &op_ra && stack_b_op == &op_rra)
		return (op_sa(stack_a, stack_b), 1);
	if (stack_b_op == &op_sb && stack_a_op == &op_pb)
		return (op_sb(stack_a, stack_b), 1);
	if (stack_b_op == &op_pa)
		return (op_pa(stack_a, stack_b), 1);
	if (stack_a_op == &op_pb)
		return (op_pb(stack_a, stack_b), 1);
	if ((stack_b_op == &op_rra && stack_a_op != &op_rra)
		|| (stack_b_op == &op_ra && stack_a_op != &op_ra))
		return (stack_a_op(stack_a, stack_b), 1);
	return (stack_a_op(stack_a, stack_b), stack_b_op(stack_a, stack_b), 1);
}

void	(*stack_a_decider(t_ps_stack *stack_a))(t_ps_stack *, t_ps_stack *)
{
	t_ps_node	*to_push_b;
	t_ps_node	*to_swap;

	if (stack_a == NULL || stack_a->size < 3 || stack_a->sorted == TRUE)
	{
		return (NULL);
	}
	if (stack_a->top->swap_top == TRUE)
	{
		return (&op_sa);
	}
	to_push_b = find_closest_to_push_b(stack_a);
	if (to_push_b != NULL)
	{
		if (to_push_b == stack_a->top)
		{
			return (&op_pb);
		}
		else
		{
			return (rotate_decider(to_push_b));
		}
	}
	to_swap = find_closest_to_swap(stack_a);
	if (to_swap != NULL)
		return (rotate_decider(to_swap));
	return (NULL);
}

void	(*stack_b_decider(t_ps_stack *stack_b))(t_ps_stack *, t_ps_stack *)
{
	t_ps_node	*target_b;
	t_ps_node	*target_in_a;

	if (stack_b == NULL || stack_b->size <= 0)
		return (NULL);
	if (stack_b->top->swap_top == TRUE)
		return (&op_sb);
	target_b = find_closest_to_push_a(stack_b);
	if (target_b == NULL)
	{
		if (stack_b->sorted == TRUE)
			return (NULL);
		return (rotate_decider(find_closest_to_swap(stack_b)));
	}
	target_in_a = find_target_in_a(target_b);
	if (target_in_a == NULL)
		return (NULL);
	if (target_b == stack_b->top && target_in_a == target_in_a->stack->top)
	{
		return (&op_pa);
	}
	if (target_b == stack_b->top && target_in_a != target_in_a->stack->top)
		return (rotate_decider(target_in_a));
	return (rotate_decider(target_b));
}
