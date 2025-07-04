/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:52 by muaykak           #+#    #+#             */
/*   Updated: 2025/06/28 21:11:50 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putchar_count(char c, t_ft_printf *data)
{
	if (write(data->fd, &c, 1) == -1)
		return (-1);
	data->count += 1;
	return (1);
}
