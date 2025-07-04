/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_small_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:31:54 by muaykak           #+#    #+#             */
/*   Updated: 2025/06/28 21:12:48 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthex_small_count(unsigned int num, t_ft_printf *data)
{
	if (num / 16 != 0)
	{
		if (ft_puthex_small_count(num / 16, data) == -1)
			return (-1);
	}
	if (num % 16 < 10)
	{
		if (ft_putchar_count((num % 16) + 48, data) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_count((num % 16) + 87, data) == -1)
			return (-1);
	}
	return (1);
}
