/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_check_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:53 by srussame          #+#    #+#             */
/*   Updated: 2025/06/29 15:07:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	grammar_check1_sub1(t_word_struct **list, t_word_struct *temp)
{
	if (temp->word_type == WORD && temp->prev_word
		&& temp->prev_word->word_type == HEREDOC)
		check_heredoc_expand(temp);
	if ((temp->word_type == HEREDOC || temp->word_type == APPEND
			|| temp->word_type == WRITE || temp->word_type == READ)
		&& (temp->next_word == NULL || temp->next_word->word_type != WORD))
	{
		*get_code() = 2;
		ft_printf(2, "Syntax Error: Invalid Redirections\n");
		return (word_struct_lstclear(list), false);
	}
	else if (temp->word_type == PIPE && (temp->next_word == NULL
			|| temp->prev_word == NULL || ((temp->prev_word->word_type != WORD
					&& temp->prev_word->word_type != NORMAL)
				&& temp->prev_word->word_type != HEREDOC)))
	{
		*get_code() = 2;
		ft_printf(2, "Syntax Error: Invalid pipes\n");
		return (word_struct_lstclear(list), false);
	}
	return (true);
}

/*
	1ST SYNTAX CHECKING FUNCTION
		- PIPE should be placed between words
		- redirections (APPEND HEREDOC READ WRITE) MUST FOLLOWED BY WORD
	** CLEAN the t_word_struct list upon failure
*/
bool	grammar_check1(t_word_struct **list)
{
	t_word_struct	*temp;

	if (!list)
		return (false);
	temp = *list;
	while (temp)
	{
		if (grammar_check1_sub1(list, temp) == false)
			return (false);
		temp = temp->next_word;
	}
	return (true);
}

void	quotation_check_sub1(t_word_struct *temp, int *flag)
{
	unsigned int	i;
	char			c;

	i = 0;
	*flag = 0;
	c = '\0';
	while ((temp->word)[i] != '\0')
	{
		if ((temp->word)[i] == '\'' || (temp->word)[i] == '\"')
		{
			if (*flag == 0)
			{
				c = (temp->word)[i];
				*flag = 1;
			}
			else if (*flag == 1 && c == (temp->word)[i])
				*flag = 0;
		}
		i++;
	}
}

/*
	check if the word has closed quotation mark
		- "asdf" -> TRUE
		- 'asdfaf dsasdf fdsf'asdfdsf -> TRUE
		- "aasdfasdfa -> FALSE
		- asdfafafdasdfdfasdf' -> FALSE
*/
bool	quotation_check(t_word_struct **list)
{
	t_word_struct	*temp;
	int				flag;

	if (!list)
		return (false);
	temp = *list;
	while (temp)
	{
		if (temp->word_type == WORD)
		{
			quotation_check_sub1(temp, &flag);
			if (flag != 0)
			{
				ft_printf(2, "Syntax Error: Unclosed Quotes\n");
				*get_code() = 2;
				return (word_struct_lstclear(list), false);
			}
		}
		temp = temp->next_word;
	}
	return (true);
}

/*
	INITIAL SYNTAX CHECK
*/
bool	grammar_check(t_word_struct **list)
{
	if (!list)
		return (false);
	if (quotation_check(list) == false)
		return (false);
	if (forbidden_check(list) == false)
		return (false);
	if (grammar_check1(list) == false)
		return (false);
	return (true);
}
