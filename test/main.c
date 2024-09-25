/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:25:59 by srussame          #+#    #+#             */
/*   Updated: 2024/09/21 17:31:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*read_buffer;

	read_buffer = (char *)malloc(1024);
	if (!read_buffer)
		return (0);
	read_buffer[read(0, read_buffer, 10)] = '\0';
	printf("read_buffer: \"%s\"\n", read_buffer);
	free(read_buffer);
	return (1);
}
