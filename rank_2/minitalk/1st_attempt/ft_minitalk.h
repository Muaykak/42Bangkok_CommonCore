/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:53:46 by srussame          #+#    #+#             */
/*   Updated: 2024/11/29 13:53:47 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>

int	bin_to_decimal(char *bin);
int	ft_power(int x, int pow);
void	bintext_init(char *str);
void	bintext_process(int *num);
void	sigusr1_handler(int sig);
void	sigusr2_handler(int sig);
int	ft_strcmp(char *s1, char *s2);

#endif
