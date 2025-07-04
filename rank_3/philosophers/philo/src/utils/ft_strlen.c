/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:50:53 by srussame          #+#    #+#             */
/*   Updated: 2025/04/28 10:51:04 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	ft_strlen(const char *str)
{
	unsigned long long	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}