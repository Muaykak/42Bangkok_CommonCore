/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex_big.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:12:41 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 14:12:43 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_puthex_big(unsigned int num, int *count)
{
	if (num / 16 != 0)
		ft_printf_puthex_big(num / 16, count);
	if (num % 16 < 10)
		ft_putchar_count((num % 16) + 48, count);
	else
		ft_putchar_count((num % 16) + 55, count);
}
