/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-08 11:37:55 by muaykak           #+#    #+#             */
/*   Updated: 2025-07-08 11:37:55 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philo_take_fork(t_thread_arg *arg)
{
	if (!arg || get_philo_status(arg) != ACTIVE)
		return ;	
}

void	philo_eat(t_thread_arg *arg)
{
	struct timeval	death_timer;
	
	if (!arg)
		return ;
	if (get_philo_status(arg) != ACTIVE)
		return ;	
	gettimeofday(&death_timer, NULL);

}
