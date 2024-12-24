/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:54:37 by muaykak           #+#    #+#             */
/*   Updated: 2024/11/09 05:49:43 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_minitalk.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

char	bintext[8];

void	signal_end_check(int *num)
{
	if (*num == 8)
	{
		bintext_init(bintext);
		ft_printf("\n\n\nwaiting for signals\n");
		ft_printf("pid: %d\n\n", (int)getpid());
		*num = 0;
	}
}

void	bintext_process(int *num)
{
	char	c;

	if (bintext[7] != '\0')
	{
		c = bin_to_decimal(bintext);
		if (c == '\0')
		{
			*num = *num + 1;
			signal_end_check(num);
		}
		else
			write(1, &c, 1);
		bintext_init(bintext);
		return ;
	}
}

void	sigusr1_handler(int sig)
{
	int		i;

	if (sig != SIGUSR1)
		return ;
	i = 0;
	while (i < 8 && bintext[i] != '\0')
		i++;
	if (i < 8)
		bintext[i] = '1';
}

void	sigusr2_handler(int sig)
{
	int		i;

	if (sig != SIGUSR2)
		return ;
	i = 0;
	while (i < 8 && bintext[i] != '\0')
		i++;
	if (i < 8)
		bintext[i] = '0';
}

int	main(void)
{
	struct sigaction sigact1;
	struct sigaction sigact2;
	int	num;

	num = 0;
	sigact1.sa_handler = &sigusr1_handler;
	sigemptyset(&sigact1.sa_mask);
	sigaddset(&sigact1.sa_mask, SIGUSR2);
	sigaddset(&sigact1.sa_mask, SIGUSR1);
	sigact1.sa_flags = 0;
	sigaction(SIGUSR1, &sigact1, NULL);
	
	sigact2.sa_handler = &sigusr2_handler;
	sigemptyset(&sigact2.sa_mask);
	sigaddset(&sigact2.sa_mask, SIGUSR1);
	sigaddset(&sigact2.sa_mask, SIGUSR2);
	sigact2.sa_flags = 0;
	sigaction(SIGUSR2, &sigact2, NULL);
		ft_printf("pid: %d\n", (int)getpid());
		ft_printf("waiting for signal ...\n\n");

	while(1)
	{
		bintext_process(&num);
		pause();
	}
}
