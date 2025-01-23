/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:21 by srussame          #+#    #+#             */
/*   Updated: 2025/01/14 14:34:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_utils.h"

void	stack_display(t_list *stack_a, t_list *stack_b);
void	ft_free_split(char **save);
void	free_number(void *number);
int		ft_abs(int number);
int		max_number(t_list *stack);
int		high_num(t_list *stack);
int		low_num(t_list *stack);

/* return the minmax number in the stack */
int	max_number(t_list *stack)
{
	int i;

	if (stack == 0)
		return (0);
	i = ((int *)stack->content)[0];
	while (stack != 0)
	{
		if (ft_abs(i) < ft_abs(((int *)stack->content)[0]))
			i  = ((int *)stack->content)[0];
		stack = stack->next;
	}
	return (i);
}

/* return the highest number of the stack*/
int	high_num(t_list *stack)
{
	int i;

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
	int i;

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

int	ft_abs(int number)
{
	if (number == -2147483648)
		return (2147483647);
	if (number < 0)
		return (-1 * number);
	else
		return (number);
}

void	ft_free_split(char **save)
{
	size_t	i;

	i = 0;
	while (save[i] != 0)
	{
		free(save[i]);
		i++;
	}
	free(save);
}

void	free_number(void *number)
{
	if (number != NULL)
		free(number);
	return ;
}

/* This function will print Both stack a and b*/
void	stack_display(t_list *stack_a, t_list *stack_b)
{
	ft_printf("A = {");
	while (stack_a != 0)
	{
		ft_printf("%d", *((int *)stack_a->content));
		if (stack_a->next != 0)
			ft_printf(", ");
		stack_a = stack_a->next;
	}
	ft_printf("}\nB = {");
	while (stack_b != 0)
	{
		ft_printf("%d", *((int *)stack_b->content));
		if (stack_b->next != 0)
			ft_printf(", ");
		stack_b = stack_b->next;
	}
	ft_printf("}\n\n");
}
