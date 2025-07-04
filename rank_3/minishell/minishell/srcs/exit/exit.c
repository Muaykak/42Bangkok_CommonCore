/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:19:25 by srussame          #+#    #+#             */
/*   Updated: 2025/06/30 11:37:25 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	*ext(void)
{
	static int	ext = 0;

	return (&ext);
}

bool	is_exit(int num)
{
	if (num == 0)
		return (!*ext());
	*ext() = num;
	return (!*ext());
}
