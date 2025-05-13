/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:06:06 by srussame          #+#    #+#             */
/*   Updated: 2025/05/13 21:06:11 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_gettime_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": ft_gettime() ERROR!\n\n", 2);
}

static void	ft_gettime_errmsg2(void)
{
	ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
	": ft_gettime(): function argument is NULL\n\n", 2);
}

/*
	The real gettimeofday() function is nested inside
		- to indicate and print error message
	return TRUE = success
	return FALSE = fail
*/
t_bool	ft_gettime(struct timeval *datetime)
{
	if (datetime == NULL)
		return (ft_gettime_errmsg2(), FALSE);
	if (gettimeofday(datetime, NULL) != 0)
		return (ft_gettime_errmsg1(), FALSE);
	return (TRUE);
}
