/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_check_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:56 by srussame          #+#    #+#             */
/*   Updated: 2025/06/29 15:11:59 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_heredoc_expand(t_word_struct *temp)
{
	char	*str;

	str = temp->word;
	while (*str != '\0' && *str != '\'' && *str != '\"')
		str++;
	if (*str == '\0')
		temp->word_type = NORMAL;
	else
		temp->word_type = NOTEXPAND;
}

bool	forbidden_check(t_word_struct **list)
{
	t_word_struct	*temp;

	if (!list)
		return (false);
	temp = *list;
	while (temp)
	{
		if (temp->word_type == FORBIDDEN)
		{
			ft_printf(2, "Syntax Error: the token \'%c\': is not interpret\n",
				(temp->word)[0]);
			*get_code() = 2;
			return (word_struct_lstclear(list), false);
		}
		temp = temp->next_word;
	}
	return (true);
}
