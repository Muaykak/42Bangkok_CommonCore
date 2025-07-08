/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-08 10:40:32 by muaykak           #+#    #+#             */
/*   Updated: 2025-07-08 10:40:32 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	create_all_philo(t_philo_info *info)
{
	int	i;

	if (!info)
		return (false);
	i = 0;
	while (i < info->p_num)
	{
		pthread_create(&(info->all_philo_thread[i]), NULL, )
	}
}
