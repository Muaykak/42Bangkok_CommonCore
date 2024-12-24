/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:43:32 by srussame          #+#    #+#             */
/*   Updated: 2024/11/29 14:43:34 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "ft_minitalk.h"

char	bintext[8];

void	bintext_zero(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bintext[i] = '0';
		i++;
	}
}
void	sent_to(pid_t pid)
{
	int	i;

	i = 0;
	ft_printf("%s\n", bintext);
	while (i < 8)
	{
		if (bintext[i] == '1')
			kill(pid, SIGUSR1);
		else if (bintext[i] == '0')
			kill(pid, SIGUSR2);
		usleep(5000);
		i++;
	}
	bintext_zero();
}

void	decimal_to_bin(int dec_num)
{
	int	i;

	i = 7;
	bintext_zero();
	if (dec_num == -128)
	{
		bintext[0] = '1';
		return ;
	}
	if (dec_num < 0)
	{
		bintext[0] = '1';
		dec_num *= -1;
	}
	while (dec_num != 0 && i >= 1)
	{
		if (dec_num % 2 == 1)
			bintext[i] = '1';
		else
			bintext[i] = '0';
		i--;
		dec_num /= 2;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (0);
	i = 0;
	ft_printf("the message is: %s\n", argv[2]);
//	int	j;
//	j = 0;
//	while (argv[2][j] != '\0')
//	{
//		ft_printf("c: %d\n", (int)argv[2][j]);
//		j++;
//	}
//	ft_printf("characterlength: %d\n", j);
	while (argv[2][i] != '\0')
	{
		decimal_to_bin(argv[2][i]);
		sent_to(ft_atoi(argv[1]));
		i++;
	}
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	sent_to(ft_atoi(argv[1]));
	ft_printf("message_sent.\n");
	return (0);
}
