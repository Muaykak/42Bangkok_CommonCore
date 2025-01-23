/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operation_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:33:21 by srussame          #+#    #+#             */
/*   Updated: 2025/01/17 15:33:48 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	op_swap(t_list **stack);

int	op_swap(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack) || (*stack)->next == 0)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
	return (1);
}
