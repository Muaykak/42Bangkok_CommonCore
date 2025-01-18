/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_my_algor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:21:27 by srussame          #+#    #+#             */
/*   Updated: 2025/01/18 11:21:29 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_my_algor.h"

int		*check_stack_min_max(t_list *stack, int *num);
int		check_correct_order(t_list *stack_a, int min, int max);
void	my_algor_execute(t_list **stack_a, t_list **stack_b);

/* main function that execute function to the stack*/
void	my_algor_execute(t_list **stack_a, t_list **stack_b)
{
	int		minmax[2];

	if (check_stack_sorted(*stack_a, *stack_b) == 1)
		return ;
	check_stack_min_max(*stack_a, minmax);
	while (check_correct_order(*stack_a, minmax[0], minmax[1]) != 1)
	{
		sorting_stack(stack_a, stack_b, minmax[0], minmax[1]);
		op_handler(stack_a, stack_b, &op_rotate_a, PRINT_OP);
	}
	while (check_stack_sorted(*stack_a, *stack_b) != 1)
		op_handler(stack_a, stack_b, &op_rotate_a, PRINT_OP);
	return	;
}

/* Check if the stack is in the correct order evern if
	not in the right position
	Example :  {5, 1, 2, 3, 4} 	is in correct order*/
int		check_correct_order(t_list *stack_a, int min, int max)
{
	int 	state;

	state = 0;
	while (stack_a->next != 0)
	{
		if (((int *)stack_a->content)[0] == min)
			state = 0;
		else if (((int *)stack_a->content)[0] == max)
			state = 1;
		if (state == 0)
		{
			if (((int *)stack_a->content)[0] > \
			(((int *)stack_a->next->content))[0])
				return (0);
		}
		else if (state == 1)
		{
			if (((int *)stack_a->content)[0] < \
			(((int *)stack_a->next->content))[0])
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

/*First function is to run through the whole stack to see min and max number*/
int	*check_stack_min_max(t_list *stack, int *num)
{

	if (stack == 0)
	{
		num[0] = 0;
		num[1] = 0;
		return (num);
	}
	num[0] = ((int *)stack->content)[0];
	num[1] = ((int *)stack->content)[0];
	while (stack != 0)
	{
		if (((int *)stack->content)[0] <= num[0])
			num[0] = ((int *)stack->content)[0];
		if (((int *)stack->content)[0] >= num[1])
			num[1] = ((int *)stack->content)[0];
		stack = stack->next;
	}
	return (num);
}
