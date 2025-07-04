/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_sign_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:38 by srussame          #+#    #+#             */
/*   Updated: 2025/07/02 18:08:30 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_dollar_value_sub1(char **word, unsigned int quote_count[2])
{
	if (**word == '$' && quote_count[0] == 0)
	{
		*word = *word + 1;
		return (ft_strdup(""));
	}
	else
	{
		*word = *word + 1;
		return (ft_itoa(*get_code()));
	}
}

char	*get_dollar_value(char **word, unsigned int quote_count[2])
{
	if (!word || !(*word))
		return (NULL);
	*word = *word + 1;
	if ((ft_isalpha(**word) != 0 || **word == '_') && quote_count[0] == 0)
		return (get_env_dollar_value(word));
	else if (((**word == '\'' || **word == '\"') && quote_count[0] == 0
			&& quote_count[1] == 0))
		return (ft_strdup(""));
	else if ((ft_isdigit(**word) != 0 && quote_count[0] == 0))
	{
		*word = *word + 1;
		return (ft_strdup(""));
	}
	else if ((**word == '$' && quote_count[0] == 0) || (**word == '\?'
			&& quote_count[0] == 0))
		return (get_dollar_value_sub1(word, quote_count));
	else
		return (ft_strdup("$"));
}

size_t	count_until_dollar_sign(char *word)
{
	size_t	i;

	if (!word)
		return (0);
	i = 0;
	while (word[i] != '\0' && word[i] != '$')
		i++;
	return (i);
}

char	*get_not_dollar_sign(char **word, unsigned int quote_count[2])
{
	char	*new_str;
	size_t	len;
	size_t	i;

	if (!word || !(*word))
		return (NULL);
	len = count_until_dollar_sign(*word);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	i = 0;
	while (i < len && *((*word) + i) != '\0')
	{
		if (*((*word) + i) == '\'' && quote_count[1] != 1)
			quote_count[0] = (quote_count[0] + 1) % 2;
		else if (*((*word) + i) == '\"' && quote_count[0] != 1)
			quote_count[1] = (quote_count[1] + 1) % 2;
		new_str[i] = *((*word) + i);
		i++;
	}
	*word += len;
	return (new_str);
}

/*
	Expand the dollar sign in all the list except the SINGLE_QUOTE
	*Could be the LARGE one ;-;
*/
bool	expand_dollar_sign(t_word_struct *wordlist)
{
	t_word_struct	*cat_list;
	char			*word;
	unsigned int	quote_count[2];

	if (!wordlist)
		return (false);
	cat_list = NULL;
	ft_memset(quote_count, 0, sizeof(quote_count));
	word = wordlist->word;
	while (word && *word != '\0')
	{
		if (*word == '$')
		{
			if (word_struct_addback(&cat_list, word_struct_newnode(WORD,
						get_dollar_value(&word, quote_count))) == false)
				return (word_struct_lstclear(&cat_list), false);
		}
		else
		{
			if (word_struct_addback(&cat_list, word_struct_newnode(WORD,
						get_not_dollar_sign(&word, quote_count))) == false)
				return (word_struct_lstclear(&cat_list), false);
		}
	}
	return (cat_all_catlist(&cat_list, wordlist));
}
