/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:23 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 14:07:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	op_push_b(t_list **stack, t_list **push, int print_op)
{
	t_list	*new;

	if (!push || !stack || (*stack) == 0)
		return (0);
	new = *stack;
	*stack = (*stack)->next;
	ft_lstadd_front(push, new);
	if (print_op == 1)
		ft_printf("pb\n");
	return (1);
}
