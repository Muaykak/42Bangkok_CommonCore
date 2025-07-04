/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_v2_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:09 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:40:52 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*get_command_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	return (env[i] + 5);
}

char	*access_absolute(char *cmd, char *path)
{
	char	**all_path;
	char	*temp;
	char	*temp2;
	int		i;

	all_path = ft_split(path, ':');
	i = 0;
	temp = NULL;
	while (all_path && all_path[i])
	{
		temp2 = ft_strjoin(all_path[i], "/");
		temp = ft_strjoin(temp2, cmd);
		free(temp2);
		if (!access(temp, X_OK))
			break ;
		free(temp);
		temp = NULL;
		i++;
	}
	free_split(all_path);
	return (temp);
}
