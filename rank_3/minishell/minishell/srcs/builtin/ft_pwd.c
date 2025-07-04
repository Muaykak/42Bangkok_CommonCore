/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:43 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:42:50 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(char **arg, bool child_flag)
{
	char	thispath[1024];
	char	*pwd_env;

	(void)arg;
	if (!getcwd(thispath, sizeof(thispath)))
	{
		pwd_env = get_env_value("PWD");
		ft_printf(1, "%s\n", pwd_env);
		free(pwd_env);
		return (builtin_return(0, child_flag));
	}
	ft_printf(1, "%s\n", thispath);
	return (builtin_return(0, child_flag));
}
