/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:11:20 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 11:51:15 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	go_read(int fd, char **leftover, t_gnl_data *gnl_data);
int			buffjoin(char **dest, char *readbuff);
static void	buffjoin_sub1(char **dest, char *readbuff, t_buffjoin_data *bj);
size_t	check_readbuffer(char *read_buffer, size_t read_ret);

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FILE];
	t_gnl_data	gnl_data;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	gnl_data.cl_ret = check_leftover(&leftover[fd], &gnl_data);
	if (gnl_data.cl_ret == 2)
		return (gnl_data.return_line);
	if (gnl_data.cl_ret == -1)
		return (0);
	gnl_data.read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!gnl_data.read_buffer)
		return (0);
	gnl_data.read_buffer[BUFFER_SIZE] = 0;
	gnl_data.gr_ret = go_read(fd, &leftover[fd], &gnl_data);
	free(gnl_data.read_buffer);
	if (gnl_data.gr_ret == 0)
		return (0);
	return (gnl_data.return_line);
}

static int	go_read(int fd, char **leftover, t_gnl_data *gnl_data)
{
	t_goread_data	gr_data;

	gr_data.loop_count = 0;
	gr_data.readcat = 0;
	gr_data.read_ret = read(fd, gnl_data->read_buffer, BUFFER_SIZE);
	if (gr_data.read_ret == -1)
		return (0);
	gnl_data->read_buffer[gr_data.read_ret] = 0;
	gr_data.check_ret = check_readbuffer(gnl_data->read_buffer, \
	gr_data.read_ret);
	while (gr_data.check_ret == BUFFER_SIZE)
	{
		if (buffjoin(&gr_data.readcat, gnl_data->read_buffer) == 0)
			return (0);
		gr_data.loop_count++;
		gr_data.read_ret = read(fd, gnl_data->read_buffer, BUFFER_SIZE);
		gnl_data->read_buffer[gr_data.read_ret] = 0;
		gr_data.check_ret = check_readbuffer(gnl_data->read_buffer, \
		gr_data.read_ret);
	}
	if (gr_data.read_ret > 0 \
	&& buffjoin(&gr_data.readcat, gnl_data->read_buffer) == 0)
		return (0);
	return (join_leftover(gnl_data, &gr_data, leftover));
}

int	buffjoin(char **dest, char *readbuff)
{
	t_buffjoin_data	bj;

	bj.new_len = 0;
		while ((*dest) && (*dest)[bj.new_len] != 0 && (*dest)[bj.new_len] != '\n')
			bj.new_len++;
	bj.buff_len = 0;
	while (readbuff && readbuff[bj.buff_len] && readbuff[bj.buff_len] != '\n')
		bj.buff_len++;
	bj.new_len = bj.new_len + bj.buff_len + 1;
	bj.newdest = (char *)malloc(bj.new_len);
	if (!bj.newdest || (bj.buff_len == 0 && readbuff[bj.buff_len] == -1))
	{
		if (bj.newdest)
			free(bj.newdest);
		if ((*dest))
			free(*dest);
		return (0);
	}
	buffjoin_sub1(dest, readbuff, &bj);
	return (1);
}

static void	buffjoin_sub1(char **dest, char *readbuff, t_buffjoin_data *bj)
{
	bj->new_i = 0;
	while ((*dest) && (*dest)[bj->new_i] != 0 \
	&& (*dest)[bj->new_i] != '\n')
	{
		bj->newdest[bj->new_i] = (*dest)[bj->new_i];
		bj->new_i++;
	}
	bj->buff_i = 0;
	while (bj->new_i < bj->new_len)
		bj->newdest[bj->new_i++] = readbuff[bj->buff_i++];
	bj->newdest[bj->new_i] = 0;
	if (*dest)
		free(*dest);
	*dest = bj->newdest;
}

size_t	check_readbuffer(char *read_buffer, size_t read_ret)
{
	size_t	i;

	i = 0;
	while (read_buffer[i] != '\n' && i < read_ret)
		i++;
	return (i);
}
