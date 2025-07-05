/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 08:38:33 by srussame          #+#    #+#             */
/*   Updated: 2025/07/05 18:30:29 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

/*
	checks that all argument should contain only one number and whitespaces,
	and should not contain any symbols or characters accept digits
*/

bool	philo_parser(t_philo_info **info, int argc, char **argv)
{
	if (!info)
		return (false);
	if (argc < 5 || argc > 6)	
		return (ft_putstr_fd(PHILO_ERR_MSG_2, 2), false);
	return (true);
}