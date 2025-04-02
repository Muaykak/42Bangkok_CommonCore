/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unsorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:55:15 by srussame          #+#    #+#             */
/*   Updated: 2025/04/03 01:55:27 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	check if the target in the stack is already sort 
	and no need to push to swap*/
int	check_unsorted(t_ps_node *target)
{
	if (target == NULL || target->stack->size < 3)
		return (0);
	if (target->st_next == target->next
		|| target->st_prev == target->prev)
		return (0);
	return (1);
}