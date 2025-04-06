/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_quicksort_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:36:04 by srussame          #+#    #+#             */
/*   Updated: 2025/04/01 11:36:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*pivot_partition(t_list *pre_top, t_list *pre_bot)
{
	t_list		*pivot;
	t_list		*pre;
	t_list		*curr;
	t_ps_node	*temp;

	pivot = pre_top;
	pre = pre_top;
	curr = pre_top;
	while (curr != pre_bot->next)
	{
		temp = 0;
		if (show_ps_num(curr) < show_ps_num(pivot))
		{
			temp = (t_ps_node *)curr->content;
			curr->content = pre->next->content;
			pre->next->content = temp;
			pre = pre->next;
		}
		curr = curr->next;
	}
	temp = (t_ps_node *)pivot->content;
	pivot->content = (t_ps_node *)pre->content;
	pre->content = (t_ps_node *)temp;
	return (pre);
}

static void	pre_quicksort_sub(t_list *pre_top, t_list *pre_bot)
{
	t_list	*pivot;

	if (pre_top == NULL || pre_bot == NULL || pre_top == pre_bot)
		return ;
	pivot = pivot_partition(pre_top, pre_bot);
	pre_quicksort_sub(pre_top, pivot);
	pre_quicksort_sub(pivot->next, pre_bot);
}

t_list	*pre_quicksort(t_list *pre_top)
{
	t_list	*pre_bot;

	if (pre_top == NULL)
		return (NULL);
	pre_bot = ft_lstlast(pre_top);
	pre_quicksort_sub(pre_top, pre_bot);
	return (pre_top);
}
