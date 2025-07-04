/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:46 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static	t_word_struct	*create_first_expand_list(void)
{
	t_word_struct	*new_node;
	char			*empty_string;

	empty_string = ft_strdup("");
	if (!empty_string)
		return (NULL);
	new_node = word_struct_newnode(EXPAND, empty_string);
	if (!new_node)
		free(empty_string);
	return (new_node);
}

t_word_struct	*create_expand_list(t_word_struct *target)
{
	char			*word;
	char			*new_word;
	t_word_struct	*new_expand_list;

	if (target == NULL)
		return (NULL);
	word = target->word;
	new_expand_list = create_first_expand_list();
	new_word = get_next_expand_word(&word);
	while (new_word != NULL)
	{
		if (word_struct_addback(&new_expand_list, word_struct_newnode(EXPAND,
					new_word)) == false)
			return (word_struct_lstclear(&new_expand_list), NULL);
		new_word = get_next_expand_word(&word);
	}
	return (new_expand_list);
}
