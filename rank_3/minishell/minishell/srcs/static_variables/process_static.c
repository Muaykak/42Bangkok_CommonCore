/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:05:02 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/01 11:05:03 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_process	**get_t_process(void)
{
	static t_process	*process = NULL;

	return (&process);
}
