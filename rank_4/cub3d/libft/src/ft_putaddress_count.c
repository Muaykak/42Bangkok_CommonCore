/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:33:55 by muaykak           #+#    #+#             */
/*   Updated: 2025/06/28 21:11:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_puthexaddress_count(unsigned long ptr, t_ft_printf *data);

int	ft_putaddress_count(void *ptr, t_ft_printf *data)
{
	if (ptr == 0)
	{
		if (ft_putstr_count("(nil)", data) == -1)
			return (-1);
		return (1);
	}
	if (ft_putstr_count("0x", data) == -1)
		return (-1);
	if (ft_puthexaddress_count((unsigned long)ptr, data) == -1)
		return (-1);
	return (1);
}

static int	ft_puthexaddress_count(unsigned long ptr, t_ft_printf *data)
{
	if (ptr / 16 != 0)
	{
		if (ft_puthexaddress_count(ptr / 16, data) == -1)
			return (-1);
	}
	if (ptr % 16 < 10)
	{
		if (ft_putchar_count((ptr % 16) + 48, data) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_count((ptr % 16) + 87, data) == -1)
			return (-1);
	}
	return (1);
}
