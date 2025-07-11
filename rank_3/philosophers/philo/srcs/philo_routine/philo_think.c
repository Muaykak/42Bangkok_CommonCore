/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:43:00 by srussame          #+#    #+#             */
/*   Updated: 2025/07/12 01:14:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	wait_algorithm(t_thread_arg *arg, struct timeval *death_timer)
{
	struct timeval	curr_time;
	int				time_left;
	int				time_think;

	if (gettimeofday(&curr_time, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2));
//	printf("death_timer sec: %ld usec: %ld\n", death_timer->tv_sec, death_timer->tv_usec);
//	printf("curr_time sec: %ld usec: %ld\n", curr_time.tv_sec, curr_time.tv_usec);
	if (death_timer->tv_usec < curr_time.tv_usec)	
	{
		curr_time.tv_sec++;
		time_left = (death_timer->tv_usec + 1000000 - curr_time.tv_usec) / 1000;
	}
	else
		time_left = (death_timer->tv_usec - curr_time.tv_usec) / 1000;
	time_left += (death_timer->tv_sec - curr_time.tv_sec) * 1000;
	time_think =  time_left / 10;

	if (time_think < 1)
		return ;
	ft_philo_wait(time_think, arg, death_timer);
}

void	philo_think(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg || arg->status != ACTIVE
	|| get_print_status(arg) == false)
		return ;
	if (is_philo_alive(death_timer) == false)
		return ((void)print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD));
	print_philo_log(PHILO_LOG_THINK, arg, LOG_THINK);
	wait_algorithm(arg, death_timer);
}
