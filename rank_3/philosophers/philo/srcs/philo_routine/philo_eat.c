/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:37:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/10 18:00:23 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


bool	handle_one_philo(t_thread_arg *arg, struct timeval *death_timer)
{
	while (is_philo_alive(death_timer) == true)
	{
	}
	print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD);
	return (false);
}

void	wait_algorithm(t_thread_arg *arg, struct timeval *death_timer)
{
	struct timeval	curr_time;
	int				result;

	if (gettimeofday(&curr_time, NULL) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_7, 2));
	if (curr_time.tv_usec < death_timer->tv_usec)	
	{
		curr_time.tv_sec--;
		result = (curr_time.tv_usec + 1000000 - death_timer->tv_usec) / 1000;
	}
	else
		result = (curr_time.tv_usec - death_timer->tv_usec) / 1000;
	result += (curr_time.tv_sec - death_timer->tv_sec) * 1000;
	result = (result - (arg->t_eat + arg->t_slp)) / 5;
	if (result < 1)
		return ;
	printf("result: %d\n", result);
	ft_philo_wait(result, arg, death_timer);
}

bool	grabbing_fork(t_philo_fork *fork, struct timeval *death_timer, t_thread_arg *arg)
{
	while (is_philo_alive(death_timer) == true && get_print_status(arg) == true)
	{
		if (pthread_mutex_lock(&(fork->lock)) != 0)
			return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
		if (fork->is_using == false)
		{
			fork->is_using = true;
			if (pthread_mutex_unlock(&(fork->lock)) != 0)
				return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
			return (true);
		}
		if (pthread_mutex_unlock(&(fork->lock)) != 0)
			return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	}
	return (false);
}

bool	taking_fork(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg || arg->status != ACTIVE
	|| get_print_status(arg) == false)
		return (false);
	print_philo_log(PHILO_LOG_THINK, arg, LOG_THINK);
	if (grabbing_fork(arg->right, death_timer, arg) == false)
		return (print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD), false);
	print_philo_log(PHILO_LOG_TAKE_FORK, arg, LOG_TAKE_FORK);
	if (arg->left == NULL)
		return (handle_one_philo(arg, death_timer));
	if (grabbing_fork(arg->left, death_timer, arg) == false)
		return (print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD), false);
	print_philo_log(PHILO_LOG_TAKE_FORK, arg, LOG_TAKE_FORK);
	return (true);
}

bool	place_down_fork(t_thread_arg *arg)
{
	if (!arg)
		return (false);
	if (pthread_mutex_lock(&arg->right->lock) != 0)
		ft_putstr_fd(PHILO_ERR_MSG_6, 2);
	arg->right->is_using = false;
	if (pthread_mutex_unlock(&arg->right->lock) != 0)
		ft_putstr_fd(PHILO_ERR_MSG_6, 2);
	if (pthread_mutex_lock(&arg->left->lock) != 0)
		ft_putstr_fd(PHILO_ERR_MSG_6, 2);
	arg->left->is_using = false;
	if (pthread_mutex_unlock(&arg->left->lock) != 0)
		ft_putstr_fd(PHILO_ERR_MSG_6, 2);
	return (true);
}

void	philo_eat(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg)
		return ;
	if (arg->status != ACTIVE
	|| (arg->e_max != -1 && arg->eat_count >= (size_t)arg->e_max)
	|| taking_fork(arg, death_timer) == false)
		return ;
	print_philo_log(PHILO_LOG_EAT, arg, LOG_EAT);
	set_deathtimer(death_timer, arg);
	ft_philo_wait(arg->t_eat, arg, NULL);
	if (is_philo_alive(death_timer) == false)
		return ((void)print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD));
	place_down_fork(arg);
	if (arg->e_max != -1)
		arg->eat_count++;
	if (arg->e_max != -1 && arg->eat_count >= (size_t)arg->e_max)
		print_philo_log(PHILO_LOG_FINISH, arg, LOG_FINISH);
	return ;
}
