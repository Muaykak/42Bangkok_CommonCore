/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <sutawith@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:47 by muaykak           #+#    #+#             */
/*   Updated: 2025/06/28 21:36:19 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_count(char *str, t_ft_printf *data)
{
	size_t	i;

	if (!str)
	{
		if (write(data->fd, "(null)", 6) == -1)
			return (-1);
		data->count += 6;
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (write(data->fd, &str[i], 1) == -1)
			return (-1);
		data->count += 1;
		i++;
	}
	return (1);
}
