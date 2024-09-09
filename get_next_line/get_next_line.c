/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:56:27 by srussame          #+#    #+#             */
/*   Updated: 2024/09/09 13:56:28 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char	*read_buffer;
	char	*line_str;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_buffer == 0)
		return (0);
	read_buffer[BUFFER_SIZE] = '\0';
	line_str = 0;
	read(fd, read_buffer, BUFFER_SIZE);
}

int		add_line_str(char **linestr, char *read_buffer, int read_return)
{
	int			count_read;
	static int	line_str_length;

	count_read = 0;
	while (count_read < read_return && read_buffer[count_read] != '\0')
	{
		if (read_buffer[count_read] == '\n')
		{
			line_str_length += 1;
			break ;
		}
		count_read++;
	}
	line_str_length += (count_read + 1);
	
}