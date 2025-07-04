/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:15 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:36:59 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_split(char **temp)
{
	int	i;

	if (!temp)
		return ;
	i = 0;
	while (temp[i] != NULL)
		free(temp[i++]);
	free(temp);
	return ;
}

void	print_env(void)
{
	int		i;

	i = 0;
	while (env()[0][i])
		ft_printf(1, "%s\n", env()[0][i++]);
}

static void	print(t_env	*env)
{
	if (env->value)
	{
		if (!*env->value)
			ft_printf(1, "declare -x %s=\"\"\n", env->key);
		else
			ft_printf(1, "declare -x %s=\"%s\"\n", env->key, env->value);
	}
	else
		ft_printf(1, "declare -x %s\n", env->key);
}

void	print_env_list(void)
{
	t_env	*env;

	env = *get_t_env();
	while (env)
	{
		print(env);
		env = env->next;
	}
}
