/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:04:22 by srussame          #+#    #+#             */
/*   Updated: 2025/03/07 20:04:23 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_main.h"

void	sighandlr2(int signum, siginfo_t *info, void *ucontext);
void	sighandlr1(int signum, siginfo_t *info, void *ucontext);
void	check_argument(int argc, char **argv);

/* Check the arguments given to the client 
	the first argument is the pid of the server
		- this argument should contains only number
			must not include any other character accept number*/
static int	check_first_argument(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_argument(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("need 2 arguments\n");
		exit(EXIT_FAILURE);
	}
	if (check_first_argument(argv[1]) == 0)
	{
		ft_printf("pid must has only number\n");
		exit(EXIT_FAILURE);
	}
}

void	sighandlr1(int signum, siginfo_t *info, void *ucontext)
{
	if (signum != SIGUSR1)
		return ;
	(void)ucontext;
	sent_to(info->si_pid);
}

void	sighandlr2(int signum, siginfo_t *info, void *ucontext)
{
	if (signum != SIGUSR2)
		return ;
	(void)ucontext;
	(void)info;
	ft_printf("the server recieved all message.\n");
	exit(EXIT_SUCCESS);
}
