/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_odd_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:33:14 by srussame          #+#    #+#             */
/*   Updated: 2025/05/07 17:33:16 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	routine for philosophers that is a odd number
	the odd number will *grab* their LEFT fork THEN RIGHT fork respectively
*/
void	*routine_odd(void *p)
{
	t_philo_thread	*thread;

	if (p == NULL)
		return (NULL);
	thread = (t_philo_thread *)p;
	if (philo_lock(&(thread->philo_info->main_lock)) == 0)
		return (0);
	if (thread->philo_info->death_flag == TRUE)
	{
		philo_unlock(&(thread->philo_info->main_lock));
		return (0);
	}
	if (philo_unlock(&(thread->philo_info->main_lock)) == 0)
		return (0);
	
	return (NULL);
}
