/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 06:46:01 by srussame          #+#    #+#             */
/*   Updated: 2024/09/24 16:43:21 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_count(char c, int *count);
int	ft_putstr_count(char *str, int *count);
int	ft_putnbr_count(int num, int *count);
int	ft_putuint_count(unsigned int num, int *count);
int	ft_putaddress_count(void *ptr, int *count);
int	ft_puthex_small_count(unsigned int num, int *count);
int	ft_puthex_big_count(unsigned int num, int *count);

#endif
