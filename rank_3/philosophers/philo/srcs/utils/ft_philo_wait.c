/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:58:54 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/12 08:52:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	finish_time(struct timeval *result, int time_ms)
{
	if (!result)
		return (false);
	if (gettimeofday(result, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2), false);
	result->tv_sec += (time_ms / 1000);
	result->tv_usec += (time_ms % 1000) * 1000;
	if (result->tv_usec >= 1000000)
	{
		result->tv_sec++;
		result->tv_usec -= 1000000;
	}
	return (true);
}

bool	is_finish_wait(struct timeval *end_wait)
{
	struct timeval	curr_time;

	if (!end_wait)
		return (false);
	if (gettimeofday(&curr_time, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2), false);
	if (curr_time.tv_sec < end_wait->tv_sec)
		return (false);
	if (curr_time.tv_sec > end_wait->tv_sec)
		return (true);
	if ((curr_time.tv_sec == end_wait->tv_sec)
		&& (curr_time.tv_usec >= end_wait->tv_usec))
		return (true);
	return (false);
}

void	ft_philo_wait(int time_ms, t_thread_arg *arg,
			struct timeval *death_timer)
{
	struct timeval	end_wait;

	if (!arg || time_ms < 1)
		return ;
	if (finish_time(&end_wait, time_ms) == false)
		return ;
	while (get_print_status(arg) == true && is_finish_wait(&end_wait) == false)
	{
		if (death_timer != NULL && is_philo_alive(death_timer) == false)
			return ;
		usleep(10);
	}
	return ;
}
