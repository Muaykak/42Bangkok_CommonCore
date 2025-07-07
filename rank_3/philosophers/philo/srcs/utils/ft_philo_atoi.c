/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:51:00 by srussame          #+#    #+#             */
/*   Updated: 2025/07/06 16:20:32 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	count_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str != '\0' && ft_isspace(*str))
		str++;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str != '\0' && (*str < '1' || *str > '9'))
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		str++;
		i++;
	}
	while (*str != '\0' && ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (0);
	return (i);
}

/*
	because this program I will not accept the argument that is lower than 1
	so it can not be negative
*/
int	ft_philo_atoi(char *strnum)
{
	long	result;

	if (!strnum)
		return (0);
	while (*strnum != '\0' && ft_isspace(*strnum))
		strnum++;
	if ((ft_isdigit(*strnum) == 0 && *strnum != '+')
	|| (*strnum == '+' && !ft_isdigit(*(strnum + 1))))
		return	(ft_putstr_fd(PHILO_ERR_MSG_1, 2), 0);	
	if (*strnum == '+')
		strnum++;
	while (*strnum != '\0' && *strnum == '0')
		strnum++;
	result = (long)count_digit(strnum);
	if (result > 10 || result < 1)
		return (ft_putstr_fd(PHILO_ERR_MSG_4, 2), 0);
	result = 0;
	while (ft_isdigit(*strnum))
	{
		result = (result * 10) + (*strnum - 48);
		strnum++;
	}
	if (result > 2147483647)
		return (ft_putstr_fd(PHILO_ERR_MSG_4, 2), 0);
	return ((int)result);
}
