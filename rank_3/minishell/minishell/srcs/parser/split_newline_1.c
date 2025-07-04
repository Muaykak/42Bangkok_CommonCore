/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_newline_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:35 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:36 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	quote_check(int *quote_flag, char *c, char charread)
{
	if (charread == '\'' || charread == '\"')
	{
		if (*quote_flag == 0)
		{
			*quote_flag = 1;
			*c = charread;
		}
		else if (*quote_flag == 1 && charread == *c)
			*quote_flag = 0;
	}
}

static int	count_newline_split(char *lineread)
{
	int		count;
	int		quote_flag;
	char	c;

	if (!lineread)
		return (0);
	quote_flag = 0;
	count = 1;
	while (*lineread != '\0')
	{
		quote_check(&quote_flag, &c, *lineread);
		if (*lineread == '\n' && quote_flag == 0)
			count++;
		if (*lineread != '\0')
			lineread++;
	}
	return (count);
}

/*
	Count until newline that is not in the quote
*/
static int	count_until_newline(char *lineread)
{
	int		i;
	int		quote_flag;
	char	c;

	if (!lineread)
		return (0);
	i = 0;
	quote_flag = 0;
	while (*lineread != '\0')
	{
		quote_check(&quote_flag, &c, *lineread);
		if (*lineread == '\n' && quote_flag == 0)
			break ;
		i++;
		lineread++;
	}
	return (i);
}

static char	*get_next_split_newline(char **lineread)
{
	int		len;
	int		i;
	char	*new_string;

	if (!lineread || !(*lineread))
		return (NULL);
	while (**lineread == '\n' && **lineread != '\0')
		(*lineread) = (*lineread) + 1;
	len = count_until_newline(*lineread);
	if (len == 0)
		return (NULL);
	new_string = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len && **lineread != '\0')
	{
		new_string[i++] = **lineread;
		(*lineread) = (*lineread) + 1;
	}
	return (new_string);
}

/*
	After getting line from readline()
	split that string by newline ('\n')
*/
char	**split_newline(char *lineread)
{
	char	**line_split;
	char	*newstring;
	int		split_count;
	int		i;

	if (!lineread)
		return (NULL);
	split_count = count_newline_split(lineread);
	line_split = (char **)ft_calloc((split_count + 1), sizeof(char *));
	if (!line_split)
		return (NULL);
	line_split[split_count] = NULL;
	i = 0;
	newstring = get_next_split_newline(&lineread);
	while (newstring != NULL && i < split_count)
	{
		line_split[i++] = newstring;
		newstring = get_next_split_newline(&lineread);
	}
	return (line_split);
}
