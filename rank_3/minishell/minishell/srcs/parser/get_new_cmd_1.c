/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_cmd_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:44 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:19:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_cmd_check(t_word_struct *wordlist)
{
	if (!wordlist)
		return (false);
	if (wordlist->word_type == EXPAND && (!(wordlist->prev_word)
			|| (wordlist->prev_word->word_type != APPEND
				&& wordlist->prev_word->word_type != HEREDOC
				&& wordlist->prev_word->word_type != WRITE
				&& wordlist->prev_word->word_type != READ)))
		return (true);
	return (false);
}

size_t	count_cmd_in_process(t_word_struct *wordlist)
{
	size_t	i;

	if (!wordlist)
		return (0);
	i = 0;
	while (wordlist && wordlist->word_type != PIPE)
	{
		if (wordlist->word_type == EXPAND && (!(wordlist->prev_word)
				|| (wordlist->prev_word->word_type != APPEND
					&& wordlist->prev_word->word_type != HEREDOC
					&& wordlist->prev_word->word_type != WRITE
					&& wordlist->prev_word->word_type != READ)))
			i++;
		wordlist = wordlist->next_word;
	}
	return (i);
}

void	clear_cmd_char(char ***cmd)
{
	size_t	i;

	i = 0;
	if (!cmd || !(*cmd))
		return ;
	while ((*cmd)[i])
	{
		free((*cmd)[i]);
		i++;
	}
	free(*cmd);
	*cmd = NULL;
}

char	**get_new_cmd(t_word_struct *wordlist)
{
	char	**new_cmd;
	size_t	i;
	size_t	len;

	if (!wordlist)
		return (NULL);
	len = count_cmd_in_process(wordlist);
	new_cmd = ft_calloc(len + 1, sizeof(char *));
	if (!new_cmd)
		return (NULL);
	i = 0;
	while (i < len && wordlist)
	{
		while (wordlist && is_cmd_check(wordlist) == false)
			wordlist = wordlist->next_word;
		if (!wordlist)
			break ;
		new_cmd[i] = ft_strdup(wordlist->word);
		if (new_cmd[i] == NULL)
			return (clear_cmd_char(&new_cmd), NULL);
		i++;
		wordlist = wordlist->next_word;
	}
	return (new_cmd);
}
