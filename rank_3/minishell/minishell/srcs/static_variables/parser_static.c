/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_static.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:04:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 11:04:56 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	***line(void)
{
	static char	**line_split = NULL;

	return (&line_split);
}

void	clear_line(void)
{
	char	**temp;
	int		i;

	temp = *line();
	i = 0;
	while (temp && temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	*line() = NULL;
}
