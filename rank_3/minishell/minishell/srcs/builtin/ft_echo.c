/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:38 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:34:11 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	check_n_option(char *option)
{
	int	i;

	if (!option)
		return (false);
	i = 1;
	if (option[0] == '\0' || option[0] != '-'
		|| option[1] == '\0' || option[1] != 'n')
		return (false);
	while (option[i] != '\0')
	{
		if (option[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

static void	print_arg(char **arg)
{
	int		i;

	i = 0;
	while (check_n_option(arg[i]) == true)
		i++;
	while (arg[i])
	{
		ft_printf(1, "%s", arg[i]);
		if (arg[i + 1])
			ft_printf(1, " ");
		i++;
	}
}

void	ft_echo(char **arg, bool child_flag)
{
	if (len_arg(arg) == 1)
		ft_printf(1, "\n");
	else if (len_arg(arg) >= 2)
	{
		if (check_n_option(arg[1]) == true)
			print_arg(&arg[2]);
		else
		{
			print_arg(&arg[1]);
			ft_printf(1, "\n");
		}
	}
	else
	{
		print_arg(&arg[1]);
		ft_printf(1, "\n");
	}
	return (builtin_return(0, child_flag));
}
