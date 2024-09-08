/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:25:02 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 14:25:02 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void ft_puthexaddress_count(unsigned long ptr, int *count);

void	ft_putaddress_count(void *ptr, int *count)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		*count = *count + 5;
		return ;
	}
	write(1, "0x", 2);
	*count = *count + 2;
	ft_puthexaddress_count((unsigned long)ptr, count);
}

static void	ft_puthexaddress_count(unsigned long ptr, int *count)
{
	if (ptr / 16 != 0)
		ft_puthexaddress_count(ptr / 16, count);
	if (ptr % 16 < 10)
		ft_putchar_count((ptr % 16) + 48, count);
	else
		ft_putchar_count((ptr % 16) + 87, count);
}
