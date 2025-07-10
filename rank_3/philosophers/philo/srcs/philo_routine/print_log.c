/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:05:09 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/09 18:23:42 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static size_t	timestamp_calculation(t_thread_arg *arg)
{
	size_t			return_value;
	struct timeval	curr_time;

	if (!arg)
		return (0);
	if(gettimeofday(&curr_time, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2), 0);
	return_value = 0;
	if (curr_time.tv_usec < (arg->start_time->tv_usec))
	{
		curr_time.tv_sec--;
		return_value += ((curr_time.tv_usec + 1000000 - arg\
->start_time->tv_usec) / 1000);
	}
	else
		return_value += (curr_time.tv_usec - arg->start_time->tv_usec) / 1000;
	return_value += (curr_time.tv_sec - arg->start_time->tv_sec) * 1000;
	return (return_value);
}

bool	print_philo_log(char *str, t_thread_arg *arg, t_log_status status)
{
	if (!str || !arg)
		return (ft_putstr_fd(RED"Error: philo: print_philo_log: arguments \
cannot be null\n"RESET, 2), false);
	if (*(arg->print_status) == true)
	{
		if (status == LOG_DEAD)
		{
			*(arg->print_status) = false;
			arg->status = DEAD;
		}
		else if (status == LOG_FINISH)
			arg->status = FINISH;
		if (pthread_mutex_lock(arg->print_lock) != 0)
			return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
		printf("%zu ms\t:"YELLOW"%d"RESET" %s\n",
			timestamp_calculation(arg), arg->thread_num, str);
		if (pthread_mutex_unlock(arg->print_lock) != 0)	
			return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	}
	return (true);
}
