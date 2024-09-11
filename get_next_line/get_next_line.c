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

char	*go_read(int fd, t_gnl_data *gnl_data, \
		char **leftover, int *leftover_len);
char	*add_newread(t_gnl_data *gnl_data, \
		int return_read, int read_count);
int		malloc_leftover(char **leftover, char *read_buffer, \
	int return_read, int *leftover_len);
char	*malloc_newread(t_gnl_data *gnl_data, int *check_return, \
		int return_read, int read_count);

char	*get_next_line(int fd)
{
	t_gnl_data	gnl_data;
	static char	*leftover_str;
	char		*old_leftover_str;
	static int	leftover_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	gnl_data.return_string = 0;
	gnl_data.read_buffer = (char *)malloc(BUFFER_SIZE);
	if (!gnl_data.read_buffer)
		return (0);
	old_leftover_str = leftover_str;
	gnl_data.return_string = go_read(fd, &gnl_data, &leftover_str, \
	&leftover_len);
	if (gnl_data.return_string == 0)
	{
		free(gnl_data.read_buffer);
		return (0);
	}

}

char	*go_read(int fd, t_gnl_data *gnl_data, \
		char **leftover, int *leftover_len)
{
	int		read_count;
	int		return_read;

	read_count = 1;
	return_read = read(fd, gnl_data->read_buffer, BUFFER_SIZE);
	while (return_read > 0 \
	&& check_readbuffer(gnl_data->read_buffer, return_read) == BUFFER_SIZE)
	{
		gnl_data->return_string = add_newread(gnl_data, \
		return_read, read_count);
		if (gnl_data->return_string == 0)
			return (0);
		read_count++;
		return_read = read(fd, gnl_data->read_buffer, BUFFER_SIZE);
	}
	if (return_read < 1 && read_count == 1)
		return (0);
	if (check_readbuffer(gnl_data->read_buffer, return_read) != BUFFER_SIZE)
		if (malloc_leftover(leftover, gnl_data->read_buffer, \
		return_read, leftover_len) == 0)
			return (0);
	return (gnl_data->return_string);
}

char	*add_newread(t_gnl_data *gnl_data, \
		int return_read, int read_count)
{
	t_newread_data	nr;
//	char	*return_newstring;
//	int		i;
//	int		j;
//	int		check_return;

//	if (!gnl_data->return_string && !gnl_data->read_buffer)
//		return (0);
//	check_return = check_readbuffer(gnl_data->read_buffer, return_read);
//	if (check_return < return_read)
//		check_return += 1;
//	if (gnl_data->return_string == 0)
//	{
//		return_newstring = (char *)malloc(check_return + 1);
//	}
//	else
//	{
//		return_newstring = (char *)malloc\
//		(((read_count - 1) * BUFFER_SIZE) + check_return + 1);
//	}
//	if (!return_newstring)
//	{
//		if (gnl_data->return_string)
//			free(gnl_data->return_string);
//		gnl_data->return_string = 0;
//		return (0);
//	}
	nr.return_newstring = malloc_newread(gnl_data, \
	&nr.check_return, return_read, read_count);
	if (!nr.return_newstring)
		return (0);
	nr.i = 0;
	if (gnl_data->return_string != 0)
	{
		while (nr.i < ((read_count - 1) * BUFFER_SIZE))
		{
			nr.return_newstring[nr.i] = gnl_data->return_string[nr.i];
			nr.i++;
		}
		free(gnl_data->return_string);
	}
	nr.j = 0;
	while (nr.j < nr.check_return)
		nr.return_newstring[nr.i++] = gnl_data->read_buffer[nr.j++];
	nr.return_newstring[nr.i] = '\0';
	return (nr.return_newstring);
}

char	*malloc_newread(t_gnl_data *gnl_data, int *check_return, \
		int return_read, int read_count)
{
	char	*return_newstring;

	if (!gnl_data->return_string && !gnl_data->read_buffer)
		return (0);
	*check_return = check_readbuffer(gnl_data->read_buffer, return_read);
	if (*check_return < return_read)
		*check_return += 1;
	if (gnl_data->return_string == 0)
		return_newstring = (char *)malloc(*check_return + 1);
	else
		return_newstring = (char *)malloc(((read_count - 1) * BUFFER_SIZE)\
		 + *check_return + 1);
	if (!return_newstring)
	{
		if (gnl_data->return_string)
			free(gnl_data->return_string);
		gnl_data->return_string = 0;
		return (0);
	}
	if (gnl_data->return_string == 0)
		gnl_data->return_str_size = *check_return + 1;
	else
		gnl_data->return_str_size = (((read_count - 1) * BUFFER_SIZE) + \
		*check_return + 1);
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