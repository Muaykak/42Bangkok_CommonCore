/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:33:48 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 22:34:02 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* take numsets from get_numset() */
t_ps_stack	*create_stack_a(char ***numsets)
{
	t_ps_stack	*stack_a;
	t_ps_node	*new_node;
	int	i;
	int	j;

	if (numsets == NULL)
		return (NULL);
	stack_a = (t_ps_stack *)ft_calloc(1, sizeof(t_ps_stack));
	if (stack_a == NULL)
		return (NULL);
	stack_a->stack = A;
	i = 0;
	new_node = 0;
	while (numsets[i] != NULL)
	{
		j = 0;
		while (numsets[i][j] != NULL)
		{
			ps_node_addback(&new_node, ps_node_new(stack_a,
				ft_atoi(numsets[i][j])));
			if (new_node == NULL || stack_a->bot->number
				!= ft_atoi(numsets[i][j]))
			{
				ps_node_clearall(&new_node);
				return (NULL);
			}	
			j++;
		}
		i++;
	}
	free_numsets(numsets);
	return (stack_a);
}
