/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_signal_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:59 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:45:30 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler_mode_1(int signum)
{
	write(STDOUT_FILENO, "\n", 1);
	clear_line();
	clear_t_process();
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	*get_code() = signum + 128;
}

// ioctl(STDIN_FILENO, TIOCSTI, "\n");
//write(1, "\n", 1);
void	sigint_handler_mode_heredoc(int signum)
{
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 1);
	*get_code() = signum + 128;
	*sigint_status() = signum + 128;
}

void	sig_all_child(void)
{
	t_process	*proc;

	proc = *get_t_process();
	while (proc)
	{
		if (proc->pid > 0)
		{
			kill(proc->pid, (int)(*sigint_status()));
		}
		proc = proc->next;
	}
	if (*sigint_status() == SIGQUIT)
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	else
		write(STDOUT_FILENO, "\n", 1);
}

void	sig_handler_mode_wait(int signum)
{
	*sigint_status() = signum;
	sig_all_child();
	rl_on_new_line();
	rl_replace_line("", 1);
}
