/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_sign_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:41 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:44:20 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	count_get_env_dollar_value(char *word)
{
	size_t	i;

	if (!word)
		return (0);
	i = 0;
	while (word[i] != '\0' && (ft_isalnum(word[i]) != 0 || word[i] == '_'))
		i++;
	return (i);
}

void	edit_get_env_dollar_value(char **oldstring)
{
	size_t	len;
	size_t	i;
	char	*new_string;

	if (!oldstring || !(*oldstring))
		return ;
	len = ft_strlen(*oldstring) + 2;
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return ;
	new_string[len] = '\0';
	i = 1;
	new_string[0] = '\"';
	while (i < len && *((*oldstring) + i - 1) != '\0')
	{
		new_string[i] = *((*oldstring) + i - 1);
		i++;
	}
	if (i < len)
		new_string[i] = '\"';
	free(*oldstring);
	*oldstring = new_string;
}

/* This function use to get the env value that needs to expand
	from dollar sign function

	NOTE : the edit_get_env_dollar_value change the way it behaves
			HOWEVER, now without it, it just works like how the
			bash works. but if you consider it to change,
			just put the above function in before the last return */
char	*get_env_dollar_value(char **word)
{
	size_t	len;
	size_t	i;
	char	*return_str;
	char	*key_string;

	if (!word || !(*word))
		return (NULL);
	len = count_get_env_dollar_value(*word);
	key_string = malloc((len + 1) * sizeof(char));
	if (!key_string)
		return (NULL);
	key_string[len] = '\0';
	i = 0;
	while (i < len)
	{
		key_string[i] = *((*word) + i);
		i++;
	}
	*word = *word + i;
	return_str = get_env_value(key_string);
	free(key_string);
	return (return_str);
}
