/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:04:05 by srussame          #+#    #+#             */
/*   Updated: 2025/03/07 20:04:06 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_main.h"

t_client	g_var;

int		sent_to(int server_pid);
void	decimal_to_bin(int dec_num);
int		check_bintext(void);
void	bintext_zero(void);

void	bintext_zero(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_var.bintext[i] = '0';
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
		if (g_var.bintext[i] != 0)
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
		g_var.bintext[0] = '1';
		return ;
	}
	if (dec_num < 0)
	{
		g_var.bintext[0] = '1';
		dec_num *= -1;
	}
	while (dec_num != 0 && i >= 1)
	{
		if (dec_num % 2 == 1)
			g_var.bintext[i] = '1';
		else
			g_var.bintext[i] = '0';
		i--;
		dec_num /= 2;
	}
}

/* This function send signal from bintext[8] to server
	return 0 if cannot send*/

int	sent_to(int server_pid)
{
	int	i;
	int	k;

	if (check_bintext() == 1)
	{
		g_var.str_index++;
		decimal_to_bin(g_var.str[g_var.str_index]);
	}
	i = 0;
	while (i < 8 && g_var.bintext[i] == '\0')
		i++;
	if (i == 8)
		return (0);
	k = g_var.bintext[i] - 48;
	g_var.bintext[i] = 0;
	if (check_bintext() && g_var.str[g_var.str_index] == '\0')
		free(g_var.bintext);
	if (k == 1)
		kill(server_pid, SIGUSR2);
	else if (k == 0)
		kill(server_pid, SIGUSR1);
	return (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sigact1;
	struct sigaction	sigact2;

	check_argument(argc, argv);
	g_var.str = argv[2];
	g_var.bintext = (char *)malloc(9 * sizeof(char));
	if (g_var.bintext == 0)
		exit(EXIT_FAILURE);
	sigact1.sa_flags = SA_SIGINFO;
	sigact1.sa_sigaction = sighandlr1;
	sigemptyset(&sigact1.sa_mask);
	sigaction(SIGUSR1, &sigact1, NULL);
	sigact2.sa_flags = SA_SIGINFO;
	sigact2.sa_sigaction = sighandlr2;
	sigemptyset(&sigact2.sa_mask);
	sigaction(SIGUSR2, &sigact2, NULL);
	bintext_init(g_var.bintext);
	g_var.str_index = 0;
	decimal_to_bin(g_var.str[g_var.str_index]);
	sent_to(ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
