/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:17:53 by srussame          #+#    #+#             */
/*   Updated: 2025/07/02 16:36:56 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_operation(char *lineread)
{
	char	**line_split;
	int		i;

	*line() = split_newline(lineread);
	free(lineread);
	line_split = *line();
	if (!line_split)
		return ;
	i = 0;
	while (line_split[i] != NULL && is_exit(0))
	{
		*get_t_process() = parser(&(line_split[i]));
		process_v2();
		clear_t_process();
		i++;
	}
	clear_line();
}

	// char	*nontrim;
	// 	if (isatty(STDIN_FILENO))
	// 		lineread = readline("minishell> ");
	// 	else
	// 	{
	// 		write(STDIN_FILENO, "minishell> ", 11);
	// 		nontrim = get_next_line(STDIN_FILENO);
	// 		lineread = ft_strtrim(nontrim, "\n");
	// 		free(nontrim);
	// 	}

	// 	if (isatty(STDERR_FILENO))

void	prompt(void)
{
	char	*lineread;

	while (is_exit(0))
	{
		signal_minishell_mode_1();
		lineread = readline("minishell> ");
		signal_allignore();
		if (!lineread)
			break ;
		add_history(lineread);
		shell_operation(lineread);
		clear_t_process();
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	env_initialize(&(*envp));
	prompt();
	env_list_clear();
	return (*get_code());
}
