/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:34:21 by srussame          #+#    #+#             */
/*   Updated: 2025/01/14 14:34:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free_split(char **save)
{
	size_t	i;

	i = 0;
	while (save[i] != 0)
	{
		free(save[i]);
		i++;
	}
	free(save);
}

void	free_number(void *number)
{
	if (number != NULL)
		free(number);
	return ;
}
