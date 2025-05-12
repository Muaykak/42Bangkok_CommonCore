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
	t_routine_data	data;

	if (p == NULL)
		return (NULL);
	thread = (t_philo_thread *)p;
	memset(&data, 0, sizeof(t_routine_data));
	if (check_deathflag(thread->philo_info) == TRUE)
		return (NULL);
	while (data.current_eat < thread->philo_info->eat_count_max)
	{
	}
}
