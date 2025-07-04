/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 04:04:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/07/02 04:09:32 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_digit(char *strnum)
{
	int	i;

	if (!strnum)
		return (0);
	while (!ft_isdigit(*strnum))
		strnum++;
	while (*strnum == '0')
		strnum++;
	i = 0;
	while (ft_isdigit(*strnum))
	{
		strnum++;
		i++;
	}
	return (i);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	num;
	char		c;

	if (nptr == 0)
		return (0);
	i = 0;
	num = 0;
	c = 0;
	while ((*(nptr + i) < '0' || *(nptr + i) > '9')
		&& ft_isspace(*(nptr + i)) != 0 && *(nptr + i) != '\0')
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		c = *(nptr + i);
		i++;
	}
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		num = (num * 10) + *(nptr + i) - 48;
		i++;
	}
	if (c == '-')
		num = num * -1;
	return (num);
}

int	convert_exit_code(char *strnum)
{
	long long	long_num;

	while (ft_isspace(*strnum))
		strnum++;
	long_num = ft_atoll(strnum);
	if (long_num < 0)
		long_num = 256 + (long_num % 256);
	else
		long_num = long_num % 256;
	return ((int)long_num);
}

bool	strnum_cmp_ismorethan(char *str, char *des)
{
	int	compare_digit;

	compare_digit = count_digit(str) - count_digit(des);
	if (compare_digit > 0)
		return (true);
	if (compare_digit < 0)
		return (false);
	while (*str != '\0' && (*str < '1' || *str > '9'))
		str++;
	while (*str != '\0' && *des != '\0' && *str == *des)
	{
		str++;
		des++;
	}
	if (*str <= *des)
		return (false);
	return (true);
}
