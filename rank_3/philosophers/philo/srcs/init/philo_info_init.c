/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:44:09 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/12 06:17:13 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/* all fork numbers equal to number of philosopher on the table */
bool	all_fork_init(t_philo_info *info)
{
	int	i;

	if (info->all_fork != 0)
		return (false);
	info->all_fork = malloc(info->p_num * sizeof(t_philo_fork));
	if (info->all_fork == NULL)
		return (false);
	memset(info->all_fork, 0, sizeof(t_philo_fork) * info->p_num);
	i = 0;
	while (i < info->p_num)
	{
		if (pthread_mutex_init(&((info->all_fork)[i].lock), NULL) != 0)
			return (free_philo_fork(info->all_fork, i), false);
		(info->all_fork)[i].is_using = false;
		i++;
	}
	return (true);
}

bool	main_lock_init(t_philo_info *info)
{
	if (pthread_mutex_init(&(info->print_lock), NULL) != 0)
		return (free_philo_fork(info->all_fork, info->p_num), false);
	info->print_status = true;
	return (true);
}

bool	philo_info_init(t_philo_info *info)
{
	if (info == NULL)
		return (false);
	if (all_fork_init(info) == false
		|| main_lock_init(info) == false || philo_thread_init(info) == false)
		return (ft_putstr_fd(PHILO_ERR_MSG_3, 2), false);
	return (true);
}
