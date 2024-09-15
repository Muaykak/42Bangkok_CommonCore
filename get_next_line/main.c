/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:36 by srussame          #+#    #+#             */
/*   Updated: 2024/09/09 14:15:37 by srussame         ###   ########.fr       */
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
	while (line[i] != '\n')
	{
		write(1, &line[i], 1);
		i++;
	}
	if (line[i] == '\n')
		write(1, "\n", 1);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open(FILE_NAME, O_RDONLY);
	line = get_next_line(fd);
	print_line(line);
	write(1, "\n", 1);
	line = get_next_line(fd);
	print_line(line);
	write(1, "\n", 1);
	line = get_next_line(fd);
	print_line(line);
	write(1, "\n", 1);
//	line = get_next_line(fd);
//	print_line(line);
//	line = get_next_line(fd);
//	print_line(line);
//	line = get_next_line(fd);
//	print_line(line);
//	line = get_next_line(fd);
//	print_line(line);
//	line = get_next_line(fd);
//	print_line(line);
//	line = get_next_line(fd);
//	print_line(line);
//	line = get_next_line(fd);
//	print_line(line);
//	if(line != 0)
//		print_line(line);
//	char	str[] = "Hello";
//
//	printf("before: \"%s\"\nLength: %u\n", str, ft_strlen(str));
//	ft_clearstr(str);
//	printf("after: \"%s\"\nLength: %u\n", str, ft_strlen(str));
//	return (0);
}
