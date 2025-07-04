/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:21:32 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:41:50 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_directory(char *pathname)
{
	struct stat	file_stat;

	if (!pathname)
		return (false);
	ft_memset(&file_stat, 0, sizeof(file_stat));
	if (stat(pathname, &file_stat))
		return (false);
	if (S_ISDIR(file_stat.st_mode))
		return (true);
	return (false);
}
