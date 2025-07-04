/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_essential_env_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:21 by srussame          #+#    #+#             */
/*   Updated: 2025/07/01 17:59:53 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_start_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return ;
	add_env_list("PWD", cwd);
	free(cwd);
	return ;
}

/* Set up SHLVL */
void	setup_shlvl(void)
{
	t_env	*shlvl;
	int		old_shlvl;

	shlvl = search_env("SHLVL");
	if (shlvl == NULL)
	{
		add_env_list("SHLVL", "1");
		return ;
	}
	old_shlvl = ft_atoi(shlvl->value);
	free(shlvl->value);
	shlvl->value = ft_itoa(old_shlvl + 1);
}

void	set_oldpwd(void)
{
	if (search_env("OLDPWD") != NULL)
		return ;
	add_env_list("OLDPWD", NULL);
}

void	set_essential_env(void)
{
	setup_shlvl();
	set_start_pwd();
	set_oldpwd();
}
