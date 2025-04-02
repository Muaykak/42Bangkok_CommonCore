/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:20:56 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 20:20:57 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_limit(char *num_set);

/* check if the splitted string has the number in range
		-2147483648 to 2147483647*/
int	check_int_limit(char *num_set)
{
	size_t	i[2];
	int		flag;
	long	num;

	i[0] = 0;
	i[1] = 0;
	flag = 0;
	while (num_set[i[0]] != 0)
	{
		if (num_set[i[0]] != '0'
		&& num_set[i[0]] != '-'
		&& num_set[i[0]] != '+')
			flag = 1;
		if (flag == 1)
			i[1]++;
		i[0]++;
	}
	if (i[1] > 11)
		return (0);
	num = ft_atol(num_set);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	else
		return (1);
}
