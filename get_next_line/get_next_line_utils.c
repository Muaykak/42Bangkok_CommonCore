/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:55:21 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 20:55:22 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t check_newline(char *buffer);
static int	check_leftover_sub1(char **leftover, t_gnl_data *gnl, \
			t_check_leftover_data *cl);

int	check_leftover(char **leftover, t_gnl_data *gnl)
{
	t_check_leftover_data	cl;

	if (!(*leftover))
		return (0);
	cl.old_l = 0;
	while (!(*leftover)[cl.old_l])
		cl.old_l++;
	if (check_newline(*leftover) == cl.old_l)
	{
		gnl->return_line = *leftover;
		*leftover = 0;
		return (1);
	}
	cl.new_l = cl.old_l - (check_newline(*leftover) + 1);
	if (cl.new_l == 0)
	{
		gnl->return_line = *leftover;
		*leftover = 0;
		return (2);
	}
	return (check_leftover_sub1(leftover, gnl, &cl));
}

static int	check_leftover_sub1(char **leftover, t_gnl_data *gnl, \
			t_check_leftover_data *cl)
{
	gnl->return_line = (char *)malloc(cl->old_l - cl->new_l);
	if (!gnl->return_line)
		return (-1);
	cl->new_leftover = (char *)malloc(cl->new_l);
	if (!cl->new_leftover)
		return (-1);
	cl->old_l = 0;
	cl->new_l = 0;
	while ((*leftover)[cl->old_l] != '\n')
		gnl->return_line[cl->new_l++] = (*leftover)[cl->old_l++];
	gnl->return_line[cl->new_l] = (*leftover)[cl->old_l++];
	cl->new_l = 0;
	while (!(*leftover)[cl->old_l])
		cl->new_leftover[cl->new_l++] = (*leftover)[cl->old_l++];
	cl->new_leftover[cl->new_l] = '\0';
	free(*leftover);
	*leftover = cl->new_leftover;
	return (2);
}

size_t	check_newline(char *buffer)
{
	size_t	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (0);
}