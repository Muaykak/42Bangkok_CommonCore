/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:27:05 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 18:00:19 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*new_env(char *key, char *value)
{
	t_env	*env;

	if (!key)
		return (NULL);
	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->value = NULL;
	if (value)
		env->value = ft_strdup(value);
	env->key = ft_strdup(key);
	env->next = NULL;
	return (env);
}

void	env_list_addback(t_env **env_list, t_env *new_node)
{
	t_env	*last_node;

	if (!env_list || !new_node)
		return ;
	if (*env_list == NULL)
	{
		*env_list = new_node;
		return ;
	}
	last_node = *env_list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
}

void	env_list_delone(t_env *node)
{
	if (!node)
		return ;
	free(node->key);
	free(node->value);
	free(node);
}

void	env_list_clear(void)
{
	t_env	*env_list;
	t_env	*temp;

	env_list = *get_t_env();
	while (env_list)
	{
		temp = env_list->next;
		env_list_delone(env_list);
		env_list = temp;
	}
	free_split(*env());
	*env() = NULL;
}
