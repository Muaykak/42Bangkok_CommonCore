/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_static.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:04:33 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 16:07:41 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	***env(void)
{
	static char	**env = NULL;

	return (&env);
}

t_env	**get_t_env(void)
{
	static t_env	*env;

	return (&env);
}
