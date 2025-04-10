/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:02:38 by srussame          #+#    #+#             */
/*   Updated: 2025/04/11 00:09:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf_fd(const char *str, ...)
{
	va_list	args;
	int		count;
	
	if (str == NULL)
		return (-1);
	va_start(args, str);
}
