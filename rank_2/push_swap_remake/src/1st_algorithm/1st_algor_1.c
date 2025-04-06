/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_algor_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:19:39 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 15:19:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_algor(t_ps_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	if (check_stack_asc_sorted(stack_a) == 1)
	{
		easy_rotate(stack_a->stack_min);
		return ;
	}
	push_b_all(stack_a, stack_a->link);
	push_a_all(stack_a, stack_a->link);
	easy_rotate(stack_a->min);
	return ;
}

