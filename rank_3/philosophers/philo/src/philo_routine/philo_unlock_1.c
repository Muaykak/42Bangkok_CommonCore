/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_unlock_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:29:58 by srussame          #+#    #+#             */
/*   Updated: 2025/05/07 18:30:00 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_unlock_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": philo_unlock(); the argument recieved is NULL\n\n", 2);
}

static void	philo_unlock_errmsg2(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": philo_unlock; pthread_mutex_lock() ERROR\n\n", 2);
}

static void	philo_unlock_errmsg3(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": philo_unlock; pthread_mutex_unlock() ERROR\n\n", 2);
}

int	philo_unlock(t_philo_fork *fork)
{
	if (fork == NULL)
		return (philo_unlock_errmsg1(), 0);
	if (pthread_mutex_unlock(&(fork->fork_mutex)) != 0)
		return (philo_unlock_errmsg3(), 0);
	if (pthread_mutex_lock(&(fork->status_mutex)) != 0)
		return (philo_unlock_errmsg2(), 0);
	fork->status = FALSE;
	if (pthread_mutex_unlock(&(fork->status_mutex)) != 0)
		return (philo_unlock_errmsg3(), 0);
	return (1);
}
