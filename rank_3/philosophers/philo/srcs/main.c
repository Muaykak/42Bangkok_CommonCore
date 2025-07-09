/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:42:50 by srussame          #+#    #+#             */
/*   Updated: 2025/07/09 17:28:27 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	display_info(t_philo_info *info)
{
	printf("p_num: %d\nt_die: %d\nt_eat: %d\nt_slp: %d\ne_max: %d\n",
		info->p_num, info->t_die, info->t_eat, info->t_slp, info->e_max);
}

int	main(int argc, char **argv)
{
	t_philo_info	info;
	bool			ret;

	if (philo_parser(&info, argc, argv) == false)
		return (1);
	if (philo_info_init(&info) == true)
		printf("FORK created succesfully!\n");
	ret = philo_simulation(&info);
	free_philo_info(&info);
	if (ret == false)
		return (1);
	return (0);
}

