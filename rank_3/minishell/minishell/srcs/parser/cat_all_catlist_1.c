/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_all_catlist_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:35 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:38:04 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	count_len_all_list(t_word_struct *cat_list)
{
	size_t	i;
	size_t	k;

	if (!cat_list)
		return (0);
	i = 0;
	while (cat_list)
	{
		k = 0;
		while (cat_list->word && (cat_list->word)[k] != '\0')
			k++;
		i += k;
		cat_list = cat_list->next_word;
	}
	return (i);
}

static void	cat_all_catlist_sub1(size_t len, t_word_struct *cat_list,
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

/*
	Concatenate all cat_list to one single string back to word in wordlist
*/
bool	cat_all_catlist(t_word_struct **cat_list, t_word_struct *wordlist)
{
	size_t	len;
	char	*cat_string;

	if (!cat_list || !wordlist)
		return (false);
	if (!(*cat_list))
		return (true);
	len = count_len_all_list(*cat_list);
	cat_string = malloc((len + 1) * sizeof(char));
	if (!cat_string)
		return (word_struct_lstclear(cat_list), false);
	cat_all_catlist_sub1(len, *cat_list, cat_string);
	free(wordlist->word);
	wordlist->word = cat_string;
	return (word_struct_lstclear(cat_list), true);
}
