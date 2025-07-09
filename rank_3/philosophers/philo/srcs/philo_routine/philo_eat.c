/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:37:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/09 11:07:19 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	is_philo_alive(struct timeval death_timer)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)

}

void	philo_take_fork(t_thread_arg *arg)
{
	struct timeval	death_timer;

	if (!arg || get_philo_status(arg) != ACTIVE)
		return ;	
	gettimeofday(&death_timer, NULL);
	if (pthread_mutex_lock(arg->right) != 0)
		return ((void)set_philo_status(arg, ERROR));
	
}

void	philo_eat(t_thread_arg *arg)
{
	if (!arg)
		return ;
	if (get_philo_status(arg) != ACTIVE)
		return ;	
}
