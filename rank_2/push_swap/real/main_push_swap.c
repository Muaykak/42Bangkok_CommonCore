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

	if (argc == 1)
		return (0);
	stack_b = 0;
	stack_a = put_argument(argc, argv);
	if (stack_a == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	cost_algor(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free_number);
	return (0);
}
