/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pre_sort_stack_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:56:50 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 00:57:08 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_pre_sort_stack(t_ps_stack *stack_a)
{
	t_list		*new_list;
	t_ps_node	*runner;

	if (stack_a == NULL)
		return (NULL);
	runner = stack_a->top;
	new_list = 0;
	while (runner->next != stack_a->top)
	{
		ft_lstadd_back(&new_list, ft_lstnew(&(*runner)));
		if (ft_lstlast(new_list)->content != runner)
		{
			ft_lstclear(&new_list, &free_pre_sort_content);
			return (NULL);
		}
		runner = runner->next;
	}
	ft_lstadd_back(&new_list, ft_lstnew(&(*runner)));
	if (ft_lstlast(new_list)->content != runner)
	{
		ft_lstclear(&new_list, &free_pre_sort_content);
		return (NULL);
	}
	return (new_list);
}
