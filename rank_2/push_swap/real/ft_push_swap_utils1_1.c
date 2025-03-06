/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils1_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:42:46 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 22:42:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_utils.h"

void	stack_display(t_list *stack_a, t_list *stack_b);
void	ft_free_split(char **save);
void	free_number(void *number);
int		show_int(t_list *stack);

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

/* show the integer of that list in the stack*/
int	show_int(t_list *stack)
{
	if (!stack)
		return (0);
	return (*((int *)stack->content));
}
