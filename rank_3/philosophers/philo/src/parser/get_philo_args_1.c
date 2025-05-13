/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_info_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:40:13 by srussame          #+#    #+#             */
/*   Updated: 2025/04/27 22:40:21 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			check_argv(int argc, char **argv);
static int	convert_to_args(t_philo_args *philo_args, int argc,  char **argv);
static int	check_ssize_limit(t_philo_args *philo_args);

void	parser_message1(void)
{
	ft_putstr_fd(RED_COLOR "\nERROR " RESET_COLOR \
	": this program need 4-5 arguments.\n\n", 2);
	return ;
}

/*
	First function to pass from argv 
	this function will check all the argv
		it will check
	- valid number of arguments (4 - 5)
	- all argument must be a number, and contain only one number per argv
	- the number must be positive integer (accept only one '+' symbol)
	- number must not exceed SSIZE_T_MAX (normally 64bits it's 9223372036854775807)
	- also the philosopher max number is bounded by PTHREAD_MAX
*/
int	get_philo_args(t_philo_args *philo_args, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (parser_message1(), 0);
	if (philo_args == NULL || check_argv(argc, argv) == 0)
		return (0);
	memset(philo_args, 0, sizeof(t_philo_args));
	return (convert_to_args(philo_args, argc, argv));
}

/* convert all arguments into t_philo_info 
	- return FALSE if philo_num exceeds PTHREAD_MAX which is defined in header */
static int	convert_to_args(t_philo_args *philo_args, int argc, char **argv)
{
	philo_args->philo_num = ft_atollu(argv[1]);
	philo_args->time_to_die = ft_atollu(argv[2]);
	philo_args->time_to_eat = ft_atollu(argv[3]);
	philo_args->time_to_sleep = ft_atollu(argv[4]);
	if (argc > 5)
	{
		philo_args->eat_flag = TRUE;
		philo_args->eat_count_max = ft_atollu(argv[5]);
	}
	if (check_ssize_limit(philo_args) == 0)
		return (0);
	if (philo_args->philo_num > PTHREAD_MAX)
	{
		ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
		": the philosopher number exceed the PTHREAD_MAX defined in the header\n"\
		YELLOW_COLOR "\tPTHREAD_MAX = ", 2);
		ft_putnbr_fd((long long)PTHREAD_MAX, 2);
		ft_putstr_fd(RESET_COLOR "\n\n", 2);
		return (0);
	}
	return (1);
}

static int	check_ssize_limit(t_philo_args *philo_args)
{
	if (philo_args->philo_num < 1 || philo_args->time_to_die < 1 \
	|| philo_args->time_to_eat < 1 || philo_args->time_to_sleep < 1)
	{
		ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
		": this program will not work if the " YELLOW_COLOR \
		"arguments" RESET_COLOR " is less than " \
		YELLOW_COLOR "1 \n\n" RESET_COLOR, 2);
		return (0);
	}
	if (philo_args->philo_num > SSIZE_MAX || philo_args->time_to_die > SSIZE_MAX \
	|| philo_args->time_to_eat > SSIZE_MAX || philo_args->time_to_sleep > SSIZE_MAX \
	|| philo_args->eat_count_max > ULONG_MAX)
	{
		ft_putstr_fd(RED_COLOR "\nError " RESET_COLOR \
		": the number in the argument exceeds the max this program allowed\n"\
		"\tshould not exceeds the LLONG_MAX ( it's " YELLOW_COLOR, 2);
		ft_putnbr_fd((long long)LLONG_MAX, 2);
		ft_putstr_fd(RESET_COLOR " )\n\n", 2);
		return (0);
	}
	return (1);
}
/* This function check the correctness of the ARGV 
	using ft_check_strnum and loop through all the arguments */
int	check_argv(int argc, char **argv)
{
	int	i;

	if (argv == NULL)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_check_strnum(argv[i]) == 0)
			return (0);
		if (ft_check_digits(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
