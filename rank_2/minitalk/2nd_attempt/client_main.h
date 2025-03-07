/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:48:39 by srussame          #+#    #+#             */
/*   Updated: 2025/03/07 18:48:42 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MAIN_H
# define CLIENT_MAIN_H

# include "ft_minitalk.h"

typedef struct s_client
{
	char	*bintext;
	char	*str;
	int		str_index;	
}	t_client;

int		sent_to(int server_pid);
void	decimal_to_bin(int dec_num);
int		check_bintext(void);
void	bintext_zero(void);

void	sighandlr2(int signum, siginfo_t *info, void *ucontext);
void	sighandlr1(int signum, siginfo_t *info, void *ucontext);
void	check_argument(int argc, char **argv);

#endif
