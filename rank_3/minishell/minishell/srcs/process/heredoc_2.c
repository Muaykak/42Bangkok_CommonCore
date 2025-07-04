/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:26 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:41:29 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	count_until_dollar_sign_heredoc(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0' && str[len] != '$')
		len ++;
	return (len);
}

char	*get_not_dollar_sign_heredoc(char **word)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	if (!word || !(*word))
		return (NULL);
	len = count_until_dollar_sign_heredoc(*word);
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	newstr[len] = '\0';
	i = 0;
	while (i < len && *((*word) + i) != '\0')
	{
		newstr[i] = *((*word) + i);
		i++;
	}
	*word += len;
	return (newstr);
}

char	*get_dollar_value_heredoc_sub1(char **word)
{
	if (**word == '$')
	{
		*word = *word + 1;
		return (ft_strdup("[minishell_PID]"));
	}
	else
	{
		*word = *word + 1;
		return (ft_itoa(*get_code()));
	}
}

char	*get_dollar_value_heredoc(char **word)
{
	if (!word || !(*word))
		return (NULL);
	*word = *word + 1;
	if ((ft_isalpha(**word) != 0 || **word == '_'))
		return (get_env_dollar_value(word));
	else if ((**word == '\'' || **word == '\"'))
		return (ft_strdup(""));
	else if (ft_isdigit(**word) != 0)
	{
		*word = *word + 1;
		return (ft_strdup(""));
	}
	else if (**word == '$' && **word == '\?')
		return (get_dollar_value_heredoc_sub1(word));
	else
		return (ft_strdup("$"));
}

void	cat_all_catlist_heredoc_sub1(size_t len, t_word_struct *cat_list,
			char *cat_string)
{
	size_t	i;
	size_t	k;

	i = 0;
	cat_string[len] = '\0';
	while (cat_list)
	{
		k = 0;
		while (cat_list->word && (cat_list->word)[k] != '\0' && i < len)
		{
			cat_string[i] = (cat_list->word)[k];
			i++;
			k++;
		}
		cat_list = cat_list->next_word;
	}
}
