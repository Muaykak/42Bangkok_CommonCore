/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:43:16 by srussame          #+#    #+#             */
/*   Updated: 2025/03/19 18:43:17 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			map_check_path(t_map_info **map_info);
//int			map_check_path_data(t_list **path_data, int path_x, int path_y);

int			map_check_path_data(t_map_data **map_data, int path_x, int path_y);

static int	map_check_path_sub2(t_map_info **map_info);

void	reset_check_path(t_map_info *map_info);

static int	map_check_path_sub2(t_map_info **map_info)
{
	t_list	*temp;

	temp = (*map_info)->collects;
	while (temp != NULL)
	{
		(*map_info)->path_dest = ((t_map_data *)(temp->content));
		map_check_path_sub1(*map_info, (*map_info)->player->x,
			(*map_info)->player->y);
		if ((*map_info)->path_dest->status == FALSE)
		{
			free_map_info(map_info);
			return (0);
		}
		reset_check_path(*map_info);
		temp = temp->next;
	}
	return (1);
}

int	map_check_path(t_map_info **map_info)
{
	if (map_info == NULL || (*map_info) == NULL)
		return (0);
	(*map_info)->path_dest = (*map_info)->path_exit;
	map_check_path_sub1((*map_info), (*map_info)->path_player->x,
		(*map_info)->path_player->y);
	reset_check_path(*map_info);
	ft_printf("exit path clear\n");
	if ((*map_info)->path_dest->status == FALSE)
	{
		free_map_info(map_info);
		ft_strerr("Error\n: No valid path to complete the game\n");
		return (0);
	}
	if (map_check_path_sub2(map_info) == 0)
	{
		ft_strerr("Error\n: No valid path to complete the game\n");
		return (0);
	}
	ft_printf("collect path clear\n");
	return (1);
}

void	reset_check_path(t_map_info *map_info)
{
	int			y;
	int			x;
	t_map_data	**map_data;

	if (map_info == NULL || map_info->map_data == NULL)
		return ;
	map_data = map_info->map_data;
	y = 0;
	while (y < map_info->map_height)
	{
		x = 0;
		while (x < map_info->map_width)
		{
			map_data[y][x].path_check = FALSE;
			x++;
		}
		y++;
	}
	return ;
}

int	map_check_path_data(t_map_data **map_data, int path_x, int path_y)
{
	if (map_data == NULL)
		return (0);
	if (map_data[path_y][path_x].path_check == TRUE)
		return (1);
	map_data[path_y][path_x].path_check = TRUE;
		return (0);
}

///* return 1 if this path is already pass*/
//int	map_check_path_data(t_list **path_data, int path_x, int path_y)
//{
//	t_list		*temp;
//	t_map_path	*new_path;
//
//	if (path_data == NULL)
//		return (0);
//	temp = *path_data;
//	while (temp != NULL)
//	{
//		if (((t_map_path *)(temp->content))->x == path_x
//			&& ((t_map_path *)(temp->content))->y == path_y)
//			return (1);
//		temp = temp->next;
//	}
//	new_path = (t_map_path *)ft_calloc(1, sizeof(t_map_path));
//	if (new_path == NULL)
//	{
//		ft_lstclear(path_data, &free_path_data);
//		*path_data = 0;
//		perror("Error\nmap_check_path_data(): ");
//		return (0);
//	}
//	new_path->x = path_x;
//	new_path->y = path_y;
//	ft_lstadd_front(path_data, ft_lstnew(&new_path[0]));
//	return (0);
//}
