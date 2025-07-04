/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotation_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:30 by srussame          #+#    #+#             */
/*   Updated: 2025/06/29 15:08:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**       remove_quotation_1.c        **/

char	*get_nonquote(char **word)
{
	char	*new_string;
	size_t	len;
	size_t	i;

	if (!word || !(*word))
		return (NULL);
	len = count_until_quote(*word);
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[len] = '\0';
	i = 0;
	while (i < len && *((*word) + i) != '\0')
	{
		new_string[i] = *((*word) + i);
		i++;
	}
	*word += len;
	return (new_string);
}

size_t	count_until_next_quote(char *word, char quote_sign)
{
	size_t	i;

	if (!word)
		return (0);
	i = 0;
	while (word[i] != '\0' && word[i] != quote_sign)
		i++;
	return (i);
}

char	*get_inquote(char **word)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	char	c;

	if (!word || !(*word))
		return (NULL);
	c = **word;
	*word = *word + 1;
	len = count_until_next_quote(*word, c);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[len] = '\0';
	i = 0;
	while (i < len && *((*word) + i) != '\0')
	{
		new_str[i] = *((*word) + i);
		i++;
	}
	if (*((*word) + i) == '\0')
		*word = *word + i;
	else
		*word = *word + i + 1;
	return (new_str);
}

bool	remove_quotation_sub1(t_word_struct *wordlist)
{
	char			*word;
	t_word_struct	*cat_list;

	if (!wordlist)
		return (false);
	word = wordlist->word;
	cat_list = NULL;
	while (word && *word != '\0')
	{
		if (*word != '\'' && *word != '\"')
		{
			if (word_struct_addback(&cat_list, word_struct_newnode(WORD,
						get_nonquote(&word))) == false)
				return (word_struct_lstclear(&cat_list), false);
		}
		else
		{
			if (word_struct_addback(&cat_list, word_struct_newnode(WORD,
						get_inquote(&word))) == false)
				return (word_struct_lstclear(&cat_list), false);
		}
	}
	return (cat_all_catlist(&cat_list, wordlist));
}

/*
	remove quotation from the t_word_struct list from word
	type 'EXPAND' and 'NORMAL'
*/
bool	remove_quotation(t_word_struct **wordlist)
{
	t_word_struct	*ptr;

	if (!wordlist || !(*wordlist))
		return (false);
	ptr = (*wordlist);
	while (ptr)
	{
		if (ptr->word_type == EXPAND || ptr->word_type == NORMAL
			|| ptr->word_type == NOTEXPAND)
		{
			if (remove_quotation_sub1(ptr) == false)
				return (word_struct_lstclear(wordlist), false);
		}
		ptr = ptr->next_word;
	}
	return (true);
}
