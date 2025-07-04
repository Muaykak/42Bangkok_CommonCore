/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:18 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_process	*parser(char **line)
{
	t_word_struct	*word_struct;

	if (!line || !(*line))
		return (NULL);
	word_struct = NULL;
	lexer(*line, &word_struct);
	grammar_check(&word_struct);
	expand(&word_struct);
	remove_empty_expand(&word_struct);
	remove_quotation(&word_struct);
	return (create_process_list(&word_struct));
}
