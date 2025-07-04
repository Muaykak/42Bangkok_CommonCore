/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_v2_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:20:54 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:47:45 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_cmd_path(char	*pathname)
{
	if (access(pathname, X_OK))
		return (1);
	if (ft_strchr(pathname, '/') != NULL && is_directory(pathname) == true)
		return (4);
	return (0);
}

void	exec_v2_error_exit(int exit_code)
{
	clear_t_process();
	rl_clear_history();
	env_list_clear();
	exit(exit_code);
}

void	trow_error_v2(char **cmd, int status)
{
	if (status == 0)
		return ;
	if (status == 1)
		ft_printf(2, "minishell: %s: %s\n", *cmd, strerror(errno));
	else if (status == 2)
		ft_printf(2, "minishell: %s: No such file or directory\n", *cmd);
	else if (status == 3)
		ft_printf(2, "minishell: %s: command not found\n", *cmd);
	else if (status == 4)
		ft_printf(2, "minishell: %s: Is a directory\n", *cmd);
	if (errno == EACCES || status == 4)
		*get_code() = 126;
	else
		*get_code() = 127;
	clear_line();
	clear_t_process();
	rl_clear_history();
	env_list_clear();
	exit(*get_code());
}

/*
	When the cmd dont include the path like 'ls' 'cat'
	will use $PATH to find that executable 
*/
int	get_default_cmd(char ***cmd, char **env)
{
	char	*path;
	char	*cmd_with_path;
	char	*temp;

	if (***cmd == '\0')
		return (3);
	path = get_command_path(env);
	if (!path)
		return (check_cmd_path(**cmd));
	if (*path == '\0')
		return (2);
	cmd_with_path = access_absolute(**cmd, path);
	if (!cmd_with_path)
		return (3);
	temp = **cmd;
	**cmd = cmd_with_path;
	free(temp);
	return (0);
}

void	exec_v2(char **cmd, char **env)
{
	int		status;

	if (ft_strchr(*cmd, '/') == NULL)
		status = get_default_cmd(&cmd, env);
	else
		status = check_cmd_path(*cmd);
	trow_error_v2(cmd, status);
	execve(*cmd, cmd, env);
	trow_error_v2(cmd, 1);
}
