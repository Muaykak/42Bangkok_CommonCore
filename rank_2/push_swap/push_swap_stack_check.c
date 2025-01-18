/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:02:06 by srussame          #+#    #+#             */
/*   Updated: 2025/01/18 12:02:07 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* The function to check if stacks both are sorted correctly*/
int	check_stack_sorted(t_list *stack_a, t_list *stack_b);

int	check_stack_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != 0 || stack_a == 0)
		return (0);
	while (stack_a->next != 0)
	{
		if (((int *)stack_a->content)[0] > ((int *)stack_a->next->content)[0])
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
