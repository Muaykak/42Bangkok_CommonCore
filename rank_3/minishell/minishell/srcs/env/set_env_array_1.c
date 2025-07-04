/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_array_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:34:38 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 18:00:31 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_list_len(void)
{
	t_env	*env_list;
	int		i;

	env_list = *get_t_env();
	i = 0;
	while (env_list)
	{
		i++;
		env_list = env_list->next;
	}
	return (i);
}

void	set_env_array_sub1(char **new_array, int *i, t_env *env_list)
{
	char	*temp1;
	char	*temp2;

	if (env_list->value && env_list->key[0] != '$')
	{
		temp1 = ft_strjoin(env_list->key, "=");
		temp2 = ft_strjoin(temp1, env_list->value);
		free(temp1);
		new_array[*i] = temp2;
		(*i) += 1;
	}
}

/* set up the env that used to sent to execve() */
void	set_env_array(void)
{
	int		i;
	int		len;
	char	**new_array;
	t_env	*env_list;

	if (*env())
		free_split(*env());
	len = env_list_len();
	new_array = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!new_array)
		return ;
	env_list = *get_t_env();
	i = 0;
	while (i < len && env_list)
	{
		set_env_array_sub1(new_array, &i, env_list);
		env_list = env_list->next;
	}
	*env() = new_array;
}
