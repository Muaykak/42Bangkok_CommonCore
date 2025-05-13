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

static void	routine_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": routine_odd: gettimeofday ERROR!\n\n", 2);
}

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
	data.eat_flag = thread->philo_info->optional_flag;
	if (check_deathflag(thread->philo_info) == TRUE)
		return (NULL);
	if (deathtime_start(&data.deathtime, thread->philo_info->time_to_die) == FALSE)
		return (NULL);
	while (1)
	{
		if (check_deathflag(thread->philo_info) == TRUE)
			return (NULL);
		if (data.eat_flag == TRUE && data.current_eat >= thread->eat_max)
			break ;
	}
	return (NULL);
}
