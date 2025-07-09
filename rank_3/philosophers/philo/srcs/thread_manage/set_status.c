/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:18:39 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/09 09:43:32 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	set_print_status(t_thread_arg *arg, bool new_status)
{
	if (!arg)
		return (false);
	if (pthread_mutex_lock(arg->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	*(arg->print_status) = new_status;
	if (pthread_mutex_unlock(arg->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	return (true);
}

bool	set_philo_status(t_thread_arg *arg, t_philo_status new_status)
{

	if (!arg)
		return (ft_putstr_fd(RED"Error: philo: set_philo_status(): \
The argument is null\n"RESET, 2), false);
	if (pthread_mutex_lock(&arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	arg->status = new_status;
	if (pthread_mutex_unlock(&arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	return (true);
}
