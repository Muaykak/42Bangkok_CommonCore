/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:14 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:45:33 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	set_old_pwd(char *thispath)
{
	char	new_path[2000];

	if (!getcwd(new_path, sizeof(new_path)))
		return ;
	add_env_list("OLDPWD", thispath);
	add_env_list("PWD", new_path);
}

static void	go_to_home(bool child_flag)
{
	int		i;

	i = 0;
	while (env()[0][i])
	{
		if (!ft_strncmp(env()[0][i], "HOME=", 5))
			break ;
		i++;
	}
	if (ft_strncmp(env()[0][i], "HOME=", 5))
	{
		ft_printf(2, "minishell: cd: HOME not set\n");
		return (builtin_return(1, child_flag));
	}
	if (chdir(env()[0][i] + 5) != 0)
	{
		ft_printf(2, "minishell: cd: %s: No such file or directory\n", \
env()[0][i] + 5);
		return (builtin_return(1, child_flag));
	}
	set_env_array();
	return (builtin_return(0, child_flag));
}

static void	change_dir(char **arg, bool child_flag)
{
	char	thispath[2000];
	char	*nextpath;

	getcwd(thispath, sizeof(thispath));
	nextpath = arg_check(arg, thispath);
	if (!nextpath)
		return (builtin_return(1, child_flag));
	if (chdir(nextpath) < 0)
	{
		if (errno == EACCES || errno == ENOENT || errno == ENOTDIR)
			ft_printf(2, "minishell: cd: %s: %s\n",
				arg[1], strerror(errno));
		else
			ft_printf(2, "minishell: cd: %s: Error\n", arg[1]);
		free(nextpath);
		return (builtin_return(1, child_flag));
	}
	set_old_pwd(thispath);
	free(nextpath);
	return (builtin_return(0, child_flag));
}

void	ft_chdir(char **arg, bool child_flag)
{
	if (len_arg(arg) == 1)
		go_to_home(child_flag);
	else if (len_arg(arg) > 2)
	{
		ft_printf(2, "minishell: cd: too many arguments\n");
		return (builtin_return(1, child_flag));
	}
	else
		change_dir(arg, child_flag);
}
