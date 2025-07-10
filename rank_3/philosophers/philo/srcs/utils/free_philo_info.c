/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:42:16 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/10 08:29:17 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_philo_fork(t_philo_fork *fork_array, int array_size)
{
	int	i;

	if (!fork_array)
		return ;
	i = 0;
	while (i < array_size)
	{
		pthread_mutex_destroy(&(fork_array[i].lock));
		i++;
	}
	free(fork_array);
}

void	free_philo_info(t_philo_info *info)
{
	if (!info)
		return ;
	free_philo_fork(info->all_fork, info->p_num);
	if (info->all_philo_thread)
		free(info->all_philo_thread);
	info->all_philo_thread = NULL;
	if (info->all_thread_arg)
		free(info->all_thread_arg);
	info->all_thread_arg = NULL;
	pthread_mutex_destroy(&info->print_lock);
}
