/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:38 by srussame          #+#    #+#             */
/*   Updated: 2025/07/02 17:30:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_cmd_env(char **cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	if (cmd[0] == NULL)
	{
		add_env_list("_", "");
		return ;
	}
	while (cmd[i + 1] != NULL)
		i++;
	add_env_list("_", cmd[i]);
}

int	len_process(void)
{
	t_process	*proc;
	int			len;

	proc = *get_t_process();
	len = 0;
	while (proc)
	{
		proc = proc->next;
		len++;
	}
	return (len);
}

int	is_builtin_v2(t_process *proc)
{
	if (!ft_strncmp(proc->cmd[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "env", 4))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "export", 7))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "unset", 6))
		return (1);
	else if (!ft_strncmp(proc->cmd[0], "exit", 5))
		return (1);
	else
		return (0);
}

void	ft_wait_proc(pid_t last_pid)
{
	int			temp_code;
	t_process	*proc;

	temp_code = 0;
	proc = *get_t_process();
	signal_minishell_mode_wait();
	while (proc)
	{
		if (proc->pid > 0)
			waitpid(proc->pid, &temp_code, 0);
		if (proc->pid == last_pid)
		{
			if (WIFEXITED(temp_code) || __WCOREDUMP(temp_code))
				*get_code() = (temp_code % 255);
			else
				*get_code() = (temp_code % 255) + 128;
		}
		proc = proc->next;
	}
	signal_allignore();
	*sigint_status() = 0;
}

void	run_process_child_proc(int *pipe_fd, t_process *proc, \
int *orig_fd, int prev_pipe_read)
{
	set_default_signal();
	close(orig_fd[0]);
	close(orig_fd[1]);
	close(pipe_fd[0]);
	if (proc->pipe_pos != FIRST && prev_pipe_read != -100)
		dup2(prev_pipe_read, 0);
	if (prev_pipe_read != -100)
		close(prev_pipe_read);
	if (proc->next != NULL)
		dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	if (redirect(proc, true) == false)
	{
		clear_t_process();
		clear_line();
		rl_clear_history();
		env_list_clear();
		exit(*get_code());
	}
	if (is_builtin_v2(proc))
		builtin(proc, true);
	else
		exec_v2(proc->cmd, *env());
}
