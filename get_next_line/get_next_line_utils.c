/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:56:58 by srussame          #+#    #+#             */
/*   Updated: 2024/09/09 13:57:00 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

// return the index that found "\n"
//	if none return return_read
int	check_readbuffer(char *read_buffer, int return_read)
{
	unsigned int	i;

	i = 0;
	while (i < return_read)
	{
		if (read_buffer[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
