/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deathflag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:35:01 by srussame          #+#    #+#             */
/*   Updated: 2025/05/11 22:35:09 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_deathflag_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nERROR " RESET_COLOR \
	" : \n\n", 2);
}

t_bool	check_deathflag(t_philo_info *philo_info)
{
	t_bool	ret;

	if (philo_info == NULL)
		return (ERROR);
	if (philo_lock(&(philo_info->main_lock)) == 0)
		return (ERROR);
	ret = philo_info->death_flag;
	if (philo_unlock(&(philo_info->main_lock)) == 0)
		return (ERROR);
	return (ret);
}
