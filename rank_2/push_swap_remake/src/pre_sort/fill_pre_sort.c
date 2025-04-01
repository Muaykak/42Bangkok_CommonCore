/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pre_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:31:15 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 13:31:25 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_pre_sort_sub1(t_list *temp, t_list *pre_sort,
				int pos, t_ps_stack *stack_a);

/* Fill the pre-sorted number list to the stack_a list

	also free the pre_sort after usage*/
int	fill_pre_sort(t_list *pre_sort, t_ps_stack *stack_a)
{
	t_list			*temp;
	t_ps_node		*curr;
	t_ps_node		*next;
	int				pos;

	if (stack_a == NULL || pre_sort == NULL)
		return (0);
	temp = pre_sort;
	pos = 1;
	while (temp->next != NULL)
	{
		curr = (t_ps_node *)(temp->content);
		next = (t_ps_node *)(temp->next->content);
		curr->sort_pos = pos++;
		curr->target_next = next;
		next->target_prev = curr;
		temp = temp->next;
	}
	fill_pre_sort_sub1(temp, pre_sort, pos, stack_a);
	return (1);
}

static void	fill_pre_sort_sub1(t_list *temp, t_list *pre_sort,
				int pos, t_ps_stack *stack_a)
{
	t_ps_node	*curr;
	t_ps_node	*next;

	curr = (t_ps_node *)(temp->content);
	next = (t_ps_node *)(pre_sort->content);
	curr->sort_pos = pos;
	curr->target_next = next;
	next->target_prev = curr;
	ft_lstclear(&pre_sort, &free_pre_sort_content);
	stack_a->min = find_node(stack_a->top, 1);
	stack_a->max = find_node(stack_a->top, pos);
}
