/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:33:13 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 18:00:48 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* search and return the env from the list*/
t_env	*search_env(char *key)
{
	t_env	*env_list;

	if (!key)
		return (NULL);
	env_list = *get_t_env();
	while (env_list)
	{
		if (!ft_strncmp(env_list->key, key, ft_strlen(key) + 1))
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}
