/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_thread_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:01:41 by srussame          #+#    #+#             */
/*   Updated: 2025/04/29 17:01:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_philo_thread_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "Error " RESET_COLOR \
	": create_philo_thread(); MALLOC ERROR\n", 2);
}

/* *return an array of philosophers' thread * */
int	create_philo_thread(t_philo_info *info, t_philo_thread ***thread_array)
{
	unsigned long long	i;

	if (info == NULL || info->fork == NULL || thread_array == NULL)
		return (0);
	(*thread_array) = (t_philo_thread **)malloc((info->philo_num + 1) \
	* sizeof(t_philo_thread *));
	if ((*thread_array) == NULL)
		return (create_philo_thread_errmsg1(), 0);
	memset((*thread_array), 0, (info->philo_num + 1) * sizeof(t_philo_thread *));
	i = 0;
	while (i < info->philo_num)
	{
		(*thread_array)[i] = (t_philo_thread *)malloc(sizeof(t_philo_thread));
		if ((*thread_array)[i] == NULL)
			return (free_philo_array((void **)(*thread_array)), \
			create_philo_thread_errmsg1(), 0);
		memset((*thread_array)[i], 0, sizeof(t_philo_thread));
		((*thread_array)[i])->philo_info = info;
		((*thread_array)[i])->thread_num = i + 1;
		((*thread_array)[i])->fork_right = &((info->fork)[i]->fork);
		if (info->philo_num > 1)
			((*thread_array)[i])->fork_left = &((info->fork)[(i + 1) % info->philo_num]->fork);
		((*thread_array)[i])->eat_max = info->eat_count_max;
		i++;
	}
	printf(GREEN_COLOR "create philo_thread success\n" RESET_COLOR);
	return (1);
}
