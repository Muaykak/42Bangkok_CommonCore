/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:37:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/12 00:48:35 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


bool	handle_one_philo(t_thread_arg *arg, struct timeval *death_timer)
{
	while (is_philo_alive(death_timer) == true)
		continue;
	print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD);
	return (false);
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
//	print_philo_log(PHILO_LOG_THINK, arg, LOG_THINK);
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
