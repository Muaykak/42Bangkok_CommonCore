/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaykak <muaykak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:41:52 by muaykak           #+#    #+#             */
/*   Updated: 2025/04/11 17:15:36 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_count(char c, t_ft_printf *data)
{
	if (write(data->fd, &c, 1) == -1)
		return (-1);
	data->count += 1;
	return (1);
}
