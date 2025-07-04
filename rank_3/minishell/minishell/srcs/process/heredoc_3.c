/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:29 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:41:35 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	cat_all_catlist_heredoc(t_word_struct **cat_list, char **line)
{
	size_t	len;
	char	*cat_string;

	if (!cat_list || !line)
		return (false);
	len = count_len_all_list(*cat_list);
	cat_string = malloc((len + 1) * sizeof(char));
	free(*line);
	(*line) = NULL;
	if (!cat_string)
		return (word_struct_lstclear(cat_list), false);
	cat_all_catlist_heredoc_sub1(len, *cat_list, cat_string);
	*line = cat_string;
	return (word_struct_lstclear(cat_list), true);
}

bool	expand_heredoc_line(char **line)
{
	t_word_struct	*cat_list;
	char			*word;

	if (!line || !(*line))
		return (false);
	cat_list = NULL;
	word = (*line);
	while (word && *word != '\0')
	{
		if (*word == '$')
		{
			if (word_struct_addback(&cat_list, word_struct_newnode(WORD,
						get_dollar_value_heredoc(&word))) == false)
				return (word_struct_lstclear(&cat_list), false);
		}
		else
		{
			if (word_struct_addback(&cat_list, word_struct_newnode(WORD,
						get_not_dollar_sign_heredoc(&word))) == false)
				return (word_struct_lstclear(&cat_list), false);
		}
	}
	return (cat_all_catlist_heredoc(&cat_list, line));
}
