/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:06:51 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/08 14:17:04 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	set_philo_status(t_thread_arg *arg, t_philo_status new_status)
{

	if (!arg)
		return (ft_putstr_fd(RED"Error: philo: set_philo_routine(): \
The argument is null\n"RESET, 2), false);
	if (pthread_mutex_lock(&arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	arg->status = new_status;
	if (pthread_mutex_unlock(&arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	return (true);
}
