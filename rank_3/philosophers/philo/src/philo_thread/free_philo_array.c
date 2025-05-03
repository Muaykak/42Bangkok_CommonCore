/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:41:16 by srussame          #+#    #+#             */
/*   Updated: 2025/04/29 17:41:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_fork(t_philo_fork **fork);

void	free_philo_fork(t_philo_fork **fork)
{
	size_t	i;

	if (fork == NULL)
		return ;
	i = 0;
	printf("freeing fork\n");
	while (fork[i] != NULL)
	{
		if ((fork[i])->init_flag == 1)
			pthread_mutex_destroy(&(fork[i]->fork));
		fork[i]->init_flag = 0;
		free(fork[i]);
		i++;
	}
	free(fork);
	return ;
}

void	free_philo_array(void **thread_array)
{
	unsigned long long	i;

	i = 0;
	if (thread_array == NULL)
		return ;
	while (thread_array[i] != NULL)
	{
		if (thread_array[i] != NULL)
			free(thread_array[i]);
		thread_array[i] = NULL;
		i++;
	}
	free(thread_array);
	return ;
}
