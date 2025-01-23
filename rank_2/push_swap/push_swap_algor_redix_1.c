/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algor_redix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:01:42 by srussame          #+#    #+#             */
/*   Updated: 2025/01/19 16:01:43 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_algor_redix.h"

int		number_digit(t_list *target, unsigned long digit);
t_list	*find_num_digit_high(t_list *stack, int find_num, unsigned long digit);
t_list	*find_num_digit_low(t_list *stack, int find_num, unsigned long digit);
void	redix_algor_sort(t_list	**stack_a, t_list **stack_b);
t_list	*find_min_number(t_list *stack);
int		cut_number(t_list *stack, unsigned long digit);

int		check_stack_sort_unsigned(t_list *stack);

void	redix_algor_sort(t_list	**stack_a, t_list **stack_b)
{
	unsigned long	digit;
	int				max;
	int				number;
	t_list			*target;

	digit = 1;
	max = max_number(*stack_a);
	while (digit <= (unsigned long)ft_abs(max) && check_stack_sort_unsigned(*stack_a) != 1)
	{
//		ft_printf("digit=%d\n", (int)digit);
//		stack_display(*stack_a, *stack_b);
		if ((*stack_a) != 0)
		{
			number = 0;
			while (number < 10)
			{
				target = find_num_digit_low(*stack_a, number, digit);
				while (target != NULL)
				{
					easy_rotate('a', stack_a, target);
					op_handler(stack_a, stack_b, "pb");
					target = find_num_digit_low(*stack_a, number, digit);
				}
				number++;
			}
		}
		else
		{
			number = 9;
			while (number >= 0)
			{
				target = find_num_digit_high(*stack_b, number, digit);
				while (target != NULL)
				{
					easy_rotate('b', stack_b, target);
					op_handler(stack_a, stack_b, "pa");
					target = find_num_digit_high(*stack_b, number, digit);
				}
				number--;
			}
		}
//		stack_display(*stack_a, *stack_b);
		digit = digit * 10;
	}
	if (*stack_a == 0)
		while (*stack_b != 0)
			op_handler(stack_a, stack_b, "pa");
	if (check_stack_sorted(*stack_a, *stack_b) == 1)
		return ;
	target = find_min_number(*stack_a);
	while (target != 0 && ((int *)target->content)[0] < 0)
	{
		easy_rotate('a', stack_a, target);
		op_handler(stack_a, stack_b, "pb");
		target = find_min_number(*stack_a);
	}
	easy_rotate('a', stack_a, find_min_number(*stack_a));
	while((*stack_b) != 0)
		op_handler(stack_a, stack_b, "pa");
}

/* ignore positive or negative number, check if the stack is sorted*/
int		check_stack_sort_unsigned(t_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = ft_abs(((int *)stack->content)[0]);
	while (stack != 0)
	{
		if (i > ft_abs(((int *)stack->content)[0]))
			return (0);
		else
			i = ft_abs(((int *)stack->content)[0]);
		stack = stack->next;
	}
	return (1);
}

/* return the pointer that points to the lowest number on the list*/
t_list	*find_min_number(t_list *stack)
{
	t_list	*target;

	if (stack == 0)
		return (0);
	target = stack;
	while (stack != 0)
	{
		if (((int *)stack->content)[0] < ((int *)target->content)[0])
			target = stack;
		stack = stack->next;
	}
	return (target);
}

/* return the number of the digit of the number of a content in the stack*/
int	number_digit(t_list *target, unsigned long digit)
{
	int	ans;
	if (target == 0)
		return (0);
	ans = ((int *)target->content)[0];
	return ((ft_abs(ans) / digit) % 10);
}

/* pick the number in the digit to find the the stack
	and will return the pointer that points to the targeted list


	
	return NULL if cannot find that number or digit*/
t_list	*find_num_digit_high(t_list *stack, int find_num, unsigned long digit)
{
	t_list	*target;

	target = NULL;
	while (stack != NULL)
	{
		if (find_num == number_digit(stack, digit))
		{
			if (target == NULL)
				target = stack;
			else
			{
				if (ft_abs(*((int *)stack->content)) >
					ft_abs(*((int *)target->content)))
					target = stack;
			}
		}
		stack = stack->next;
	}
	return (target);
}

t_list	*find_num_digit_low(t_list *stack, int find_num, unsigned long digit)
{
	t_list	*target;

	target = NULL;
	while (stack != NULL)
	{
		if (find_num == number_digit(stack, digit))
		{
			if (target == NULL)
				target = stack;
			else
			{
				if (ft_abs(*((int *)stack->content)) <
					ft_abs(*((int *)target->content)))
					target = stack;
			}
		}
		stack = stack->next;
	}
	return (target);
}