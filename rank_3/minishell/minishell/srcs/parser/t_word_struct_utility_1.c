/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_word_struct_utility_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:38 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
New node of t_word_struct
*/
t_word_struct	*word_struct_newnode(t_word_type type, char *word)
{
	t_word_struct	*word_struct;

	word_struct = malloc(sizeof(t_word_struct));
	if (!word_struct)
		return (NULL);
	ft_memset(word_struct, 0, sizeof(t_word_struct));
	word_struct->word = word;
	word_struct->word_type = type;
	return (word_struct);
}

bool	word_struct_addback(t_word_struct **list, t_word_struct *new)
{
	t_word_struct	*runner;

	if (!list || !new)
		return (false);
	if (*list == NULL)
	{
		*list = new;
		return (true);
	}
	runner = *list;
	while (runner->next_word != NULL)
		runner = runner->next_word;
	runner->next_word = new;
	new->prev_word = runner;
	return (true);
}

/*
	CLEAN the t_word_struct token list
*/
void	word_struct_lstclear(t_word_struct **word_struct_list)
{
	t_word_struct	*temp;

	if (!word_struct_list)
		return ;
	while ((*word_struct_list) && (*word_struct_list)->prev_word)
		(*word_struct_list) = (*word_struct_list)->prev_word;
	while (*word_struct_list != NULL)
	{
		temp = (*word_struct_list)->next_word;
		word_struct_lstdelone(*word_struct_list);
		*word_struct_list = temp;
	}
	*word_struct_list = NULL;
}

static bool	is_in_list(t_word_struct *node, t_word_struct **head)
{
	t_word_struct	*temp;

	if (!node || !head || !(*head))
		return (false);
	temp = *head;
	while (temp)
	{
		if (temp == node)
			return (true);
		temp = temp->next_word;
	}
	return (false);
}

/*
	remove that one node from the list
*/
void	word_struct_remove_from_list(t_word_struct *to_remove, \
t_word_struct **head)
{
	t_word_struct	*before;
	t_word_struct	*after;

	if (is_in_list(to_remove, head) == false)
		return ;
	if ((*head) == to_remove)
	{
		(*head) = to_remove->next_word;
		if ((*head))
			(*head)->prev_word = NULL;
		word_struct_lstdelone(to_remove);
		return ;
	}
	before = to_remove->prev_word;
	after = to_remove->next_word;
	before->next_word = after;
	if (after)
		after->prev_word = before;
	word_struct_lstdelone(to_remove);
	return ;
}
