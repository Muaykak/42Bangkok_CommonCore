/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:04:23 by muaykak           #+#    #+#             */
/*   Updated: 2025/06/28 21:12:52 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_count(int num, t_ft_printf *data)
{
	char	c;

	if (num < -2147483647)
	{
		if (ft_putstr_count("-2147483648", data) == -1)
			return (-1);
		return (1);
	}
	if (num < 0)
	{
		if (ft_putchar_count('-', data) == -1)
			return (-1);
		num = num * -1;
	}
	if (num / 10 != 0)
		if (ft_putnbr_count((num / 10), data) == -1)
			return (-1);
	c = (num % 10) + 48;
	if (ft_putchar_count(c, data) == -1)
		return (-1);
	return (1);
}
