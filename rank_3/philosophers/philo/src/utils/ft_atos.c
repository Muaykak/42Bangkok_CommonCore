/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:19:16 by srussame          #+#    #+#             */
/*   Updated: 2025/04/28 16:19:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* use to convert to size_t like atoi 
		but in my implementation i accept maxnum to be only SSIZE_MAX
			which is 9223372036854775807
		- i will skip the signed because size_t can only hold positive integer
*/
size_t	ft_atos(char *str)
{
	size_t	result;
	int		i;

	if (str == NULL)
		return (0);
	result = 0;
	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}
