/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_empty_expand_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:26 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:27 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_empty_string(t_word_struct *wordlist)
{
	unsigned int	i;

	if (!wordlist || wordlist->word_type != EXPAND)
		return (false);
	i = 0;
	while ((wordlist->word) && (wordlist->word)[i] != '\0')
	{
		if (ft_isspace((wordlist->word)[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

/*
	after doing a dollar sign expansion

	this function remove the empty string from the list
*/
void	remove_empty_expand(t_word_struct **wordlist)
{
	t_word_struct	*temp;
	t_word_struct	*temp2;

	if (!wordlist || !(*wordlist))
		return ;
	temp = (*wordlist);
	while (temp)
	{
		temp2 = temp->next_word;
		if (is_empty_string(temp) == true)
			word_struct_remove_from_list(temp, wordlist);
		temp = temp2;
	}
}
