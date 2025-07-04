/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_signal_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:22:01 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:45:37 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	signal_minishell_mode_heredoc(void)
{
	signal(SIGINT, &sigint_handler_mode_heredoc);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

void	signal_minishell_mode_wait(void)
{
	signal(SIGINT, &sig_handler_mode_wait);
	signal(SIGQUIT, &sig_handler_mode_wait);
	return ;
}

void	signal_minishell_mode_1(void)
{
	signal(SIGINT, &sigint_handler_mode_1);
	signal(SIGQUIT, SIG_IGN);
	return ;
}

void	signal_allignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_default_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
