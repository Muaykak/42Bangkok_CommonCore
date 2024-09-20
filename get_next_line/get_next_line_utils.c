/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:11:08 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 11:34:03 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			join_leftover(t_gnl_data *gnl_data, t_goread_data *gr_data, \
			char **leftover);
static int	put_leftover(t_goread_data *gr_data, t_gnl_data *gnl_data, \
			char **leftover);
static int	check_leftover_sub1(char **leftover, t_checkleftover_data *cl, \
			t_gnl_data *gnl_data);

int	check_leftover(char **leftover, t_gnl_data *gnl_data)
{
	t_checkleftover_data	cl;

	if (!(*leftover))
		return (0);
	cl.left_i = 0;
	while ((*leftover)[cl.left_i] != 0 && (*leftover)[cl.left_i] != '\n')
		cl.left_i++;
	if ((*leftover)[cl.left_i] == 0)
		return (1);
	gnl_data->return_line = (char *)malloc(cl.left_i + 1);
	if (!gnl_data->return_line)
		return (-1);
	return (check_leftover_sub1(leftover, &cl, gnl_data));
}

static int	check_leftover_sub1(char **leftover, t_checkleftover_data *cl, \
			t_gnl_data *gnl_data)
{
	cl->new_i = 0;
	while (cl->new_i < cl->left_i)
	{
		gnl_data->return_line[cl->new_i] = (*leftover)[cl->new_i];
		cl->new_i++;
	}
	gnl_data->read_buffer[cl->new_i] = (*leftover)[cl->new_i];
	while ((*leftover)[cl->left_i] != 0)
		cl->left_i++;
	cl->leftnew_len = (cl->left_i - (cl->new_i));
	cl->new_leftover = (char *)malloc(cl->leftnew_len + 1);
	if (!cl->new_leftover)
		return (-1);
	while (cl->leftnew_len > 0)
		cl->new_leftover[cl->leftnew_len--] = (*leftover)[cl->left_i--];
	cl->new_leftover[cl->leftnew_len] = (*leftover)[cl->left_i];
	if (*leftover)
		free(*leftover);
	*leftover = cl->new_leftover;
	return (2);
}

int	join_leftover(t_gnl_data *gnl_data, t_goread_data *gr_data, \
	char **leftover)
{
	size_t	left_len;
	size_t	readcat_len;
	size_t	return_i;

	left_len = 0;
	if (!gr_data->readcat && !(*leftover))
		return (0);
	while ((*leftover) && gnl_data->cl_ret == 1 && (*leftover)[left_len] != 0)
		left_len++;
	readcat_len = 0;
	while (gr_data->readcat && gr_data->readcat[readcat_len] != 0)
		readcat_len++;
	gnl_data->return_line = (char *)malloc(left_len + readcat_len + 1);
	if (!gnl_data->return_line)
	{
		if ((*leftover))
			free(*leftover);
		*leftover = 0;
		if (gr_data->readcat)
			free(gr_data->readcat);
		return (0);
	}
	return_i = 0;
	left_len = 0;
	while ((*leftover) && (*leftover)[left_len] != 0)
		gnl_data->return_line[return_i++] = (*leftover)[left_len++];
	readcat_len = 0;
	while (gr_data->readcat && gr_data->readcat[readcat_len] != 0)
		gnl_data->return_line[return_i++] = gr_data->readcat[readcat_len++];
	gnl_data->return_line[return_i] = 0;
	if (gr_data->readcat)
		free(gr_data->readcat);
	if (put_leftover(gr_data, gnl_data, leftover) == 0)
	{
		free(gnl_data->return_line);
		gnl_data->return_line = 0;
		return (0);
	}
	return (1);
}

static int	put_leftover(t_goread_data *gr_data, t_gnl_data *gnl_data, \
			char **leftover)
{
	char	*new_leftover;
	size_t	new_i;

	if (*leftover)
		free(*leftover);
	*leftover = 0;
	if (gr_data->check_ret + 1 >= (size_t)gr_data->read_ret)
		return (1);
	new_leftover = (char *)malloc(gr_data->read_ret \
	- (gr_data->check_ret + 1) + 1);
	if (!new_leftover)
		return (0);
	new_i = 0;
	while (gr_data->check_ret + 1 + new_i < (size_t)gr_data->read_ret)
	{
		new_leftover[new_i] = \
		gnl_data->read_buffer[gr_data->check_ret + 1 + new_i];
		new_i++;
	}
	new_leftover[new_i] = \
	gnl_data->read_buffer[gr_data->check_ret + 1 + new_i];
	*leftover = new_leftover;
	return (1);
}
