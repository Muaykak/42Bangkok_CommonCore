/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:41:19 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/12 06:27:36 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	philo_sleep(t_thread_arg *arg, struct timeval *death_timer)
{
	if (!arg || arg->status != ACTIVE
		|| get_print_status(arg) == false)
		return ;
	if (is_philo_alive(death_timer) == false)
		return ((void)print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD));
	print_philo_log(PHILO_LOG_SLEEP, arg, LOG_SLEEP);
	ft_philo_wait(arg->t_slp, arg, death_timer);
	if (is_philo_alive(death_timer) == false)
		return ((void)print_philo_log(PHILO_LOG_DEAD, arg, LOG_DEAD));
	return ;
}
