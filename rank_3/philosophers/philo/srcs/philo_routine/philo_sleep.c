/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:41:19 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/10 07:53:19 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philo_sleep(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg || get_philo_status(arg) != ACTIVE
	|| get_print_status(arg) == false)
		return ;
	if (is_philo_alive(death_timer) == false)	
		return ((void)print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD));
	print_philo_log(PHILO_LOG_SLEEP, arg, LOG_SLEEP);
	ft_philo_wait(arg->t_slp, arg);
	if (is_philo_alive(death_timer) == false)	
		return ((void)print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD));
	return ;
}
