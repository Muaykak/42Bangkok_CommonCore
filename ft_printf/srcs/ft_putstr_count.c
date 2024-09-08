/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:02:50 by srussame          #+#    #+#             */
/*   Updated: 2024/09/08 13:02:51 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_count(char *str, int *count)
{
	int	i;

	if (str == 0)
	{
		write(1, "(null)", 6);
		*count = *count + 6;
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		*count = *count + 1;
		i++;
	}
}
