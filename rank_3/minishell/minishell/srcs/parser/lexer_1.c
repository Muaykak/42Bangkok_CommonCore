/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:02 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:03 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	lexer_handle_quotation(char *line, unsigned int *k)
{
	char	c;

	if (!line || !k)
		return (false);
	c = line[*k];
	*k = *k + 1;
	while (line[*k] != '\0' && c != line[*k])
		*k = *k + 1;
	if (c == line[*k])
		*k = *k + 1;
	return (true);
}

static void	lexer_addtoken_word_sub1(char *line, unsigned int *i,
		unsigned int *k, char *new_word)
{
	unsigned int	n;

	n = 0;
	while (*i < *k && line[*i] != '\0')
	{
		new_word[n] = line[*i];
		*i = *i + 1;
		n++;
	}
	new_word[n] = '\0';
}

bool	lexer_addtoken_word(char *line, unsigned int *i,
		t_word_struct **word_struct_list)
{
	unsigned int	k;
	char			*new_word;

	if (!word_struct_list || !i || !line)
		return (false);
	k = *i;
	while (line[k] != '\0' && line[k] != '<' && line[k] != '>'
		&& line[k] != '|' && ft_isspace(line[k]) == 0 && line[k] != '\\'
		&& line[k] != ';' && line[k] != '&')
	{
		if (line[k] == '\'' || line[k] == '\"')
			lexer_handle_quotation(line, &k);
		else
			k++;
	}
	new_word = malloc(sizeof(char) * (k - *i + 1));
	if (!new_word)
		return (word_struct_lstclear(word_struct_list), false);
	lexer_addtoken_word_sub1(line, i, &k, new_word);
	if (word_struct_addback(word_struct_list, word_struct_newnode(WORD,
				new_word)) == false)
		return (word_struct_lstclear(word_struct_list), false);
	return (true);
}

bool	lexer_sub1(char *line, unsigned int *i,
		t_word_struct **word_struct_list)
{
	if (line[*i] == '|')
	{
		if (lexer_addtoken_pipe(i, word_struct_list) == false)
			return (false);
	}
	else if (line[*i] == '<' || line[*i] == '>')
	{
		if (lexer_addtoken_redirect(line, i, word_struct_list) == false)
			return (false);
	}
	else
	{
		if (lexer_addtoken_forbidden(line, i, word_struct_list) == false)
			return (false);
	}
	return (true);
}

bool	lexer(char *line, t_word_struct **word_struct_list)
{
	unsigned int	i;

	if (!line || !word_struct_list)
		return (false);
	i = 0;
	while (line[i] != '\0')
	{
		lexer_moveto_notspace(line, &i);
		if (line[i] == '\0')
			break ;
		else if (line[i] == '|' || line[i] == '<' || line[i] == '>'
			|| line[i] == ';' || line[i] == '\\' || line[i] == '&')
		{
			if (lexer_sub1(line, &i, word_struct_list) == false)
				return (false);
		}
		else
		{
			if (lexer_addtoken_word(line, &i, word_struct_list) == false)
				return (false);
		}
	}
	return (true);
}
