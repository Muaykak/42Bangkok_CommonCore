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

#include "main_checker.h"
#include "ft_push_swap.h"


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
	op_handler(&stack_a, &stack_b, &op_swap_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_push_b, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_push_b, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_push_b, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_rotate_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_rotate_b, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_reverse_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_reverse_b, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_swap_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_push_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_push_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	op_handler(&stack_a, &stack_b, &op_push_a, PRINT_OP);
	stack_display(stack_a, stack_b);
	ft_lstclear(&first_pos, &free_number);
}
