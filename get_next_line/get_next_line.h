/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:14:00 by srussame          #+#    #+#             */
/*   Updated: 2024/09/11 16:47:28 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 3

typedef struct	s_go_read
{
	char	*read_buffer;
	char	*read_cat;
	size_t	read_ret;
	size_t	loop_count;
}				t_go_read;

typedef struct	s_join_readbuff
{
	char	*newcat;
	size_t	n;
	size_t	r;
}				t_join_readbuff;

typedef struct	s_gnl_data
{
	char	*return_line;
	int		ret;
}				t_gnl_data;


char	*get_next_line(int fd);
int		check_leftover(char **leftover, size_t *leftover_len, \
		char **return_line);
void	set_free(char **leftover, size_t *leftover_len);
size_t	check_readbuff(t_go_read *gr_data);

#endif
