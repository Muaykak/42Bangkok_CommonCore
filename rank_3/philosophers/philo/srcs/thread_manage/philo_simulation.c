/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:22:21 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/09 17:26:58 by muaykak          ###   ########.fr       */
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
