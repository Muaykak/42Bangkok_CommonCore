/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:18:45 by srussame          #+#    #+#             */
/*   Updated: 2025/03/30 20:18:46 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_format(int argc, char **argv);
static int	check_format_sub1(char *argv, int j);

/*sub function of check_format*/
static int	check_format_sub1(char *argv, int j)
{
	if ((argv[j] < '0' || argv[j] > '9' ) && argv[j] != '-' \
	&& argv[j] != '+' && argv[j] != ' ')
		return (0);
	if (argv[j] == '+' || argv[j] == '-')
	{
		if (j != 0 && argv[j - 1] != ' ')
			return (0);
		if (argv[j + 1] < '0' || argv[j + 1] > '9')
			return (0);
	}
	return (1);
}

/* This is sub function to check the cjorrect format
	Will check various things through its sub functions*/
int	check_format(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argc > i)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (check_format_sub1(argv[i], j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
