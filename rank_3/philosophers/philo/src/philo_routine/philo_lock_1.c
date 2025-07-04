/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lock_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:03:32 by srussame          #+#    #+#             */
/*   Updated: 2025/05/07 18:03:33 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_lock_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": philo_lock(); the argument recieved is NULL\n\n", 2);
}

static void	philo_lock_errmsg2(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": philo_lock; pthread_mutex_lock() ERROR\n\n", 2);
}

static void	philo_lock_errmsg3(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": philo_lock; pthread_mutex_unlock() ERROR\n\n", 2);
}

int	philo_lock(t_philo_fork *fork)
{
	if (fork == NULL)
		return (philo_lock_errmsg1(), 0);
	if (pthread_mutex_lock(&(fork->fork_mutex)) != 0)
		return (philo_lock_errmsg2(), 0);
	if (pthread_mutex_lock(&(fork->status_mutex)) != 0)
	{
		philo_lock_errmsg2();
		if (pthread_mutex_unlock(&(fork->fork_mutex)) != 0)
			philo_lock_errmsg3();
		return (0);
	}
	fork->status = TRUE;
	if (pthread_mutex_unlock(&(fork->status_mutex)) != 0)
		return (philo_lock_errmsg3(), 0);
	return (1);
}
