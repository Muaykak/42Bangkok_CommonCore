/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env_list_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:30:18 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 17:41:12 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	del_env_list(char *key)
{
	t_env	*env_key;
	t_env	*prev_tar;
	t_env	*next_tar;

	env_key = search_env(key);
	if (!env_key)
		return ;
	next_tar = env_key->next;
	prev_tar = *get_t_env();
	if (prev_tar == env_key)
	{
		*get_t_env() = env_key->next;
		return (env_list_delone(env_key), set_env_array());
	}
	while (prev_tar->next != env_key)
		prev_tar = prev_tar->next;
	prev_tar->next = next_tar;
	return (env_list_delone(env_key), set_env_array());
}
