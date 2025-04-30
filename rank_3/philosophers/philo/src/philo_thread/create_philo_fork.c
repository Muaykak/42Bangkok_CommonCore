/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:21:12 by srussame          #+#    #+#             */
/*   Updated: 2025/04/29 18:21:13 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_philo_fork_errmsg1(void);
static void create_philo_fork_errmsg2(void);

/* return an array of mutex fork*/
int	create_philo_fork(t_philo_info *info)
{
	size_t	i;

	if (info == NULL)
		return (0);
	info->fork = (t_philo_fork **)malloc((info->philo_num + 1) \
	* sizeof(t_philo_fork *));
	if (info->fork == NULL)
		return (create_philo_fork_errmsg1(), 0);
	memset(info->fork, 0, (info->philo_num + 1) * sizeof(t_philo_fork *));
	i = 0;
	while (i < info->philo_num)
	{
		(info->fork)[i] = (t_philo_fork *)malloc(sizeof(pthread_mutex_t));
		if ((info->fork)[i] == NULL)
			return (free_philo_fork(info->fork), \
			create_philo_fork_errmsg1(), 0);
		memset((info->fork)[i], 0, sizeof(t_philo_fork));
		if (pthread_mutex_init(&(((info->fork)[i])->fork), NULL) != 0)
			return (free_philo_fork(info->fork), \
			create_philo_fork_errmsg2(), 0);
		((info->fork)[i])->init_flag = 1;
		i++;
	}
	printf(YELLOW_COLOR "create philo_fork success\n" RESET_COLOR);
	return (1);
}

static void create_philo_fork_errmsg2(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": create_philo_fork; PTHREAD_MUTEX_INIT() ERROR\n\n", 2);
}

static void	create_philo_fork_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": create_philo_fork; MALLOC ERROR\n\n", 2);
}
