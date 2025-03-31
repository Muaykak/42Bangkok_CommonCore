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

t_ps_stack	*create_stack_a(char ***numsets);
static int	create_stack_a_sub1(t_ps_node **new_node, char *numset, 
				t_ps_stack *stack_a);
static int	create_stack_a_sub2(char ***numsets, t_ps_stack *stack_a);

static int	create_stack_a_sub2(char ***numsets, t_ps_stack *stack_a)
{
	t_ps_node	*new_node;
	int			i;
	int			j;

	i = 0;
	new_node = 0;
	while (numsets[i] != NULL)
	{
		j = 0;
		while (numsets[i][j] != NULL)
		{
			if (create_stack_a_sub1(&new_node, numsets[i][j++], stack_a) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

static int	create_stack_a_sub1(t_ps_node **new_node,
	char *numset, t_ps_stack *stack_a)
{
	ps_node_addback(new_node, ps_node_new(stack_a,
		ft_atoi(numset)));
	if (*new_node == NULL || stack_a->bot->number
		!= ft_atoi(numset))
	{
		ps_node_clearall(new_node);
		return (0);
	}	
	return (1);
}

/* take numsets from get_numset() */
t_ps_stack	*create_stack_a(char ***numsets)
{
	t_ps_stack	*stack_a;

	if (numsets == NULL)
		return (NULL);
	stack_a = (t_ps_stack *)ft_calloc(1, sizeof(t_ps_stack));
	if (stack_a == NULL)
		return (NULL);
	stack_a->stack = A;
	create_stack_a_sub2(numsets, stack_a);
	free_numsets(numsets);
	if (check_duplicate(stack_a) == 0)
	{
		ps_node_clearall(&(stack_a->top));
		return (NULL);
	}
	return (stack_a);
}
