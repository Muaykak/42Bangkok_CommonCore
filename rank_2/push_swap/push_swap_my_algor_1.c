/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_my_algor_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:50:46 by srussame          #+#    #+#             */
/*   Updated: 2025/01/22 17:50:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_my_algor.h"

void	my_algor(t_list **stack_a, t_list **stack_b, int print_op)
{
//	char	a_op[4];
//	char	b_op[4];
	int		i;
//	t_list	*target;

	if (check_stack_sorted(*stack_a, *stack_b) == 1)
		return ;
	i = 0;
	while (ft_lstsize(*stack_a) / 2 > i)
	{
		op_handler(stack_a, stack_b, "pb", print_op);
		i++;
	}
}

