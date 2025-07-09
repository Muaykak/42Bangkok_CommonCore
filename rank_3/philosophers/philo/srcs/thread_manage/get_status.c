/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 09:19:18 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/09 17:58:19 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	get_print_status(t_thread_arg *arg)
{
	bool	ret;
	if (!arg)
		return (false);
	if (pthread_mutex_lock(arg->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	ret = *(arg->print_status);
	if (pthread_mutex_unlock(arg->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ret);
	return (ret);
}

t_philo_status	get_philo_status(t_thread_arg *arg)
{
	t_philo_status	ret;

	if (!arg)
		return (ft_putstr_fd(RED"Error: philo: get_philo_status: \
Error occurred\n"RESET, 2), ERROR);
	if (pthread_mutex_lock(&arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ERROR);
	ret = arg->status;
	if (pthread_mutex_unlock(&arg->status_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), ret);
	return (ret);
}
