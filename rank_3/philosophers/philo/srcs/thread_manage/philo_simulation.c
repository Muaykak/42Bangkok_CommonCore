/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:22:21 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/12 06:22:20 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	philo_simulation(t_philo_info *info)
{
	if (!info)
		return (false);
	if (create_all_philo(info) == false)
		return (false);
	return (join_all_philo(info));
}
