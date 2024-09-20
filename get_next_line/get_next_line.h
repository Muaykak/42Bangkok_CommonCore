/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:10:51 by srussame          #+#    #+#             */
/*   Updated: 2024/09/16 14:10:52 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_data
{
	char	*return_line;
	char	*read_buffer;
	int		cl_ret;
	int		gr_ret;
}				t_gnl_data;

typedef struct s_goread_data
{
	size_t	read_ret;
	size_t	loop_count;
	size_t	check_ret;
	char	*readcat;
}				t_goread_data;

typedef struct s_buffjoin_data
{
	size_t	new_len;
	size_t	new_i;
	size_t	buff_len;
	size_t	buff_i;
	char	*newdest;
}				t_buffjoin_data;

typedef struct s_checkleftover_data
{
	char	*new_leftover;
	size_t	leftnew_len;
	size_t	left_i;
	size_t	new_i;
}				t_checkleftover_data;

# define BUFFER_SIZE 5 
# define MAX_FILE 1024

char	*get_next_line(int fd);
int		check_leftover(char **leftover, t_gnl_data *gnl_data);
size_t	check_readbuffer(char *read_buffer, size_t read_ret);
int		join_leftover(t_gnl_data *gnl_data, t_goread_data *gr_data, \
		char **leftover);
int		buffjoin(char **dest, char *readbuff);

#endif
