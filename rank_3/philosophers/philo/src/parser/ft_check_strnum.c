/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_strnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:18:28 by srussame          #+#    #+#             */
/*   Updated: 2025/04/27 20:18:29 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_strnum_sub1(char *str, size_t i);
static void	check_strnum_errmsg1(void);
static void check_strnum_errmsg2(void);
static void	check_strnum_errmsg3(void);
int			ft_check_strnum(char *str);

/* check the given string
		just check_if the string can pass to atol, atoi like function
		
		- checking if there is no other characters except number 0 - 9
			and symbol (only '+')

			* I will not accept negative value because each argument 
				of this project cannot not be in negative value *

		- normally atoi will accept string like this "-21 adfkjhkadsf"
			means that it doesn't care what after the number
			but this function WILL NOT ACCEPT THIS CASE
		
		- so after the the first number on the string, should have only
			white space characters
*/
int	ft_check_strnum(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		if (ft_isspace(str[i]) == 0 && str[i] != '+')
			return (check_strnum_errmsg1(), 0);
		if (str[i] == '+')
		{
			i++;
			if (str[i] < '0' || str[i] > '9')
				return (check_strnum_errmsg1(), 0);
		}
		if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
			i++;
	}
	return (ft_check_strnum_sub1(str, i));
}

static int	ft_check_strnum_sub1(char *str, size_t i)
{
	int	flag;

	flag = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		flag = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) == 0	)
			return (check_strnum_errmsg2(), 0);
		i++;
	}
	if ((str[i] == '\0' && i == 0) || flag == 0)
		return (check_strnum_errmsg3(), 0);
	return (1);
}

static void	check_strnum_errmsg3(void)
{
	ft_putstr_fd(RED_COLOR "\nERROR " RESET_COLOR \
	": CANNOT ACCEPT ANY EMPTY ARGUMENTS.\n\n", 2);
}

static void check_strnum_errmsg2(void)
{
	ft_putstr_fd(RED_COLOR "\nERROR " RESET_COLOR \
	": EACH argument MUST contain only  one number(miliseconds) \n\
	and after the number can be only whitespaces\n", 2);
}

static void	check_strnum_errmsg1(void)
{
	ft_putstr_fd(RED_COLOR "\nERROR " RESET_COLOR \
	": All arguments MUST have no other characters \n\
	except a number[0 - 9],a symbol(only '+' symbol accepted),\n\
	and whitespaces\n", 2);
}