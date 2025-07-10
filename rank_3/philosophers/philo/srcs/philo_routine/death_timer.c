/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_timer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 07:35:14 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/10 08:05:21 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	is_philo_alive(struct timeval *death_timer)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2), false);
	if (curr_time.tv_sec < death_timer->tv_sec)
		return (true);
	if (curr_time.tv_sec > death_timer->tv_sec)
		return (false);
	if (curr_time.tv_sec == death_timer->tv_sec
		&& curr_time.tv_usec >= death_timer->tv_usec)
		return (false);
	return (true);
}

void	set_deathtimer(struct timeval *death_timer, t_thread_arg *arg)
{
	if (gettimeofday(death_timer, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2));
	death_timer->tv_sec += (arg->t_die / 1000);
	death_timer->tv_usec += (arg->t_die % 1000) * 1000;
	if (death_timer->tv_usec >= 1000000)
	{
		death_timer->tv_sec++;
		death_timer->tv_usec -= 1000000;
	}
}
