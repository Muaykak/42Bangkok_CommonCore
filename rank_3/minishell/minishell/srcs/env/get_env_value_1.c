/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:32:02 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 17:32:31 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_env_value(char *key)
{
	t_env	*key_env;

	if (!key)
		return (NULL);
	key_env = search_env(key);
	if (!key_env)
		return (ft_strdup(""));
	return (ft_strdup(key_env->value));
}
