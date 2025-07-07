/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:42:50 by srussame          #+#    #+#             */
/*   Updated: 2025/07/07 15:35:03 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	display_info(t_philo_info *info)
{
	printf("p_num: %d\nt_die: %d\nt_eat: %d\nt_slp: %d\ne_max: %d\n",
		info->p_num, info->t_die, info->t_eat, info->t_slp, info->e_max);
}

void	display_all_thread_arg(t_philo_info *info)
{
	int	i;

	if (!info || !(info->all_thread_arg))
		return ;
	i = 0;
	while (i < info->p_num)
	{
		printf("\nthread arg[%d]\nright: %p\nleft: %p\nprint_lock: \
%p\nstatus_lock: %p\ndead status:\
%p\n\n", i, (info->all_thread_arg[i]).right, (info->all_thread_arg[i]).left, (info->all_thread_arg[i]).print_lock, (info->all_thread_arg[i]).status_lock, (info->all_thread_arg[i]).dead_status);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo_info	info;

	if (philo_parser(&info, argc, argv) == false)
		return (1);
	if (philo_info_init(&info) == true)
		printf("FORK created succesfully!\n");
	display_all_thread_arg(&info);
	free_philo_info(&info);
	return (0);
}

