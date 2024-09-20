/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:36 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 11:30:45 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define FILE_NAME "test.txt"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	print_line(char *line)
{
	size_t	i;

	i = 0;
	if (line == 0)
	{
		write(1, "(null)\n", 7);
		return ;
	}
	while (line[i] != '\n' && line[i] != 0)
	{
		write(1, &line[i], 1);
		i++;
	}
	if (line[i] == '\n')
		write(1, "\\n\n", 3);
	if (line[i] == 0)
		write(1, "\\0\n", 3);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open(FILE_NAME, O_RDONLY);
	line = get_next_line(fd);
	print_line(line);
	if (line)
		free(line);
//	line = get_next_line(fd);
//	print_line(line);
//	if (line)
//		free(line);
//	line = get_next_line(fd);
//	print_line(line);
//	if (line)
//		free(line);
//	line = get_next_line(fd);
//	print_line(line);
//	if (line)
//		free(line);
//	line = get_next_line(fd);
//	print_line(line);
//	if (line)
//		free(line);
//	line = get_next_line(fd);
//	print_line(line);
//	if (line)
//		free(line);
	close(fd);
}
