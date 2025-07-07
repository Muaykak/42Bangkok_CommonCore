/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:42:16 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/07 15:20:38 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_mutex_array(pthread_mutex_t *mutex_array, int array_size)
{
	int	i;

	if (!mutex_array)
		return ;
	i = 0;
	while (i < array_size)	
	{
		pthread_mutex_destroy(&(mutex_array[i]));
		i++;
	}
	free(mutex_array);
}

void	free_philo_info(t_philo_info *info)
{
	if (!info)
		return ;
	free_mutex_array(info->all_fork, info->p_num);
	if (info->all_philo_thread)
		free(info->all_philo_thread);
	info->all_philo_thread = NULL;
	if (info->all_thread_arg)
		free(info->all_thread_arg);
	info->all_thread_arg = NULL;
	pthread_mutex_destroy(&info->print_lock);
	pthread_mutex_destroy(&info->status_mutex);
}
