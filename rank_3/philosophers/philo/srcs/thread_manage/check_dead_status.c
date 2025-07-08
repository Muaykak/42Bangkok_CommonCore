/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 07:54:42 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/08 09:16:33 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_status	check_dead_status(t_thread_arg *thread_arg)
{
	t_philo_status	ret;

	if (!thread_arg)
		return (ft_putstr_fd(RED"Error: philo: check_dead_status(): \
The argument is null\n"RESET, 2), ERROR);
	if (pthread_mutex_lock(&thread_arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ERROR);
	ret = thread_arg->status;
	if (pthread_mutex_unlock(&thread_arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ERROR);
	return (ret);
}
