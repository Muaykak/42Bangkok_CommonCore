/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:41 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:46:13 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	find_char(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
			return (true);
		i++;
	}
	ft_printf(2, "minishell: export: %s: not a valid identifier\n", arg);
	*get_code() = 1;
	return (false);
}

bool	check_first_char(char *arg)
{
	if (*arg == '=')
	{
		ft_printf(2, "minishell: export: %s: not a valid identifier\n", arg);
		*get_code() = 1;
		return (true);
	}
	if (*arg == '-')
	{
		ft_printf(2, "minishell: export: %s: not allow options\n", arg);
		*get_code() = 2;
		return (true);
	}
	if (ft_isdigit(*arg) == 1)
	{
		ft_printf(2, "minishell: export: %s: not a valid identifier\n", arg);
		*get_code() = 1;
		return (true);
	}
	return (false);
}

bool	export_error(char *arg)
{
	int	i;

	i = 0;
	if (check_first_char(arg) == true)
		return (true);
	while (arg[i] && arg[i] != '=')
	{
		if (ft_isalpha(arg[i])
			|| arg[i] == '_'
			|| ft_isalnum(arg[i]))
			i++;
		else
		{
			ft_printf(2, "minishell: export: %s: \
not a valid identifier\n", arg);
			*get_code() = 1;
			return (true);
		}
	}
	return (false);
}

void	set_export(char **arg, bool child_flag)
{
	int		i;
	char	**temp;

	i = 1;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '=') != NULL)
		{
			temp = ft_split_keyvalue(arg[i]);
			if (temp[1] == NULL)
				add_env_list(temp[0], "");
			else
				add_env_list(temp[0], temp[1]);
			free_split(temp);
		}
		else
			add_env_list(arg[i], NULL);
		i++;
	}
	return (builtin_return(0, child_flag));
}

void	ft_export(char **arg, bool child_flag)
{
	int		string_set;

	if (len_arg(arg) == 1)
	{
		print_env_list();
		return (builtin_return(0, child_flag));
	}
	string_set = 1;
	while (arg[string_set])
	{
		if (export_error(arg[string_set]) == true)
			return (builtin_return(*get_code(), child_flag));
		string_set++;
	}
	set_export(arg, child_flag);
	return (builtin_return(0, child_flag));
}
