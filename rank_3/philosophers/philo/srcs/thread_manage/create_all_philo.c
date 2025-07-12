/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:40:32 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/12 06:22:04 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	clear_philo_create_error(t_philo_info *info)
{
	int	i;

	i = 0;
	info->print_status = false;
	if (pthread_mutex_unlock(&info->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	while (i < info->p_num)
	{
		if ((info->all_thread_arg)[i].status == UNACTIVE)
			break ;
		if (pthread_join((info->all_philo_thread)[i], NULL) != 0)
			return (ft_putstr_fd(PHILO_ERR_MSG_9, 2), false);
		i++;
	}
	return (true);
}

bool	join_all_philo(t_philo_info *info)
{
	int	i;

	if (!info)
		return (false);
	i = 0;
	while (i < info->p_num)
	{
		if (pthread_join((info->all_philo_thread)[i], NULL) != 0)
			return (ft_putstr_fd(PHILO_ERR_MSG_9, 2), false);
		i++;
	}
	return (true);
}

bool	create_all_philo(t_philo_info *info)
{
	int	i;

	if (!info)
		return (false);
	i = 0;
	if (pthread_mutex_lock(&info->print_lock) != 0)
		return (ft_putstr_fd(PHILO_ERR_MSG_6, 2), false);
	printf("creating all the thread...\n");
	while (i < info->p_num)
	{
		if (pthread_create(&(info->all_philo_thread[i]), NULL,
				&philo_routine, (void *)(&(info->all_thread_arg)[i])) != 0)
			return (clear_philo_create_error(info), false);
		(info->all_thread_arg)[i].status = ACTIVE;
		i++;
	}
	printf("simulation start\n\n");
	if (gettimeofday(&info->start_time, NULL) != 0)
		return (pthread_mutex_unlock(&info->print_lock),
			ft_putstr_fd(PHILO_ERR_MSG_7, 2), false);
	if (pthread_mutex_unlock(&info->print_lock) != 0)
		set_print_status(&((info->all_thread_arg)[0]), false);
	return (true);
}
