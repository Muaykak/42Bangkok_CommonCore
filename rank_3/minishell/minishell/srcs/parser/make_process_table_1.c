/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_process_table_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 07:15:58 by srussame          #+#    #+#             */
/*   Updated: 2025/06/28 10:20:11 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	move_to_next_word_to_process(t_word_struct **wordlist)
{
	if (!wordlist || !(*wordlist))
		return ;
	while ((*wordlist) && (*wordlist)->word_type != PIPE)
		(*wordlist) = (*wordlist)->next_word;
	if ((*wordlist) && (*wordlist)->word_type == PIPE)
		(*wordlist) = (*wordlist)->next_word;
}

t_process	*get_next_process(t_word_struct **wordlist)
{
	char		**new_cmd;
	t_redirect	*redirect_list;
	t_process	*new_process;

	if (!wordlist || !(*wordlist))
		return (NULL);
	new_cmd = get_new_cmd(*wordlist);
	if (!new_cmd)
		return (NULL);
	redirect_list = get_redirect_list(*wordlist);
	new_process = ft_calloc(1, sizeof(t_process));
	if (!new_process)
		return (clear_cmd_char(&new_cmd), redirect_lstclear(&redirect_list),
			NULL);
	new_process->cmd = new_cmd;
	new_process->redirect = redirect_list;
	move_to_next_word_to_process(wordlist);
	return (new_process);
}

bool	process_list_addback(t_process **list, t_process *new)
{
	t_process	*temp;

	if (!list || !new)
		return (false);
	if (!(*list))
	{
		new->pipe_pos = FIRST;
		(*list) = new;
		return (true);
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->pipe_pos = MIDDLE;
	new->pipe_pos = LAST;
	temp->next = new;
	return (true);
}

void	process_list_lstclear(t_process **process_list)
{
	t_process	*temp;

	if (!process_list || !(*process_list))
		return ;
	while (*process_list)
	{
		temp = (*process_list)->next;
		if ((*process_list)->cmd)
			clear_cmd_char(&((*process_list)->cmd));
		if ((*process_list)->redirect)
			redirect_lstclear(&((*process_list)->redirect));
		free(*process_list);
		*process_list = temp;
	}
	*process_list = NULL;
}

t_process	*create_process_list(t_word_struct **wordlist)
{
	t_word_struct	*temp;
	t_process		*new_process;
	t_process		*process_list;

	if (!wordlist || !(*wordlist))
		return (NULL);
	temp = (*wordlist);
	process_list = NULL;
	new_process = get_next_process(&temp);
	while (new_process != NULL)
	{
		if (process_list_addback(&process_list, new_process) == false)
			return (process_list_lstclear(&process_list), NULL);
		new_process = get_next_process(&temp);
	}
	word_struct_lstclear(wordlist);
	*wordlist = NULL;
	return (process_list);
}

// // Debug print can delete anytime
// void	print_process_list(t_process *proc)
// {
// 	int			i;
// 	int			j;
// 	t_redirect	*redir;
// 	int			r;
// 
// 	i = 0;
// 	while (proc)
// 	{
// 		printf("=== Process %d ===\n", i);
// 		j = 0;
// 		while (proc->cmd && proc->cmd[j])
// 		{
// 			printf("cmd[%d] = %s\n", j, proc->cmd[j]);
// 			j++;
// 		}
// 		redir = proc->redirect;
// 		r = 0;
// 		while (redir)
// 		{
// 			printf("redir[%d] type = %d, value = %s\n", r, redir->type,
// 				redir->value);
// 			redir = redir->next;
// 			r++;
// 		}
// 		i++;
// 		proc = proc->next;
// 	}
// }
