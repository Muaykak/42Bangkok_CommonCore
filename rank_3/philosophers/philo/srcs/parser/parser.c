/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:38:33 by srussame          #+#    #+#             */
/*   Updated: 2025/07/05 23:31:07 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	msg_err_limit(char *msg, int limit)
{
	ft_putstr_fd(msg, 2);
	ft_putnbr_fd(limit, 2);
	ft_putstr_fd("\n", 2);
}

bool	argv_to_info(t_philo_info *info, int argc, char **argv)
{
	info->p_num = ft_philo_atoi(argv[1]);
	if (info->p_num == 0)
		return (false);
	info->t_die = ft_philo_atoi(argv[2]);
	if (info->t_die == 0)
		return (false);
	info->t_eat = ft_philo_atoi(argv[3]);
	if (info->t_eat == 0)
		return (false);
	info->t_slp = ft_philo_atoi(argv[4]);
	if (info->t_slp == 0)
		return (false);
	if (argc == 5)
		return (true);
	info->e_max = ft_philo_atoi(argv[5]);
	if (info->e_max == 0)
		return (false);
	return (true);
}

bool	check_philo_limit(t_philo_info *info)
{
	if (!info)
		return (false);
	if (info->p_num > MAX_PHILO_NUM)
		return (msg_err_limit(PHILO_ERR_MSG_5"MAX_PHILO_NUM = ", MAX_PHILO_NUM), false);
	if (info->t_die > MAX_TIME_MS || info->t_eat > MAX_TIME_MS
		|| info->t_slp > MAX_TIME_MS)
		return (msg_err_limit(PHILO_ERR_MSG_5"MAX_TIME_MS = ", MAX_TIME_MS), false);
	if (info->e_max != -1 && info->e_max > MAX_EAT)
		return (msg_err_limit(PHILO_ERR_MSG_5"MAX_EAT = ", MAX_EAT), false);
	return (true);
}

bool	philo_parser(t_philo_info *info, int argc, char **argv)
{

	if (!info)
		return (false);
	if (argc < 5 || argc > 6)	
		return (ft_putstr_fd(PHILO_ERR_MSG_2, 2), false);
	memset(info, 0, sizeof(t_philo_info));
	if (argc == 6)
		info->e_max = -1;
	if (argv_to_info(info, argc, argv) == false
	|| check_philo_limit(info) == false)
		return (false);
	return (true);
}
