/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 04:04:34 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/02 04:07:42 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	should contain only 1 symbol '+' || '-' 
	only 1 number  can have whitespace between
	but not any other special characters 
*/
int	is_one_number(char *cmd)
{
	char	c;

	while (ft_isspace(*cmd))
		cmd++;
	if (*cmd == '\0' || ((*cmd == '-' || *cmd == '+')
			&& !ft_isdigit(*(cmd + 1))))
		return (0);
	c = '\0';
	if (*cmd == '+' || *cmd == '-')
	{
		c = *cmd;
		cmd++;
	}
	while (*cmd != '\0' && ft_isdigit(*cmd))
		cmd++;
	while (*cmd != '\0' && ft_isspace(*cmd))
		cmd++;
	if (*cmd != '\0')
		return (0);
	if (c == '\0' || c == '+')
		return (1);
	return (-1);
}

/*
	The limit number that exit recieved
	is 2^63 -1 in positive and 2^63 in negative
*/
bool	check_is_outlimit(char *cmd, int sign_flag)
{
	while (!ft_isdigit(*cmd))
		cmd++;
	while (*cmd == '0')
		cmd++;
	if (*cmd == '\0')
		return (false);
	if (sign_flag > 0)
		return (strnum_cmp_ismorethan(cmd, "9223372036854775807"));
	else
		return (strnum_cmp_ismorethan(cmd, "9223372036854775808"));
}

int	check_arg(char **cmd, bool child_flag)
{
	int	ret;

	ret = is_one_number(cmd[1]);
	if (ret == 0 || check_is_outlimit(cmd[1], ret) == true)
	{
		ft_printf(2, "minishell: exit: %s: numeric \
argument required\n", cmd[1]);
		return (ft_exit_builtin_return(2, child_flag), 2);
	}
	if (cmd[2] != NULL)
	{
		ft_printf(2, "minishell: exit: too many arguments\n");
		*get_code() = 1;
		return (1);
	}
	return (0);
}

void	ft_exit(t_process *proc, bool child_flag)
{
	if ((proc->cmd)[1] == NULL)
		return (ft_exit_builtin_return(0, child_flag));
	if (check_arg(proc->cmd, child_flag) != 0)
		return ;
	return (ft_exit_builtin_return(convert_exit_code((proc->cmd)[1]),
		child_flag));
}
