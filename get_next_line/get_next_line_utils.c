/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:28:27 by srussame          #+#    #+#             */
/*   Updated: 2024/09/13 15:28:29 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	do_newleftover(char **leftover, size_t *leftover_len, \
			size_t start_index);
void		set_free(char **leftover, size_t *leftover_len);
size_t		check_readbuff(t_go_read *gr_data);
static int	check_leftover_sub1(char **return_line, size_t start_index, \
			char **leftover, size_t *leftover_len);

int	check_leftover(char **leftover, size_t *leftover_len, char **return_line)
{
	size_t	start_index;

	if (*leftover == 0)
		return (0);
	start_index = 0;
	while (start_index < *leftover_len)
	{
		if (*(*(leftover + start_index)) == '\n')
			break ;
		start_index++;
	}
	if (start_index == *leftover_len)
		return (1);
	return (check_leftover_sub1(return_line, \
	start_index, leftover, leftover_len));
}

static int	check_leftover_sub1(char **return_line, size_t start_index, \
	char **leftover, size_t *leftover_len)
{
	size_t	i;

	*return_line = (char *)malloc(start_index + 1);
	if (!(*return_line))
	{
		set_free(leftover, leftover_len);
		return (-1);
	}
	i = 0;
	while (i < start_index)
	{
		*(*(return_line + i)) = *(*(leftover + i));
		i++;
	}
	*(*(return_line + start_index)) = *(*(leftover + start_index));
	if (do_newleftover(leftover, leftover_len, start_index) == 0)
	{
		free(*return_line);
		return (-1);
	}
	return (2);
}

static int	do_newleftover(char **leftover, size_t *leftover_len, \
			size_t start_index)
{
	char	*new_leftover;
	size_t	i;

	if (++start_index == *leftover_len)
	{
		set_free(leftover, leftover_len);
		return (1);
	}
	new_leftover = (char *)malloc(*leftover_len - start_index);
	if (!new_leftover)
	{
		set_free(leftover, leftover_len);
		return (0);
	}
	i = 0;
	while (start_index < *leftover_len)
		new_leftover[i++] = *(*(leftover + start_index++));
	free(*leftover);
	*leftover = new_leftover;
	*leftover_len = *leftover_len - start_index;
	return (1);
}

void	set_free(char **leftover, size_t *leftover_len)
{
	if (!(*leftover))
	{
		free(*leftover);
		*leftover = 0;
	}
	*leftover_len = 0;
}

// return in the index that found '\n' in read_buffer
// if the return value == read_ret, '\n' is not found
size_t	check_readbuff(t_go_read *gr_data)
{
	size_t	i;

	i = 0;
	while (i < gr_data->read_ret && gr_data->read_buffer[i] != '\n')
		i++;
	return (i);
}
