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

static int	join_readbuff(t_go_read *gr_data);
static int	go_read(int fd, char **leftover, size_t *leftover_len, \
			t_gnl_data *gnl_data);
static void	go_read_sub1(t_gnl_data *gnl_data, t_go_read *gr_data, \
		char **leftover, size_t *leftover_len);
static void	join_leftover(t_go_read *gr_data, char **leftover, \
		size_t *leftover_len, t_gnl_data *gnl_data);

#include <stdio.h>

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
	else if (gnl_data.ret == -1)
		return (0);
	write(1, "leftover: \"", 11);
	write(1, leftover, leftover_len);
	write(1, "\"\n", 2);
	printf("leftover len: %zu\n", leftover_len);
	printf("gnl_data.ret: %d\n", gnl_data.ret);
	if (go_read(fd, &leftover, &leftover_len, &gnl_data) == 0)
		return (0);
	return (gnl_data.return_line);
}

static int	go_read(int fd, char **leftover, size_t *leftover_len, \
	t_gnl_data *gnl_data)
{
	t_go_read	gr_data;

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
			break ;
		gr_data.read_ret = read(fd, gr_data.read_buffer, BUFFER_SIZE);
		gr_data.loop_count++;
	}
	go_read_sub1(gnl_data, &gr_data, leftover, leftover_len);
	return (1);
}

static void	go_read_sub1(t_gnl_data *gnl_data, t_go_read *gr_data, \
		char **leftover, size_t *leftover_len)
{
	if (join_readbuff(gr_data) != 0)
	{
		if (gnl_data->ret == 1)
			join_leftover(gr_data, leftover, leftover_len, gnl_data);
		else
			gnl_data->return_line = gr_data->read_cat;
	}
	set_free(leftover, leftover_len);
	gr_data->l_start = check_readbuff(gr_data) + 1;
	if (gr_data->l_start < gr_data->read_ret)
	{
		*leftover = (char *)malloc(gr_data->read_ret - gr_data->l_start);
		if (*leftover != 0)
		{
			while (gr_data->l_start < gr_data->read_ret)
				(*leftover)[(*leftover_len)++] \
				= gr_data->read_buffer[gr_data->l_start++];
		}
	}
	free(gr_data->read_buffer);
}

static void	join_leftover(t_go_read *gr_data, char **leftover, \
		size_t *leftover_len, t_gnl_data *gnl_data)
{
	t_join_leftover	jl_data;

	jl_data.old_len = (BUFFER_SIZE * gr_data->loop_count) + gr_data->read_ret;
	jl_data.joinnew = (char *)malloc((*leftover_len) + jl_data.old_len);
	if (!jl_data.joinnew)
		return ;
	jl_data.new_i = 0;
	while (jl_data.new_i < *leftover_len)
		jl_data.joinnew[jl_data.new_i++] = (*leftover)[jl_data.new_i];
	jl_data.old_i = 0;
	while (jl_data.old_i < jl_data.old_len)
		jl_data.joinnew[jl_data.new_i++] = gr_data->read_cat[jl_data.old_i++];
	gnl_data->return_line = jl_data.joinnew;
	free(gr_data->read_cat);
}

static int	join_readbuff(t_go_read *gr_data)
{
	t_join_readbuff	j_data;

		write(1, "read_buffer: \"", 14);
		write(1, gr_data->read_buffer, gr_data->read_ret);
		write(1, "\"\n", 2);
	if (gr_data->read_cat == 0)
		j_data.newcat = (char *)malloc(gr_data->read_ret);
	else
		j_data.newcat = (char *)malloc((BUFFER_SIZE * gr_data->loop_count) \
		+ gr_data->read_ret);
	if (j_data.newcat == 0)
		return (0);
	j_data.n = 0;
	while (j_data.n < (BUFFER_SIZE * gr_data->loop_count) \
	&& gr_data->read_cat != 0)
	{
		j_data.newcat[j_data.n] = gr_data->read_cat[j_data.n];
		j_data.n++;
	}
	j_data.r = 0;
	while (j_data.r < gr_data->read_ret \
	&& gr_data->read_buffer[j_data.r] != '\n')
		j_data.newcat[j_data.n++] = gr_data->read_buffer[j_data.r++];
	if (gr_data->read_buffer[j_data.r] == '\n')
		j_data.newcat[j_data.n] = gr_data->read_buffer[j_data.r];
	if (gr_data->read_cat != 0)
		free(gr_data->read_cat);
	gr_data->read_cat = j_data.newcat;
	write(1, "newcat: \"", 9);
	write(1, gr_data->read_cat, j_data.n);
	write(1, "\"\n", 2);
	return (1);
}
