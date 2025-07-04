/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_word_struct_utility_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:41 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:42 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	word_struct_lstdelone(t_word_struct *lst)
{
	if (!lst)
		return ;
	if (lst->word)
		free(lst->word);
	free(lst);
}

t_word_struct	*word_struct_lstlast(t_word_struct *list)
{
	t_word_struct	*last;

	if (!list)
		return (NULL);
	last = list;
	while (last->next_word != NULL)
		last = last->next_word;
	return (last);
}

void	word_struct_joinlist(t_word_struct **target_list,
		t_word_struct *new_list)
{
	t_word_struct	*new_last;
	t_word_struct	*before_target;
	t_word_struct	*after_target;

	if (!new_list || !target_list)
		return ;
	if (!(*target_list))
	{
		*target_list = new_list;
		return ;
	}
	before_target = (*target_list)->prev_word;
	after_target = (*target_list)->next_word;
	new_last = word_struct_lstlast(new_list);
	new_list->prev_word = before_target;
	if (before_target)
		before_target->next_word = new_list;
	new_last->next_word = after_target;
	if (after_target)
		after_target->prev_word = new_last;
	word_struct_lstdelone(*target_list);
	*target_list = new_list;
	while ((*target_list)->prev_word)
		(*target_list) = (*target_list)->prev_word;
}
