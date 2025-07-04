/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_list_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:46 by srussame          #+#    #+#             */
/*   Updated: 2025/06/29 14:56:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redirect	*redirect_newnode(t_word_struct *wordlist)
{
	t_redirect	*newnode;

	if (!wordlist)
		return (NULL);
	newnode = malloc(sizeof(t_word_struct));
	if (!newnode)
		return (NULL);
	if (wordlist->word_type == APPEND)
		newnode->type = APPEND_FILE;
	else if (wordlist->word_type == WRITE)
		newnode->type = WRITE_FILE;
	else if (wordlist->word_type == HEREDOC)
	{
		newnode->type = HERE_DOC;
		if (wordlist->next_word->word_type == NORMAL)
			newnode->expand = true;
		else
			newnode->expand = false;
	}
	else if (wordlist->word_type == READ)
		newnode->type = READ_FILE;
	newnode->value = ft_strdup(wordlist->next_word->word);
	newnode->next = NULL;
	return (newnode);
}

bool	redirect_addback(t_redirect **redir_list, t_redirect *newnode)
{
	t_redirect	*temp;

	if (!redir_list || !newnode)
		return (false);
	if (!(*redir_list))
	{
		*redir_list = newnode;
		return (true);
	}
	temp = *redir_list;
	while (temp->next)
		temp = temp->next;
	temp->next = newnode;
	return (true);
}

void	redirect_lstclear(t_redirect **list)
{
	t_redirect	*temp;

	if (!list)
		return ;
	while ((*list))
	{
		temp = (*list)->next;
		if ((*list)->value)
			free((*list)->value);
		free((*list));
		*list = temp;
	}
	*list = NULL;
}

t_redirect	*get_redirect_list(t_word_struct *wordlist)
{
	t_redirect	*new_redirect_list;

	if (!wordlist)
		return (NULL);
	new_redirect_list = NULL;
	while (wordlist && wordlist->next_word
		&& wordlist->next_word->word_type != PIPE)
	{
		if (wordlist->word_type == APPEND || wordlist->word_type == HEREDOC
			|| wordlist->word_type == WRITE || wordlist->word_type == READ)
		{
			if (redirect_addback(&new_redirect_list,
					redirect_newnode(wordlist)) == false)
				return (redirect_lstclear(&new_redirect_list), NULL);
		}
		wordlist = wordlist->next_word;
	}
	return (new_redirect_list);
}
