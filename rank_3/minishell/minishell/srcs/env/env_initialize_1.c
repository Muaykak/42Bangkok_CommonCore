/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialize_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:26:38 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 18:00:04 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_env	*get_next_env_node(char **env, int *i)
{
	t_env	*node;
	char	**temp;
	char	*temp_1;

	if (!env || env[*i] == NULL)
		return (NULL);
	if (ft_strchr(env[*i], '=') == NULL)
		node = new_env(env[*i], NULL);
	else
	{
		temp = ft_split_keyvalue(env[*i]);
		if (ft_strchr(temp[0], '=') != NULL)
		{
			temp_1 = ft_substr(temp[0], 0, ft_strlen(temp[0]) - 1);
			node = new_env(temp_1, "");
			free(temp_1);
		}
		else
			node = new_env(temp[0], temp[1]);
		free_split(temp);
	}
	*i = *i + 1;
	return (node);
}

void	env_initialize(char **env)
{
	t_env	*new_node;
	int		i;

	i = 0;
	new_node = get_next_env_node(env, &i);
	while (new_node != NULL)
	{
		env_list_addback(get_t_env(), new_node);
		new_node = get_next_env_node(env, &i);
	}
	set_essential_env();
	set_env_array();
}
