/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:29:49 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 00:29:58 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ss(t_ps_stack *stack_a, t_ps_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL
		|| stack_a->size < 2 || stack_b->size < 2)
		return ;
	op_sa_sub1(stack_a);
	op_sb_sub1(stack_b);
	if (PS_PRINT_OP == 1)
		ft_printf("ss\n");
	return ;
}
