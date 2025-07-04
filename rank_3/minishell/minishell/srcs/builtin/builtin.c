/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:06 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:42:21 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit_builtin_return(int exit_code, bool child_flag)
{
	if (child_flag == false)
	{
		*get_code() = exit_code;
		is_exit(1);
		return ;
	}
	clear_line();
	clear_t_process();
	rl_clear_history();
	env_list_clear();
	exit(exit_code);
}

void	builtin_return(int return_value, bool child_flag)
{
	if (child_flag == false)
	{
		*get_code() = return_value;
		return ;
	}
	clear_t_process();
	clear_line();
	rl_clear_history();
	env_list_clear();
	exit(return_value);
}

int	len_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	use_function(t_process *proc, t_use_function func, bool child_flag)
{
	if (func == FT_CD)
		ft_chdir(proc->cmd, child_flag);
	else if (func == FT_ECHO)
		ft_echo(proc->cmd, child_flag);
	else if (func == FT_PWD)
		ft_pwd(proc->cmd, child_flag);
	else if (func == FT_ENV)
		ft_env(proc->cmd, child_flag);
	else if (func == FT_EXPORT)
		ft_export(proc->cmd, child_flag);
	else if (func == FT_UNSET)
		ft_unset(proc->cmd, child_flag);
	else if (func == FT_EXIT)
		ft_exit(proc, child_flag);
}

int	builtin(t_process *proc, bool child_flag)
{
	if (proc->cmd[0] == NULL)
		return (builtin_return(0, child_flag), 0);
	if (!ft_strncmp(proc->cmd[0], "cd", 3))
		use_function(proc, FT_CD, child_flag);
	else if (!ft_strncmp(proc->cmd[0], "echo", 5))
		use_function(proc, FT_ECHO, child_flag);
	else if (!ft_strncmp(proc->cmd[0], "pwd", 4))
		use_function(proc, FT_PWD, child_flag);
	else if (!ft_strncmp(proc->cmd[0], "env", 4))
		use_function(proc, FT_ENV, child_flag);
	else if (!ft_strncmp(proc->cmd[0], "export", 7))
		use_function(proc, FT_EXPORT, child_flag);
	else if (!ft_strncmp(proc->cmd[0], "unset", 7))
		use_function(proc, FT_UNSET, child_flag);
	else if (!ft_strncmp(proc->cmd[0], "exit", 5))
		use_function(proc, FT_EXIT, child_flag);
	else
		return (builtin_return(0, child_flag), 0);
	return (1);
}
