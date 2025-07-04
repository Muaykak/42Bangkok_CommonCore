/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:35 by srussame          #+#    #+#             */
/*   Updated: 2025/07/02 17:24:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	run_process(t_process *proc, int *orig_fd)
{
	int			pipe_fd[2];
	static int	prev_pipe_read = -100;

	pipe(pipe_fd);
	proc->pid = fork();
	if (proc->pid < 0)
	{
		ft_printf(2, "minishell: error: broken fork\n");
		clear_t_process();
		exit(1);
	}
	if (proc->pid == 0)
		run_process_child_proc(pipe_fd, proc, orig_fd, prev_pipe_read);
	close(pipe_fd[1]);
	if (prev_pipe_read != -100)
		close(prev_pipe_read);
	if (proc->next == NULL)
	{
		close(pipe_fd[0]);
		prev_pipe_read = -100;
	}
	else
		prev_pipe_read = pipe_fd[0];
}

void	process_v2_sub2(t_process *proc)
{
	int	orig_fd[2];
	int	last_pid;

	orig_fd[0] = dup(STDIN_FILENO);
	orig_fd[1] = dup(STDOUT_FILENO);
	while (proc)
	{
		run_process(proc, orig_fd);
		if (proc->next == NULL)
			last_pid = proc->pid;
		update_cmd_env(proc->cmd);
		proc = proc->next;
	}
	dup2(orig_fd[0], STDIN_FILENO);
	dup2(orig_fd[1], STDOUT_FILENO);
	close(orig_fd[0]);
	close(orig_fd[1]);
	ft_wait_proc(last_pid);
	clear_t_process();
}

void	process_v2_sub1_1(int *orig)
{
	dup2(orig[0], STDIN_FILENO);
	dup2(orig[1], STDOUT_FILENO);
	close(orig[0]);
	close(orig[1]);
	clear_t_process();
}

void	process_v2_sub1(t_process *proc)
{
	int	last_pid;
	int	orig[2];

	update_cmd_env(proc->cmd);
	orig[0] = dup(STDIN_FILENO);
	orig[1] = dup(STDOUT_FILENO);
	if (is_builtin_v2(proc))
	{
		if (redirect(proc, false) == false)
			return (process_v2_sub1_1(orig));
		builtin(proc, false);
		return (process_v2_sub1_1(orig));
	}
	run_process(proc, orig);
	dup2(orig[0], STDIN_FILENO);
	dup2(orig[1], STDOUT_FILENO);
	close(orig[0]);
	close(orig[1]);
	last_pid = proc->pid;
	ft_wait_proc(last_pid);
	clear_t_process();
	return ;
}

/**
 * 	srussame: NEED TO re-logic the process() function
 * 
 * 
 * **/
void	process_v2(void)
{
	t_process	*proc;

	proc = *get_t_process();
	if (!proc)
		return ;
	if (read_all_heredoc(proc) == 0)
		return ;
	if (!(proc->next))
		process_v2_sub1(proc);
	else
		process_v2_sub2(proc);
}
