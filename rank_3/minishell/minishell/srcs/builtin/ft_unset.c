/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:45 by srussame          #+#    #+#             */
/*   Updated: 2025/07/02 05:27:49 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_option(char **arg, bool child_flag)
{
	int	i;

	if (!arg || !(*arg))
		return (0);
	i = 0;
	while (arg[i])
	{
		if (*(arg[i]) == '-')
		{
			ft_printf(2, "minishell: unset: %s: options not allowed\n", arg[i]);
			return (builtin_return(2, child_flag), 1);
		}
		i++;
	}
	return (0);
}

void	ft_unset(char **arg, bool child_flag)
{
	int		i;

	if (len_arg(arg) == 1)
		return (builtin_return(0, child_flag));
	i = 1;
	if (check_option(&(arg[1]), child_flag) == 1)
		return ;
	while (arg[i])
		del_env_list(arg[i++]);
	return (builtin_return(0, child_flag));
}
