/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:54:51 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 20:54:53 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	buffjoin(char **dest, char *src);
static int	put_leftover(t_goread_data *gr, char **leftover);
static int	go_read(int fd, t_gnl_data *gnl, char **leftover);

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FILE];
	t_gnl_data	gnl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	gnl.return_line = 0;
	gnl.cl_ret = check_leftover(&leftover[fd], &gnl);
	if (gnl.cl_ret == -1)
	{
		free(leftover[fd]);
		leftover[fd] = 0;
		return (0);
	}
	if (gnl.cl_ret == 2)
		return (gnl.return_line);
	if (go_read(fd, &gnl, &leftover[fd]) == 0)
	{
		if (gnl.cl_ret == 1)
			free(gnl.return_line);
		return (0);
	}
	return (gnl.return_line);
}

static int	go_read(int fd, t_gnl_data *gnl, char **leftover)
{
	t_goread_data	gr;

	gr.readcat = 0;
	gr.read_ret = read(fd, gnl->read_buffer, BUFFER_SIZE);
	if (gr.read_ret <= 0)
		return (0);
	gnl->read_buffer[gr.read_ret] = 0;
	gr.checkline_ret = check_newline(gnl->read_buffer);
	while (gr.checkline_ret == BUFFER_SIZE)
	{
		if (buffjoin(&gr.readcat, gnl->read_buffer) == 0)
			return (0);
		gr.read_ret = read(fd, gnl->read_buffer, BUFFER_SIZE);
		gnl->read_buffer[gr.read_ret] = 0;
		gr.checkline_ret = check_newline(gnl->read_buffer);
	}
	if (buffjoin(&gr.readcat, gnl->read_buffer) == 0)
		return (0);
	if (buffjoin(&gnl->return_line, gr.readcat) == 0)
		return (0);
	return (put_leftover(&gr, leftover));
}

static int	put_leftover(t_goread_data *gr, char **leftover)
{
	t_putleft_data	pl;

	if (*leftover)
		free(*leftover);
	*leftover = 0;
	if (gr->checkline_ret + 1 >= (size_t)gr->read_ret)
		return (1);
	pl.new_len = gr->read_ret - (gr->checkline_ret + 1);
	pl.new_left = (char *)malloc(pl.new_len + 1);
	if (!pl.new_left)
	{
		if (gr->readcat)
			free(gr->readcat);
		return (0);
	}
	pl.new_len = 0;
	while (gr->checkline_ret < (size_t)gr->read_ret)
		pl.new_left[pl.new_len++] = gr->readcat[gr->checkline_ret++];
	pl.new_left[pl.new_len] = 0;
	if (gr->readcat)
		free(gr->readcat);
	*leftover = pl.new_left;
	return (1);
}

static int	buffjoin(char **dest, char *src)
{
	t_buffjoin_data	bj;

	bj.old_len = 0;
	while ((*dest) && (*dest)[bj.old_len] != 0)
		bj.old_len++;
	bj.new_len = 0;
	while (src && src[bj.new_len] != 0 && src[bj.new_len] != '\n')
		bj.new_len++;
	bj.new_len = bj.new_len + bj.old_len;
	bj.new_dest = (char *)malloc(bj.new_len + 1);
	if (!bj.new_dest)
	{
		if (*dest)
			free(*dest);
		return (0);
	}
	bj.old_len = 0;
	bj.new_len = 0;
	while ((*dest) && (*dest)[bj.old_len] != 0)
		bj.new_dest[bj.new_len++] = (*dest)[bj.old_len++];
	bj.old_len = 0;
	while (src && src[bj.old_len] != '\n' && src[bj.old_len] != 0)
		bj.new_dest[bj.new_len++] = src[bj.old_len++];
	bj.new_dest[bj.new_len] = src[bj.old_len];
	if (*dest)
		free(*dest);
	*dest = bj.new_dest;
	return (1);
}
