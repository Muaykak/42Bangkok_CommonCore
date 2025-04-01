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
	t_ps_stack	*stack_b;

	numsets = get_numsets(argc, argv);
	if (numsets == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = create_stack_a(numsets);
	stack_b = create_stack_b(stack_a);
	if (stack_a == NULL || stack_b == NULL)
	{
		if (stack_a)
			ps_node_clearall(&(stack_a->top));
		if (stack_b)
			ps_node_clearall(&(stack_b->top));
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	display_sorted_stack(stack_a);
	ft_printf("min: %d\nmax: %d\n", stack_a->min->number, stack_a->max->number);
	ft_printf("element a count: %d\n", stack_a->size);
	ft_printf("element b count: %d\n", stack_b->size);
	ps_node_clearall(&(stack_a->top));
	return (0);
}