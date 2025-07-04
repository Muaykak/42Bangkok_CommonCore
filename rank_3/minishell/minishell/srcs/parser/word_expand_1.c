/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:43 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* *******       word_expand_1.c      ******* */

bool	expand_list(t_word_struct **target_list)
{
	t_word_struct	*new_expand_list;

	if (!target_list)
		return (false);
	new_expand_list = create_expand_list(*target_list);
	if (!new_expand_list)
		return (false);
	word_struct_joinlist(target_list, new_expand_list);
	return (true);
}

t_word_struct	*jump_to_word_type(t_word_struct *head)
{
	t_word_struct	*ptr;

	if (!head)
		return (NULL);
	ptr = head;
	while (ptr->prev_word)
		ptr = ptr->prev_word;
	while (ptr && ptr->word_type != WORD)
		ptr = ptr->next_word;
	return (ptr);
}

/*
	Expand the t_word_struct list after dollar sign expansion
*/
bool	expand_word_list(t_word_struct **word_list)
{
	t_word_struct	*next_word_type;

	if (!word_list || !(*word_list))
		return (false);
	next_word_type = jump_to_word_type(*word_list);
	while (next_word_type != NULL)
	{
		(*word_list) = next_word_type;
		if ((*word_list)->word_type == WORD && expand_list(word_list) == false)
		{
			*word_list = next_word_type;
			return (word_struct_lstclear(word_list), false);
		}
		next_word_type = jump_to_word_type(*word_list);
	}
	if ((*word_list)->word_type == WORD && expand_list(word_list) == false)
	{
		return (word_struct_lstclear(word_list), false);
	}
	while ((*word_list) && (*word_list)->prev_word)
		(*word_list) = (*word_list)->prev_word;
	return (true);
}

bool	word_expand(t_word_struct *word)
{
	if (!word)
		return (false);
	if (expand_dollar_sign(word) == false)
	{
		return (false);
	}
	return (true);
}

/*
handles $ sign expandsion before unquote the quotation mark
*/
bool	expand(t_word_struct **word_list)
{
	t_word_struct	*temp;

	if (!word_list)
		return (false);
	temp = *word_list;
	while (temp)
	{
		if (temp->word_type == WORD && word_expand(temp) == false)
			return (word_struct_lstclear(word_list), false);
		temp = temp->next_word;
	}
	return (expand_word_list(word_list));
}

// void	print_expand_list(t_word_struct *list)
// {
// 	size_t	i;
// 
// 	i = 0;
// 	printf("+++++++++++++++++++++++ EXPAND LIST\n");
// 	while (list)
// 	{
// 		printf("expand[%zu]: %s length:%zu\n", i, list->word,
// 			ft_strlen(list->word));
// 		i++;
// 		list = list->next_word;
// 	}
// }
