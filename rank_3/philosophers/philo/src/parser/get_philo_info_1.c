/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_info_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:54:19 by srussame          #+#    #+#             */
/*   Updated: 2025/04/29 08:54:20 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	convert_to_timeval(struct timeval *time, size_t time_ms)
{
	size_t	sec;

	if (time == NULL)
		return ;
	sec = time_ms / 1000;
	time_ms = time_ms % 1000;
	time->tv_sec = sec;
	time->tv_usec = time_ms * 1000;
	return ;
}

/*	This function tries to convert the argv to usable info of the program 
	1. use get_philo_args() first to check argv and to convert is to size_t
	2. convert the time in miliseconds (from argv) to [struct timeval]
		return 1 on SUCCESS and 0 on failed
*/
int	get_philo_info(t_philo_info *philo_info, int argc, char **argv)
{
	t_philo_args	philo_args;

	if (philo_info == NULL || get_philo_args(&philo_args, argc, argv) == 0)
		return (0);
	memset(philo_info, 0, sizeof(t_philo_info));
	philo_info->philo_num = philo_args.philo_num;
	convert_to_timeval(&(philo_info->time_to_die), philo_args.time_to_die);
	convert_to_timeval(&(philo_info->time_to_eat), philo_args.time_to_eat);
	convert_to_timeval(&(philo_info->time_to_sleep), philo_args.time_to_sleep);
	philo_info->optional_flag = philo_args.optional_flag;
	philo_info->eat_count_max = philo_args.eat_count_max;
	return (1);
}
