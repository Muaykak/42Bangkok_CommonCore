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

int		add_line_str\
(char **linestr, char *read_buffer, int read_return, int *line_strlen);

char	*get_next_line(int fd)
{
	char	*read_buffer;
	char	*line_str;
	int		line_strlen;

	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_buffer == 0)
		return (0);
	read_buffer[BUFFER_SIZE] = '\0';
	line_str = 0;
	read(fd, read_buffer, BUFFER_SIZE);
}

int		add_line_str\
(char **linestr, char *read_buffer, int read_return, int *line_strlen)
{
	int	count_read;

	count_read = 0;
	while (count_read < read_return && read_buffer[count_read] != '\0')
	{
		if (read_buffer[count_read] == '\n')
		{
			*line_strlen += 1;
			break ;
		}
		count_read++;
	}
	*line_strlen += (count_read + 1);

}

int	main(void)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)malloc(1);
	ptr2 = ptr1;
	free(ptr2);
}