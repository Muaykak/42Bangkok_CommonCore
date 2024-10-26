/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:55:08 by srussame          #+#    #+#             */
/*   Updated: 2024/09/20 20:55:09 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_gnl_data
{
	int		cl_ret;
	char	*return_line;
	char	*read_buffer;

}				t_gnl_data;

typedef struct s_check_leftover_data
{
	size_t	old_l;
	size_t	new_l;
	char	*new_leftover;
}				t_check_leftover_data;

typedef struct s_goread_data
{
	long long	read_ret;
	size_t		checkline_ret;
	char		*readcat;
}				t_goread_data;

typedef struct s_buffjoin_data
{
	size_t	old_len;
	size_t	new_len;
	char	*new_dest;
}				t_buffjoin_data;

typedef struct s_putleft_data
{
	size_t	new_len;
	size_t	new_i;
}				t_putleft_data;

char	*get_next_line(int fd);
int		check_leftover(char **leftover, t_gnl_data *gnl);
size_t	check_newline(char *buffer);
int		put_leftover(t_goread_data *gr, char **leftover,
			t_gnl_data *gnl);
#endif
