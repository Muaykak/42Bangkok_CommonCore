/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils1_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:44:53 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 22:44:54 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_utils.h"

int		ft_abs(int number);
int		high_num(t_list *stack);
int		low_num(t_list *stack);
t_list	*find_min_number(t_list *stack);
t_list	*find_max_number(t_list *stack);

int	ft_abs(int number)
{
	if (number == -2147483648)
		return (2147483647);
	if (number < 0)
		return (-1 * number);
	else
		return (number);
}

/* return the highest number of the stack*/
int	high_num(t_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = *((int *)stack->content);
	while (stack != 0)
	{
		if (*((int *)stack->content) > i)
			i = *((int *)stack->content);
		stack = stack->next;
	}
	return (i);
}

/* return the lowest number of the stack*/
int	low_num(t_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = *((int *)stack->content);
	while (stack != 0)
	{
		if (*((int *)stack->content) < i)
			i = *((int *)stack->content);
		stack = stack->next;
	}
	return (i);
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

/* return the pointer that points to the lowest number on the list*/
t_list	*find_max_number(t_list *stack)
{
	t_list	*target;

	if (stack == 0)
		return (0);
	target = stack;
	while (stack != 0)
	{
		if (((int *)stack->content)[0] > ((int *)target->content)[0])
			target = stack;
		stack = stack->next;
	}
	return (target);
}
