/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:48:47 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 13:48:54 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_puthex_small(unsigned int num, int *count)
{
	if (num / 16 != 0)
		ft_printf_puthex_small(num / 16, count);
	if (num % 16 < 10)
		ft_putchar_count((num % 16) + 48, count);
	else
		ft_putchar_count((num % 16) + 87, count);
}
