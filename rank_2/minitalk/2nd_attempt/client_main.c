/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:36:48 by srussame          #+#    #+#             */
/*   Updated: 2025/03/07 12:36:52 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_main.h"

t_client	glob_var;

void	bintext_zero(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		glob_var.bintext[i] = '0';
		i++;
	}
}

/* check if bintext is all null*/
int	check_bintext(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (glob_var.bintext[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	decimal_to_bin(int dec_num)
{
	int	i;

	i = 7;
	bintext_zero();
	if (dec_num == -128)
	{
		glob_var.bintext[0] = '1';
		return ;
	}
	if (dec_num < 0)
	{
		glob_var.bintext[0] = '1';
		dec_num *= -1;
	}
	while (dec_num != 0 && i >= 1)
	{
		if (dec_num % 2 == 1)
			glob_var.bintext[i] = '1';
		else
			glob_var.bintext[i] = '0';
		i--;
		dec_num /= 2;
	}
}


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

/* This function send signal from bintext[8] to server
	return 0 if cannot send*/
int	sent_to(int server_pid)
{
	int i;
	int	k;

	if (check_bintext() == 1)
	{
		glob_var.str_index++;
		decimal_to_bin(glob_var.str[glob_var.str_index]);
	}
	i = 0;
	while (i < 8 && glob_var.bintext[i] == '\0')
		i++;
	if (i == 8)
		return (0);
	if (glob_var.bintext[i] == '1')
		k = 1;
	else
		k = 0;
	ft_printf("bintext[%d]= %c\n", i, glob_var.bintext[i]);
	glob_var.bintext[i] = 0;
	if (k == 1)
		kill(server_pid, SIGUSR2);
	else if (k == 0)
		kill(server_pid, SIGUSR1);
	return (1);
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

int	main(int argc, char **argv)
{
	struct sigaction	sigact1;
	struct sigaction	sigact2;

	check_argument(argc, argv);
	glob_var.str = argv[2];
	glob_var.bintext = (char *)malloc(9 * sizeof(char));
	if (glob_var.bintext == 0)
		exit(EXIT_FAILURE);
	sigact1.sa_flags = SA_SIGINFO;
	sigact1.sa_sigaction = sighandlr1;
	sigemptyset(&sigact1.sa_mask);
	sigaction(SIGUSR1, &sigact1, NULL);
	sigact2.sa_flags = SA_SIGINFO;
	sigact2.sa_sigaction = sighandlr2;
	sigemptyset(&sigact2.sa_mask);
	sigaction(SIGUSR2, &sigact2, NULL);
	bintext_init(glob_var.bintext);
	glob_var.str_index = 0;
	decimal_to_bin(glob_var.str[glob_var.str_index]);
	sent_to(ft_atoi(argv[1]));
	while (1)
	{
		pause();
	}
	return (0);
}
