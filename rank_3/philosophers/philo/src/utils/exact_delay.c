/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exact_delay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:53:47 by srussame          #+#    #+#             */
/*   Updated: 2025/04/27 17:53:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//try to use gettimeofday and while loop to get delay that more precise than usleep()
// ** in microsecond
// return 1 is true 0 is fail, the function is not working properly
int	exact_delay_usec(int usec)
{
	t_perform_time	time;

	if (usec >= 1000000)
		return (1);
	if (gettimeofday(&time.start, NULL) != 0)
		return (0);
	time_taken_cal(&time);
	while (time.cal.tv_usec < usec)
		time_taken_cal(&time);
	return (1);
}