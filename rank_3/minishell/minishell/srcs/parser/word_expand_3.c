/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:49 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:50 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	count_next_expand_word(char *word)
{
	size_t			i;
	unsigned int	quote_count[2];

	if (!word)
		return (0);
	i = 0;
	ft_memset(quote_count, 0, sizeof(quote_count));
	while (word[i] != '\0')
	{
		if (word[i] == '\'' && quote_count[1] != 1)
			quote_count[0] = (quote_count[0] + 1) % 2;
		if (word[i] == '\"' && quote_count[0] != 1)
			quote_count[1] = (quote_count[1] + 1) % 2;
		if (ft_isspace(word[i]) != 0 && quote_count[0] == 0
			&& quote_count[1] == 0)
			break ;
		i++;
	}
	return (i);
}

char	*get_next_expand_word(char **word)
{
	size_t	len;
	size_t	i;
	char	*new_string;

	if (!word || !(*word) || **word == '\0')
		return (NULL);
	while (**word != '\0' && ft_isspace(**word) != 0)
		*word = *word + 1;
	if (**word == '\0')
		return (NULL);
	len = count_next_expand_word(*word);
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	new_string[len] = '\0';
	while (i < len && **word != '\0')
	{
		new_string[i] = **word;
		i++;
		*word = *word + 1;
	}
	return (new_string);
}
