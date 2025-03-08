/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_argument_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:23:18 by srussame          #+#    #+#             */
/*   Updated: 2025/03/06 22:23:21 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		check_format(int argc, char **argv);
int		check_int_limit(char *num_set);

int		check_format_sub1(char *argv, int j);

/*sub function of check_format*/
int	check_format_sub1(char *argv, int j)
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
		if (num_set[i[0]] != '0')
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
