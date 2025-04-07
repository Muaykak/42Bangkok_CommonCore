/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:38:17 by srussame          #+#    #+#             */
/*   Updated: 2025/03/15 15:38:18 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char		**get_map_char(char *filepath);

//static char	*read_map(int fd);
static int	map_check_extention(char *filepath);
//static char	*map_read_check(char *new_cat, char *str, int fd);
//static char	*read_map_sub1(char *new_cat, char *str);

/* get a list of strings readed from the map file*/
t_list	*read_list_map(int fd);
char	**read_list_to_map_data(t_list **read_list);

/* Objective : read the map as format from the path given from argument
				RETURN as ** array of STRINGS **

				*** USE MALLOC OBVIOUSLY **
*/

char	**get_map_char(char *filepath)
{
	char	**map_data;
	t_list	*map_read;
	int		fd;

	if (filepath == NULL || map_check_extention(filepath) == 0)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n\nCAN\'T OPEN FILE");
		return (NULL);
	}
	map_read = read_list_map(fd);
	close(fd);
	if (map_read == NULL)
		return (NULL);
	map_data = read_list_to_map_data(&map_read);
	if (map_data == NULL)
		perror("\nError\nget_map_char()");
	return (map_data);
}

char	**read_list_to_map_data(t_list **read_list)
{
	size_t	length;
	t_list	*temp;
	char	**map_data;

	if (read_list == NULL || (*read_list) == NULL)
		return (NULL);
	length = 0;
	temp = *read_list;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	map_data = (char **)ft_calloc(length + 1, sizeof(char *));
	if (map_data == NULL)
		return (NULL);
	temp = *read_list;
	length = 0;
	while (temp != NULL)
	{
		map_data[length++] = (char *)(temp->content);
		temp = temp->next;
	}
	return (ft_lstclear(read_list, &free_collect), map_data);
}

/* get a list of strings readed from the map file*/
t_list	*read_list_map(int fd)
{
	t_list	*list;
	t_list	*new_list;
	char	*new_read;

	list = 0;
	new_read = get_next_line(fd);
	while (new_read != NULL && ft_strncmp(new_read, "\n", 1) == 0)
	{
		free(new_read);
		new_read = get_next_line(fd);
	}
	while (new_read != NULL && ft_strncmp(new_read, "\n", 1 != 0))
	{
		new_read = ft_strtrim(new_read, "\n");
		if (new_read == NULL)
		{
			perror("Error\n\nread_list_map()");
			return (ft_lstclear(&list, &free_path_data), NULL);
		}
		new_list = ft_lstnew(&new_read[0]);
		if (new_list == NULL)
		{
			perror("Error\n\nread_list_map()");
			return (ft_lstclear(&list, &free_path_data), NULL);
		}
		ft_lstadd_back(&list, new_list);
		new_read = get_next_line(fd);
	}
	if (new_read == NULL)
		return (list);
	while (new_read != NULL && ft_strncmp(new_read, "\n", 1) == 0)
	{
		free(new_read);
		new_read = get_next_line(fd);
	}
	if (new_read != NULL)
	{
		ft_strerr("Error\n: The map file should contain only one map and"
			" should not contain any letters beside the map\n\n");
		return (ft_lstclear(&list, &free_path_data), NULL);
	}
	return (list);
}

/* get the concated string that separated by newline '\n' */
/* use MALLOC */
//char	*read_map(int fd)
//{
//	char	*str;
//	char	*temp;
//	char	*new_cat;
//
//	new_cat = 0;
//	str = get_next_line(fd);
//	while (str != NULL && ft_strncmp(str, "\n", 1) == 0)
//	{
//		free(str);
//		str = get_next_line(fd);
//	}
//	while (str != NULL && ft_strncmp(str, "\n", 1) != 0)
//	{
//		temp = ft_strjoin(new_cat, str);
//		if (temp == NULL)
//			return (read_map_sub1(new_cat, str));
//		if (new_cat != NULL)
//			free(new_cat);
//		free(str);
//		new_cat = temp;
//		str = get_next_line(fd);
//	}
//	return (map_read_check(new_cat, str, fd));
//}
//
//static char	*read_map_sub1(char *new_cat, char *str)
//{
//	if (new_cat)
//		free(new_cat);
//	if (str)
//		free(str);
//	perror("\nError\nread_map()");
//	return (NULL);
//}
//
//char	*map_read_check(char *new_cat, char *str, int fd)
//{
//	if (str == NULL)
//		return (new_cat);
//	while (str != NULL && ft_strncmp(str, "\n", 1) == 0)
//	{
//		free(str);
//		str = get_next_line(fd);
//	}
//	if (str != NULL)
//	{
//		ft_strerr("Error\n: The map file should contain only one map and"
//			" should not contain any letters beside the map\n\n");
//		if (new_cat)
//			free(new_cat);
//		new_cat = NULL;
//	}
//	return (new_cat);
//}

/* Check if the mapfile has the correct extension ('.ber') */

int	map_check_extention(char *filepath)
{
	size_t	name_length;

	if (filepath == NULL)
		return (0);
	name_length = ft_strlen(filepath);
	if (name_length < 5)
	{
		ft_printf("Error\n\nWRONG MAP filepath!\n");
		return (0);
	}
	if (ft_strncmp(&filepath[name_length - 4], ".ber", 4) != 0)
	{
		ft_printf("Error\n\nWRONG MAP filepath!\n");
		return (0);
	}
	return (1);
}
