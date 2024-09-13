/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:42:53 by srussame          #+#    #+#             */
/*   Updated: 2024/09/11 16:45:49 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*leftover;
	static size_t	leftover_len;
	t_gnl_data		gnl_data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	gnl_data.ret = check_leftover(&leftover, &leftover_len, \
	&gnl_data.return_line);
	if (gnl_data.ret == 2)
		return (gnl_data.return_line);
	else if (gnl_data.ret = -1)
		return (0);

}

int	go_read(int fd, char **leftover, size_t *leftover_len, \
	t_gnl_data *gnl_data)
{
	t_go_read gr_data;

	gr_data.read_buffer = (char *)malloc(BUFFER_SIZE);
	if (!gr_data.read_buffer)
		return (0);
	gr_data.read_cat = 0;
	gr_data.read_ret = read(fd, gr_data.read_buffer, BUFFER_SIZE);
	gr_data.loop_count = 0;
	while (gr_data.read_ret == BUFFER_SIZE \
	&& check_readbuff(&gr_data) == gr_data.read_ret)
	{
		if (join_readbuff(&gr_data) == 0)
		{
			free(gr_data.read_buffer);
			return (0);
		}
		gr_data.read_ret = read(fd, gr_data.read_buffer, BUFFER_SIZE);
		if (gr_data.read_ret == BUFFER_SIZE)
			gr_data.loop_count++;
	}
	if (join_readbuff(&gr_data) == 0)
	{
		free(gr_data.read_buffer);
		return (0);
	}
	if (gnl_data->ret == 1)

}

int join_leftover(t_go_read *gr_data, char **leftover, \
	size_t leftover_len, t_gnl_data *gnl_data)
{

}

int	join_readbuff(t_go_read *gr_data)
{
	t_join_readbuff j_data;

	if (gr_data->read_cat == 0)
		j_data.newcat = (char *)malloc(gr_data->read_ret);
	else
		j_data.newcat = (char *)malloc((BUFFER_SIZE * gr_data->loop_count) \
		+ gr_data->read_ret);
	if (!j_data.newcat)
		return (0);
	j_data.n = 0;
	while (j_data.n < (BUFFER_SIZE * gr_data->loop_count) \
	&& gr_data->read_cat != 0)
		j_data.newcat[j_data.n++] = *(gr_data->read_cat + j_data.n);
	j_data.r = 0;
	while (j_data.r < gr_data->read_ret \
	&& gr_data->read_buffer[j_data.r] != '\n')
		j_data.newcat[j_data.n++] = gr_data->read_buffer[j_data.r++];
	if (gr_data->read_buffer[j_data.r] == '\n')
		j_data.newcat[j_data.n] = gr_data->read_buffer[j_data.r];
	if (gr_data->read_cat != 0)
		free(*gr_data->read_cat);
	gr_data->read_cat = j_data.newcat;
	return (1);
}
