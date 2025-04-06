/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:50:53 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 19:50:55 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_stacks_sub1(t_ps_node **runner_a, t_ps_node **runner_b,
				t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	*runner_a = stack_a->top;
	*runner_b = stack_b->top;
	ft_printf("stack_a\t\tstack_b\n");
	if (*runner_a != NULL)
		ft_printf("%d[%d]", (*runner_a)->number, (*runner_a)->sort_pos);
	ft_printf("\t");
	if (*runner_b != NULL)
		ft_printf("\t%d[%d]", (*runner_b)->number, (*runner_b)->sort_pos);
	ft_printf("\n");
}

void	display_stacks(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	t_ps_node	*runner_a;
	t_ps_node	*runner_b;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	display_stacks_sub1(&runner_a, &runner_b, stack_a, stack_b);
	while ((runner_a != NULL && runner_a->next != stack_a->top)
		|| (runner_b != NULL && runner_b->next != stack_b->top))
	{
		if (runner_a != NULL && runner_a->next != stack_a->top)
		{
			runner_a = runner_a->next;
			ft_printf("%d[%d]", runner_a->number, runner_a->sort_pos);
		}
		ft_printf("\t");
		if (runner_b != NULL && runner_b->next != stack_b->top)
		{
			runner_b = runner_b->next;
			ft_printf("\t%d[%d]", runner_b->number, runner_b->sort_pos);
		}
		ft_printf("\n");
	}
}
