/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:48:31 by srussame          #+#    #+#             */
/*   Updated: 2025/03/31 19:48:32 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_stack	*create_stack_b(void)
{
	t_ps_stack	*stack_b;

	stack_b = (t_ps_stack *)ft_calloc(1, sizeof(t_ps_stack));
	if (stack_b == NULL)
		return (NULL);
	stack_b->stack = B;
	return (stack_b);
}
