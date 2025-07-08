/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-08 11:32:29 by muaykak           #+#    #+#             */
/*   Updated: 2025-07-08 11:32:29 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*philo_routine(void *ptr)
{
	t_thread_arg	*arg;

	if (!ptr)
		return (NULL);
	arg = (t_thread_arg *)ptr;
	while (get_philo_status(arg) == ACTIVE)
	{

	}
}
