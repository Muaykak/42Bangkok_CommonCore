/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathtime_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:52:45 by srussame          #+#    #+#             */
/*   Updated: 2025/05/13 21:52:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	deathtime_start_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": deathtime_start() the function argument is NULL!!\n\n", 2);
}

/*
	put the start time and end time using ft_gettime() function
	return TRUE = success
	return FALSE = ft_gettime() is FALSE
*/
t_bool	deathtime_start(t_perform_time *deathtimer, struct timeval time_to_die)
{
	if (deathtimer == NULL)
		return (deathtime_start_errmsg1(), FALSE);
	if (ft_gettime(&(deathtimer->start)) == FALSE)
		return (FALSE);
	if (deathtimer->start.tv_usec + time_to_die.tv_usec >= 1000000)
	{
		deathtimer->end.tv_sec += 1;
		deathtimer->end.tv_usec = 1000000 - (deathtimer->start.tv_usec \
		+ time_to_die.tv_usec);
	}
	else
		deathtimer->end.tv_usec = deathtimer->start.tv_usec \
		+ time_to_die.tv_usec;
	deathtimer->end.tv_sec += deathtimer->start.tv_sec + time_to_die.tv_sec;
	return (TRUE);
}
