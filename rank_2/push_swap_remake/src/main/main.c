/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:27:09 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 15:27:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		***numsets;
	t_ps_stack	*stack_a;
	t_ps_node	*temp;

	numsets = get_numsets(argc, argv);
	if (numsets == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = create_stack_a(numsets);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	temp = stack_a->top;
	while (temp->next != NULL && temp->next != stack_a->top)
	{
		ft_printf("num: %d\n", temp->number);
		temp = temp->next;
	}
	ft_printf("num: %d\n", temp->number);
	ft_printf("element count: %d\n", stack_a->size);
	ps_node_clearall(&(stack_a)->top);
	return (0);
}