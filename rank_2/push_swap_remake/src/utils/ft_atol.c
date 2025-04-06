/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:40:59 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 19:41:00 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c);

long	ft_atol(const char *nptr)
{
	long	i;
	long	num;
	char	c;

	i = 0;
	num = 0;
	c = 0;
	while ((*(nptr + i) < '0' || *(nptr + i) > '9') && ft_isspace(*(nptr
				+ i)) != 0 && *(nptr + i) != '\0')
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

// to check if the given character is whitespace characters
static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
