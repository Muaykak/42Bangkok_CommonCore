/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:37:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/10 08:16:22 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


bool	handle_one_philo(t_thread_arg *arg)
{
	ft_philo_wait(arg->t_die, arg);
	pthread_mutex_unlock(arg->right);
	print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD);
	return (false);
}

bool	philo_take_fork(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg || get_philo_status(arg) != ACTIVE
	|| get_print_status(arg) == false)
		return (false);
	print_philo_log(PHILO_LOG_THINK, arg, LOG_THINK);
	if (pthread_mutex_lock(arg->right) != 0)
		return (set_philo_status(arg, ERROR), false);	
	if (is_philo_alive(death_timer) == false)
		return (print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD),
		pthread_mutex_unlock(arg->right), false);
	print_philo_log(PHILO_LOG_TAKE_FORK, arg, LOG_TAKE_FORK);
	if (arg->left == NULL)
		return (handle_one_philo(arg));
	if (pthread_mutex_lock(arg->left) != 0)
		return (set_philo_status(arg, ERROR),
		pthread_mutex_unlock(arg->right), false);	
	if (is_philo_alive(death_timer) == false)
		return (print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD),
		pthread_mutex_unlock(arg->right),
		pthread_mutex_unlock(arg->left), false);
	print_philo_log(PHILO_LOG_TAKE_FORK, arg, LOG_TAKE_FORK);
	return (true);
}

bool	place_down_fork(t_thread_arg *arg)
{
	if (!arg)
		return (false);
	if (pthread_mutex_unlock(arg->right) != 0)
		ft_putstr_fd(PHILO_ERR_MSG_6, 2);
	if (pthread_mutex_unlock(arg->left) != 0)
		ft_putstr_fd(PHILO_ERR_MSG_6, 2);
	return (true);
}

void	philo_eat(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg)
		return ;
	if (get_philo_status(arg) != ACTIVE
	|| (arg->e_max != -1 && arg->eat_count >= (size_t)arg->e_max)
	|| philo_take_fork(arg, death_timer) == false)
		return ;
	print_philo_log(PHILO_LOG_EAT, arg, LOG_EAT);
	set_deathtimer(death_timer, arg);
	ft_philo_wait(arg->t_eat, arg);
	place_down_fork(arg);
	if (arg->e_max != -1)
		arg->eat_count++;
	if (arg->e_max != -1 && arg->eat_count >= (size_t)arg->e_max)
		print_philo_log(PHILO_LOG_FINISH, arg, LOG_FINISH);
	return ;
}
