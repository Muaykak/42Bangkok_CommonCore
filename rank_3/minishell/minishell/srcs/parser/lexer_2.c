/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:07 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:08 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Move the char pointer to the next char that is not whitespace
*/
void	lexer_moveto_notspace(char *line, unsigned int *i)
{
	if (line == NULL)
		return ;
	while (line[*i] != '\0' && ft_isspace(line[*i]) == 1)
		*i = *i + 1;
	return ;
}

bool	lexer_addtoken_forbidden(char *line, unsigned int *i, \
t_word_struct **word_struct_list)
{
	char	*newstr;

	newstr = malloc(2);
	if (!newstr)
		return (word_struct_lstclear(word_struct_list), false);
	newstr[1] = '\0';
	newstr[0] = line[*i];
	if (word_struct_addback(word_struct_list, \
word_struct_newnode(FORBIDDEN, newstr)) == true)
	{
		*i = *i + 1;
		return (true);
	}
	else
		return (word_struct_lstclear(word_struct_list), false);
}

/*
Add pipe token to word_struct list
*/
bool	lexer_addtoken_pipe(unsigned int *i, t_word_struct **word_struct_list)
{
	if (word_struct_addback(word_struct_list, word_struct_newnode(PIPE,
				NULL)) == true)
	{
		*i = *i + 1;
		return (true);
	}
	else
		return (word_struct_lstclear(word_struct_list), false);
}

static bool	lexer_addtoken_redirect_sub1(char *line, unsigned int *i,
		t_word_struct **word_struct_list)
{
	if (line[*i] == '<')
	{
		if (word_struct_addback(word_struct_list, word_struct_newnode(READ,
					NULL)) == false)
			return (word_struct_lstclear(word_struct_list), false);
	}
	else if (line[*i] == '>')
	{
		if (word_struct_addback(word_struct_list, word_struct_newnode(WRITE,
					NULL)) == false)
			return (word_struct_lstclear(word_struct_list), false);
	}
	*i = *i + 1;
	return (true);
}

bool	lexer_addtoken_redirect(char *line, unsigned int *i,
		t_word_struct **word_struct_list)
{
	if (!word_struct_list || !i || !line)
		return (false);
	if (line[*i] == '>' && line[*i + 1] == '>')
	{
		if (word_struct_addback(word_struct_list, word_struct_newnode(APPEND,
					NULL)) == false)
			return (word_struct_lstclear(word_struct_list), false);
		*i = *i + 2;
		return (true);
	}
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		if (word_struct_addback(word_struct_list, word_struct_newnode(HEREDOC,
					NULL)) == false)
			return (word_struct_lstclear(word_struct_list), false);
		*i = *i + 2;
		return (true);
	}
	return (lexer_addtoken_redirect_sub1(line, i, word_struct_list));
}
