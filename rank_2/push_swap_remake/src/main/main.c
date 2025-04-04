/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:19:52 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 16:19:53 by srussame         ###   ########.fr       */
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
		write(2 ,"Error\n", 6);
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
		write(2 ,"Error\n", 6);
		exit(EXIT_FAILURE);
	}
	first_algor(stack_a);
//	if (check_stack_asc_sorted(stack_a) == 1)
//		ft_printf("the stack is sorted!\n");
//	else
//		ft_printf("the stack is unsorted!\n");
	ps_node_clearall(&(stack_a->min));
	return (0);
}