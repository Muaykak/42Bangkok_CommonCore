/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:12:29 by srussame          #+#    #+#             */
/*   Updated: 2025/01/13 21:12:31 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

/* create a function to print all the list first*/

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
	ft_printf("}\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*first_pos;

	stack_a = 0;
	stack_b = 0;
	if (argc == 1)
	{
		ft_printf("atleast 1 argument to run the program.\n");
		return (0);
	}
	stack_a = put_argument(argc, argv);
	if (stack_a == 0)
		return (0);
	first_pos = stack_a;
	stack_display(stack_a, stack_b);
	operation_handler(&stack_a, &stack_b, &op_push_b);
	stack_display(stack_a, stack_b);
	operation_handler(&stack_a, &stack_b, &op_push_b);
	stack_display(stack_a, stack_b);
	operation_handler(&stack_a, &stack_b, &op_push_b);
	stack_display(stack_a, stack_b);
	ft_lstclear(&first_pos, &free_number);
}
