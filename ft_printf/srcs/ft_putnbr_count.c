/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:36:00 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 12:36:01 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_count(int num, int *count)
{
	char	c;

	if (num < -2147483647)
	{
		write(1, "-2147483648", 11);
		*count = *count + 11;
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		*count = *count + 1;
		num = num * -1;
	}
	if (num / 10 != 0)
		ft_putnbr_count((num / 10), count);
	c = (num % 10) + 48;
	write(1, &c, 1);
	*count = *count + 1;
}
