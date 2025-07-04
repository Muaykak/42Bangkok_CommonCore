/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_list_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:29:22 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 17:29:58 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_env_list(char *key, char *value)
{
	t_env	*key_env;

	key_env = search_env(key);
	if (!key_env)
		env_list_addback(get_t_env(), new_env(key, value));
	else
	{
		free(key_env->value);
		key_env->value = NULL;
		if (value)
			key_env->value = ft_strdup(value);
	}
	set_env_array();
}
