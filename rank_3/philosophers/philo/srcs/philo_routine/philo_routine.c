/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:32:29 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/10 07:41:34 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	wait_all_thread(t_thread_arg *arg)
{
	if (pthread_mutex_lock(arg->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2));
	if (pthread_mutex_unlock(arg->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2));
}

void	*philo_routine(void *ptr)
{
	t_thread_arg	*arg;
	struct timeval	death_timer;

	if (!ptr)
		return (NULL);
	arg = (t_thread_arg *)ptr;
	wait_all_thread(arg);
	set_deathtimer(&death_timer, arg);
	while (arg->status == ACTIVE && get_print_status(arg) == true)
	{
		philo_eat(arg, &death_timer);
		philo_sleep(arg, &death_timer);
	}
	return (NULL);
}
