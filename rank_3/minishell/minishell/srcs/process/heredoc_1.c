/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:23 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:41:21 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*create_name_temp_file(int id)
{
	char	*heredoc;
	char	*name_id;
	char	*res;

	heredoc = "/tmp/heredoc_";
	name_id = ft_itoa(id);
	res = ft_strjoin(heredoc, name_id);
	free(name_id);
	return (res);
}

void	end_heredoc(t_redirect *re, char *name_file, int fd)
{
	if (fd > 0)
		close(fd);
	free(re->value);
	re->value = name_file;
}

static int	ft_heredoc_sub1(char **line, t_redirect *redirect)
{
	signal_minishell_mode_heredoc();
	*line = readline("> ");
	signal_allignore();
	if (*sigint_status() != 0)
	{
		*sigint_status() = 0;
		return (3);
	}
	if (!(*line))
		return (2);
	if (!ft_strncmp(redirect->value, *line, ft_strlen(redirect->value)) \
&& ft_strlen(*line) == ft_strlen(redirect->value))
		return (1);
	return (0);
}

int	ft_heredoc(t_redirect *redirect)
{
	static int	id = 0;
	int			fd;
	char		*name_file;
	char		*line;
	int			ret;

	name_file = create_name_temp_file(id++);
	fd = open(name_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line = NULL;
		ret = ft_heredoc_sub1(&line, redirect);
		if (ret != 0)
			break ;
		if (redirect->expand == true)
			expand_heredoc_line(&line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	end_heredoc(redirect, name_file, fd);
	free(line);
	if (ret == 2)
		ft_printf(2, HEREDOC_ERR, redirect->value);
	return (ret);
}

int	read_all_heredoc(t_process *proc)
{
	t_redirect	*re;

	while (proc)
	{
		re = proc->redirect;
		while (re)
		{
			if (re->type == HERE_DOC)
			{
				if (ft_heredoc(re) == 3)
					return (0);
			}
			re = re->next;
		}
		proc = proc->next;
	}
	signal_allignore();
	return (1);
}
