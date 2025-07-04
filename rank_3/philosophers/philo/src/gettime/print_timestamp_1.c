/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timestamp_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:03:33 by srussame          #+#    #+#             */
/*   Updated: 2025/05/07 11:03:39 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_timestamp_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": print_timestamp -> gettimeofday() ERROR!\n\n", 2);
	return ;
}

/*print the current timestamp
	using gettimeofday() function
	format like YEAR-MONTH-DAY_HOUR:MINUTE:SEC:MS */
int	print_timestamp(void)
{
	t_datetime time;

	memset(&time, 0, sizeof(time));
	if (gettimeofday(&(time.snap_time), NULL) != 0)
		return (print_timestamp_errmsg1(), 0);
	convert_timedate(&time);
	printf("[%u-%u-%u_%02u:%02u:%02u:%03u]\t", time.year, time.month, \
		time.day, time.hour, time.minute, time.sec, time.ms);
	return (1);
}
