/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_keyvalue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:35:57 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 17:35:59 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	count_value(char *keyvalue)
{
	int		i;

	i = 0;
	if (!keyvalue)
		return (0);
	while (keyvalue[i] != '\0')
		i++;
	return (i);
}

static char	*get_strvalue(char **oldkeyvalue)
{
	char	*value;
	int		i;
	int		len;

	if (!oldkeyvalue || !(*oldkeyvalue) || **oldkeyvalue == '\0')
		return (NULL);
	len = count_value(*oldkeyvalue);
	value = malloc((len + 1) * sizeof(char));
	if (!value)
		return (NULL);
	value[len] = '\0';
	i = 0;
	while (i < len)
		value[i++] = *((*oldkeyvalue)++);
	return (value);
}

static int	count_key(char *keyvalue)
{
	int	i;

	if (!keyvalue)
		return (0);
	i = 0;
	while (keyvalue[i] != '\0' && keyvalue[i] != '=')
		i++;
	return (i);
}

static char	*get_strkey(char **oldkeyvalue)
{
	char	*key;
	int		i;
	int		len;

	if (!oldkeyvalue || !(*oldkeyvalue) || **oldkeyvalue == '\0')
		return (NULL);
	len = count_key(*oldkeyvalue);
	key = malloc((len + 1) * sizeof(char));
	if (!key)
		return (NULL);
	key[len] = '\0';
	i = 0;
	while (i < len)
		key[i++] = *((*oldkeyvalue)++);
	if (**oldkeyvalue == '=')
		(*oldkeyvalue)++;
	return (key);
}

char	**ft_split_keyvalue(char *env)
{
	char	**key_value;
	char	*key;
	char	*value;

	if (!env)
		return (NULL);
	key = get_strkey(&env);
	if (!key)
		return (NULL);
	value = get_strvalue(&env);
	if (value == NULL)
		key_value = (char **)ft_calloc(2, sizeof(char *));
	else
		key_value = (char **)ft_calloc(3, sizeof(char *));
	if (!key_value)
		return (free(key), free(value), NULL);
	key_value[0] = key;
	if (value != NULL)
		key_value[1] = value;
	return (key_value);
}
