/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:21:59 by muaykak           #+#    #+#             */
/*   Updated: 2025/06/28 21:13:10 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putuint_count(unsigned int num, t_ft_printf *data)
{
	if (num / 10 != 0)
	{
		if (ft_putuint_count((num / 10), data) == -1)
			return (-1);
	}
	if (ft_putchar_count((char)((num % 10) + 48), data) == -1)
		return (-1);
	return (1);
}
