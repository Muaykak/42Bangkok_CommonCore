/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_routine_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:35:43 by srussame          #+#    #+#             */
/*   Updated: 2025/05/07 17:35:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	run all the philo threads using 
	1. pthread_create() function to run through all the threads
		- when each of the thread successfully created 
			the run_flag of t_philo_thread will set to TRUE
		- if any of the thread cannot be created (pthread_create returns != 0)
			the run_flag will set to FALSE indicated that the thread cannot 
			be create hence the philo program should not run any further and
			exit
	2. pthread_join() function to join all the threads back to the main 
	function
*		- if the pthread_join() returns != 0 ;undefined behaviors may occur
*			(i still figuring out LOL)
*/
int	put_routine(t_philo_thread **thread)
{

	if (thread == NULL)
		return (0);
	if (philo_lock(&((*thread)->philo_info->main_lock)) == 0)
		return (0);
	if (philo_unlock(&((*thread)->philo_info->main_lock)) == 0)
		return (0);
	return (1);
}
