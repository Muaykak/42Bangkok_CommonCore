/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:51:47 by muaykak           #+#    #+#             */
/*   Updated: 2025/04/11 17:31:44 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (write(1, &str[i], 1) == -1)
			return (-1);
		data->count += 1;
		i++;
	}
	return (1);
}
