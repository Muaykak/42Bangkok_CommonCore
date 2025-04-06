/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swapable_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:17:37 by srussame          #+#    #+#             */
/*   Updated: 2025/04/02 23:17:54 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check if the target can be sort using the swap opeartion*/
int	check_swapable(t_ps_node *target)
{
	if (target == NULL || target->stack->size <= 1)
		return (0);
	if (target->next == target->st_prev)
		return (1);
	if (target->prev == target->st_next)
		return (1);
	return (0);
}
