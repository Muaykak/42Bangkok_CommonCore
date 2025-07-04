/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:18 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:33:58 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_home_path(char **arg)
{
	int	i;

	if (!ft_strncmp(arg[1], "/", 1))
		return (ft_strdup(arg[1]));
	i = 0;
	while (env()[0][i] && ft_strncmp(env()[0][i], "HOME=", 5))
		i++;
	if (ft_strncmp(env()[0][i], "HOME=", 5))
		return (ft_printf(2, "minishell: cd: HOME not set\n"), NULL);
	if (ft_strlen(arg[1]) != 1)
		return (ft_strjoin(env()[0][i] + 5, arg[1] + 1));
	return (ft_strdup(env()[0][i] + 5));
}

static char	*get_oldpwd_path(char **arg)
{
	int	i;

	i = 0;
	while (env()[0][i] && ft_strncmp(env()[0][i], "OLDPWD=", 7))
		i++;
	if (ft_strncmp(env()[0][i], "OLDPWD=", 7) != 0
		|| env()[0][i] == NULL)
		return (ft_printf(2, "minishell: cd: OLDPWD not set\n"), NULL);
	if (ft_strlen(arg[1]) != 1)
		return (ft_strjoin(env()[0][i] + 7, arg[1] + 1));
	return (ft_strdup(env()[0][i] + 7));
}

char	*arg_check(char **arg, char *thispath)
{
	char	*nextpath;
	char	*temp;

	if (!ft_strncmp(arg[1], "/", 1)
		|| !ft_strncmp(arg[1], "~", 1))
		nextpath = absolute_path(arg, true);
	else if (!ft_strncmp(arg[1], "-", 1))
		nextpath = absolute_path(arg, false);
	else
	{
		temp = ft_strjoin(thispath, "/");
		nextpath = ft_strjoin(temp, arg[1]);
		free(temp);
	}
	return (nextpath);
}

char	*absolute_path(char **arg, bool home)
{
	if (home)
		return (get_home_path(arg));
	return (get_oldpwd_path(arg));
}
