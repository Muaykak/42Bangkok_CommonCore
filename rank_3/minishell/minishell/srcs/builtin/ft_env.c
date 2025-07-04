/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:18:31 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:34:29 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(char **arg, bool child_flag)
{
	if (len_arg(arg) != 1)
	{
		ft_printf(2, "minishell: env: too many arguments\n");
		return (builtin_return(1, child_flag));
	}
	print_env();
	return (builtin_return(0, child_flag));
}
