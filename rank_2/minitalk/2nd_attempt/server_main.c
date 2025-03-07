/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:37:52 by srussame          #+#    #+#             */
/*   Updated: 2025/03/07 12:37:54 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <signal.h>

char bintext[8];

/*
	1.The server will need to print its process id 
	
*/

int	bintext_process(void)
{
	char	c;

	c = bin_to_decimal(bintext);
	if (c == '\0')
	{
		bintext_init(bintext);
		ft_printf("\n\nrecieved all\npid: %d\n", (int)getpid());
		return (0);
	}
	else
		write(1, &c, 1);
	bintext_init(bintext);
	return (1);
}

void	sighandlr1(int signum, siginfo_t *info, void *ucontext)
{
	int	i;

	if (signum != SIGUSR1)
		return ;
	(void)ucontext;
	i = 0;
	while (i < 8 && bintext[i] != '\0')
		i++;
	if (i < 8)
		bintext[i] = '0';
	if (i == 7)
	{
		if (bintext_process() == 0)
			kill(info->si_pid, SIGUSR2);
		else
			kill(info->si_pid, SIGUSR1);
		return ;
	}
	kill(info->si_pid, SIGUSR1);
}

void	sighandlr2(int signum, siginfo_t *info, void *ucontext)
{
	int	i;

	if (signum != SIGUSR2)
		return ;
	(void)ucontext;
	i = 0;
	while (i < 8 && bintext[i] != '\0')
		i++;
	if (i < 8)
		bintext[i] = '1';
	if (i == 7)
	{
		if (bintext_process() == 0)
			kill(info->si_pid, SIGUSR2);
		else
			kill(info->si_pid, SIGUSR1);
		return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction sigact1;
	struct sigaction sigact2;

	if (argc != 1)
	{
		ft_printf("This program takes no argument.\n");
		return (1);
	}
	(void)argv;
	bintext_init(bintext);
	sigact1.sa_flags = SA_SIGINFO;
	sigact1.sa_sigaction = sighandlr1;
	sigemptyset(&sigact1.sa_mask);
	sigaction(SIGUSR1, &sigact1, NULL);
	sigact2.sa_flags = SA_SIGINFO;
	sigact2.sa_sigaction = sighandlr2;
	sigemptyset(&sigact2.sa_mask);
	sigaction(SIGUSR2, &sigact2, NULL);
	ft_printf("pid: %d\n", (int)getpid());
	while (1)
	{
		pause();
	}
	return (0);
}