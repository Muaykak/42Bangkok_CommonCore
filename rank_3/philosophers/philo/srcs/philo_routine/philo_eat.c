/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:37:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/09 14:38:12 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	is_philo_alive(struct timeval *death_timer, t_thread_arg *arg)
{
	struct timeval	curr_time;
	size_t			result;

	if (gettimeofday(&curr_time, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2), false);
	result = 0;
	if (curr_time.tv_usec < death_timer->tv_usec)
	{
		curr_time.tv_sec--;
		result += (curr_time.tv_usec + 1000000 - death_timer->tv_usec) / 1000;
	}
	else
		result += (curr_time.tv_usec - death_timer->tv_usec) / 1000;
	result += (curr_time.tv_sec - death_timer->tv_sec) * 1000;
	if (result >= (size_t)arg->t_die || get_print_status(arg) == false)
		return (false);
	return (true);
}

bool	philo_take_fork(t_thread_arg *arg)
{
	struct timeval	death_timer;

	if (!arg || get_philo_status(arg) != ACTIVE
	|| get_print_status(arg) == false)
		return (false);
	print_philo_log(PHILO_LOG_THINK, arg, LOG_THINK);
	gettimeofday(&death_timer, NULL);
	if (pthread_mutex_lock(arg->right) != 0)
		return (set_philo_status(arg, ERROR), false);	
	if (is_philo_alive(&death_timer, arg) == false)
		return (print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD),
		pthread_mutex_unlock(arg->right), false);
	print_philo_log(PHILO_LOG_TAKE_FORK, arg, LOG_DEAD);
	if (pthread_mutex_lock(arg->left) != 0)
		return (set_philo_status(arg, ERROR),
		pthread_mutex_unlock(arg->right), false);	
	if (is_philo_alive(&death_timer, arg) == false)
		return (print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD),
		pthread_mutex_unlock(arg->right),
		pthread_mutex_unlock(arg->left), false);
	print_philo_log(PHILO_LOG_TAKE_FORK, arg, LOG_TAKE_FORK);
	return (true);
}

void	philo_eat(t_thread_arg *arg)
{
	if (!arg)
		return ;
	if (get_philo_status(arg) != ACTIVE
	|| (arg->e_max != -1 && arg->eat_count >= (size_t)arg->e_max)
	|| philo_take_fork(arg) == false)
		return ;
	print_philo_log(PHILO_LOG_EAT, arg, LOG_EAT);
	ft_philo_wait(arg->t_eat, arg);
	if (arg->e_max != -1)
		arg->eat_count++;
	if (arg->e_max != -1 && arg->eat_count >= (size_t)arg->e_max)
		print_philo_log(PHILO_LOG_FINISH, arg, LOG_FINISH);
	return ;
}
