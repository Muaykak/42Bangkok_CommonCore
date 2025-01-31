/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:48:41 by muaykak           #+#    #+#             */
/*   Updated: 2024/11/05 09:03:16 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "main_push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = 0;
	stack_a = put_argument(argc, argv);
	if (stack_a == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
//	my_algor(&stack_a, &stack_b, 1);
//	redix_algor_sort(&stack_a, &stack_b, 1);
//	quicksort_main((stack_a), ft_lstlast(stack_a), &stack_a, &stack_b);
//	stack_display(stack_a, stack_b);
	cost_algor(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free_number);
	return (0);
}
