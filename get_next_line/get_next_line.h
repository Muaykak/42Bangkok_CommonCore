/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:57:17 by srussame          #+#    #+#             */
/*   Updated: 2024/09/09 13:57:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 3

typedef struct	s_gnl_data
{
	char	*read_buffer;
	char	*return_string;
	int		return_str_size;
}				t_gnl_data;

typedef struct	s_newread_data
{
	int		i;
	int		j;
	int		check_return;
	char	*return_newstring;
}				t_newread_data;

char	*get_next_line(int fd);
void	ft_clearstr(char *str);
int		check_readbuffer(char *str, int return_read);

#endif
