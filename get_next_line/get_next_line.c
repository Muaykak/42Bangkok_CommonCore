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

char	*go_read(int fd, t_data *gnl_data, \
		char **leftover, int *leftover_len);
char	*add_newread(char *return_string, char *read_buffer, \
		int return_read, int read_count);
int		malloc_leftover(char **leftover, char *read_buffer, \
	int return_read, int *leftover_len);

char	*get_next_line(int fd)
{
	t_data		gnl_data;
	static char	*leftover_str;
	static int	leftover_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	gnl_data.return_string = 0;
	gnl_data.read_buffer = (char *)malloc(BUFFER_SIZE);
	if (!gnl_data.read_buffer)
		return (0);
	gnl_data.return_string = go_read(fd, gnl_data.read_buffer, &leftover_str, &leftover_len);
	if (gnl_data.return_string == 0)
	{
		free(gnl_data.read_buffer);
		return (0);
	}
	

}

char	*go_read(int fd, t_data *gnl_data, \
		char **leftover, int *leftover_len)
{
	int		read_count;
	int		return_read;
	char	*return_string;

	read_count = 1;
	return_string = 0;
	return_read = read(fd, read_buffer, BUFFER_SIZE);
	while (return_read > 0 \
	&& check_readbuffer(read_buffer, return_read) == BUFFER_SIZE)
	{
		return_string = add_newread(return_string, read_buffer, \
		return_read, read_count);
		if (return_string == 0)
			return (0);
		read_count++;
		return_read = read(fd, read_buffer, BUFFER_SIZE);
	}
	if (return_read < 1 && read_count == 1)
		return (0);
	if (check_readbuffer(read_buffer, return_read) != BUFFER_SIZE)
		if (malloc_leftover(leftover, read_buffer, \
		return_read, leftover_len) == 0)
			return (0);
	return (return_string);
}

char	*add_newread(char *return_string, char *read_buffer, \
		int return_read, int read_count)
{
	char	*return_newstring;
	int		i;
	int		j;
	int		check_return;

	if (!return_string && !read_buffer)
		return (0);
	check_return = check_readbuffer(read_buffer, return_read);
	if (check_return < return_read)
		check_return += 1;
	if (return_string == 0)
		return_newstring = (char *)malloc(check_return + 1);
	else
		return_newstring = (char *)malloc\
		(((read_count - 1) * BUFFER_SIZE) + check_return + 1);
	if (!return_newstring)
	{
		if (return_string)
			free(return_string);
		return_string = 0;
		return (0);
	}
	i = 0;
	if (return_string != 0)
	{
		while (i < ((read_count - 1) * BUFFER_SIZE))
		{
			return_newstring[i] = return_string[i];
			i++;
		}
		free(return_string);
	}
	j = 0;
	while (j < check_return)
		return_newstring[i++] = read_buffer[j++];
	return_newstring[i] = '\0';
	return (return_newstring);
}

int	malloc_leftover(char **leftover, char *read_buffer, \
	int return_read, int *leftover_len)
{
	int		i;
	int		count_len;

	if (*leftover != 0)
		free(*leftover);
	*leftover = 0;
	*leftover_len = 0;
	i = check_readbuffer(read_buffer, return_read) + 1;
	count_len = 0;
	if (i == return_read)
		return (1);
	*leftover = (char *)malloc((read_buffer - i));
	if (!(*leftover))
		return (0);
	while (*leftover_len < return_read - i)
	{
		*(*(leftover + *leftover_len)) = read_buffer[i];
		*leftover_len = *leftover_len + 1;
	}
//	*(*(leftover + *leftover_len)) = '\0';
	return (1);
}