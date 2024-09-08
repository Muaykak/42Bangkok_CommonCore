/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:41:28 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 11:41:30 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
void	ft_putnbr_count(int	num, int *count);
void	ft_putstr_count(char *str, int *count);
void	ft_putchar_count(char c, int *count);
void	ft_printf_puthex_small(unsigned int num, int *count);
void	ft_printf_puthex_big(unsigned int num, int *count);
void	ft_putaddress_count(void *ptr, int *count);
void	ft_putuint_count(unsigned int num, int *count);

#endif
