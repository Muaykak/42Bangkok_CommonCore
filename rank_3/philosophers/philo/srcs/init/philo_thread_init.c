/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:13:59 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/08 09:11:21 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	philo_thread_arg_init_sub1(t_philo_info *info, int i)
{
	(info->all_thread_arg[i]).thread_num = i + 1;
	(info->all_thread_arg[i]).print_lock = &(info->print_lock);
	pthread_mutex_init(&(info->all_thread_arg[i].status_lock), NULL);
	(info->all_thread_arg[i]).status = UNACTIVE;
	(info->all_thread_arg[i]).start_time = &(info->start_time);
	(info->all_thread_arg[i]).t_die = info->t_die;
	(info->all_thread_arg[i]).t_eat = info->t_eat;
	(info->all_thread_arg[i]).t_slp = info->t_slp;
	(info->all_thread_arg[i]).e_max = info->e_max;
}

static void	philo_thread_arg_init(t_philo_info *info)
{
	int	i;

	i = 0;
	while (i < info->p_num)
	{
		if (i % 2 == 0)
		{
			(info->all_thread_arg[i]).right = &(info->all_fork[i]);
			if (info->p_num > 1)
				(info->all_thread_arg[i]).left =
				&(info->all_fork[(i + 1) % info->p_num]);
		}
		else
		{
			(info->all_thread_arg[i]).left = &(info->all_fork[i]);
			(info->all_thread_arg[i]).right =
			&(info->all_fork[(i + 1) % info->p_num]);
		}
		philo_thread_arg_init_sub1(info, i);
		i++;
	}
}

bool	philo_thread_init(t_philo_info *info)
{
	if (!info || !(info->all_fork))
		return (false);
	info->all_philo_thread = (pthread_t *)\
malloc(info->p_num * sizeof(pthread_t));
	if (info->all_philo_thread == NULL)
		return (free_philo_info(info), false);
	info->all_thread_arg = (t_thread_arg *)\
malloc(info->p_num * sizeof(t_thread_arg));
	if (info->all_thread_arg == NULL)
		return (free_philo_info(info), false);
	memset(info->all_philo_thread, 0, sizeof(pthread_t) * info->p_num);
	memset(info->all_thread_arg, 0, info->p_num * sizeof(t_thread_arg));
	philo_thread_arg_init(info);
	return (true);
}
