/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:24:13 by srussame          #+#    #+#             */
/*   Updated: 2025/03/18 22:24:14 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	map_path_up(int path_x, int path_y,
// 				t_map_info *map_info);
// static int	map_path_down(int path_x, int path_y,
// 				t_map_info *map_info);
// static int	map_path_left(int path_x, int path_y,
// 				t_map_info *map_info);
// static int	map_path_right(int path_x, int path_y,
// 				t_map_info *map_info);

void	add_fill_list_error(t_list **fill_list, t_map_info *map_info)
{
		perror("Error\n\nmap_check_path_sub1()");
		ft_lstclear(fill_list, &free_path_data);
		free_map_info(&map_info);
		exit(EXIT_FAILURE);
}

void	add_left_fill_list(t_list **fill_list, t_map_info *map_info, t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y][mark->x - 1].type == WALL
		|| (map_info->map_data)[mark->y][mark->x - 1].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x - 1;
	new_fill->y = mark->y;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

void	add_right_fill_list(t_list **fill_list, t_map_info *map_info, t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y][mark->x + 1].type == WALL
		|| (map_info->map_data)[mark->y][mark->x + 1].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x + 1;
	new_fill->y = mark->y;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

void	add_up_fill_list(t_list **fill_list, t_map_info *map_info, t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y - 1][mark->x].type == WALL
		|| (map_info->map_data)[mark->y - 1][mark->x].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x;
	new_fill->y = mark->y - 1;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

void	add_down_fill_list(t_list **fill_list, t_map_info *map_info, t_map_path *mark)
{
	t_map_path	*new_fill;
	t_list		*new_fill_list;

	if (fill_list == NULL || map_info == NULL || mark == NULL)
		return ;
	if ((map_info->map_data)[mark->y + 1][mark->x].type == WALL
		|| (map_info->map_data)[mark->y + 1][mark->x].path_check == TRUE)
		return ;
	new_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (new_fill == NULL)
		add_fill_list_error(fill_list, map_info);
	new_fill->x = mark->x;
	new_fill->y = mark->y + 1;
	new_fill_list = ft_lstnew(&new_fill[0]);
	if (new_fill_list == NULL)
		add_fill_list_error(fill_list, map_info);
	ft_lstadd_front(fill_list, new_fill_list);
}

void	add_fill_list(t_list **fill_list, t_map_info *map_info, t_map_path *mark)
{
	if (fill_list == NULL || map_info == NULL)
		return ;
	add_up_fill_list(fill_list, map_info, mark);
	add_down_fill_list(fill_list, map_info, mark);
	add_left_fill_list(fill_list, map_info, mark);
	add_right_fill_list(fill_list, map_info, mark);
}

void	ft_lstremove_top(t_list	**lst)
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	temp = *lst;
	(*lst) = (*lst)->next;
	ft_lstdelone(temp, &free_path_data);
}

int		mark_check_path(t_list **fill_list, t_map_info *map_info)
{
	t_map_path	mark;

	if (fill_list == NULL || *fill_list == NULL)
		return (0);
	mark = *((t_map_path *)((*fill_list)->content));
	(map_info->map_data)[mark.y][mark.x].path_check = TRUE;
	ft_lstremove_top(fill_list);
	add_fill_list(fill_list, map_info, &mark);
	return (1);
}

void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y)
{
	t_map_path	*to_fill;
	t_list		*fill_list;
	t_list		*first_list;

	if (map_info == NULL)
		return ;
	fill_list = 0;
	to_fill = (t_map_path *)malloc(1 * sizeof(t_map_path));
	if (to_fill == NULL)
		add_fill_list_error(&fill_list, map_info);
	to_fill->x = path_x;
	to_fill->y = path_y;
	first_list = ft_lstnew(&to_fill[0]);
	if (first_list == NULL)
		add_fill_list_error(&fill_list, map_info);
	ft_lstadd_front(&fill_list, first_list);
	while (fill_list != NULL)
	{
		mark_check_path(&fill_list, map_info);
	}
}

// void		map_check_path_sub1(t_map_info *map_info, int path_x, int path_y);

// void	map_check_path_sub1(t_map_info *map_info, int path_x, int path_y)
// {
// 	if (map_info == NULL)
// 		return ;
// 	if (path_x < 0 || path_y < 0 || path_x >= map_info->map_width
// 		|| path_y >= map_info->map_height)
// 		return ;
// 	if (map_check_path_data(map_info->map_data, path_x, path_y) == 1)
// 		return ;
// 	ft_printf("step : %dx%d\n", path_x, path_y);
// 	if (map_path_up(path_x, path_y, map_info) == 1)
// 		map_check_path_sub1(map_info, path_x, path_y - 1);
// 	if (map_path_down(path_x, path_y, map_info) == 1)
// 		map_check_path_sub1(map_info, path_x, path_y + 1);
// 	if (map_path_left(path_x, path_y, map_info) == 1)
// 		map_check_path_sub1(map_info, path_x - 1, path_y);
// 	if (map_path_right(path_x, path_y, map_info) == 1)
// 		map_check_path_sub1(map_info, path_x + 1, path_y);
// 	return ;
// }

// static int	map_path_right(int path_x, int path_y,
// 				t_map_info *map_info)
// {
// 	if ((map_info->map_data)[path_y][path_x + 1].type != WALL)
// 		return (1);
// 	else
// 		return (0);
// }

// static int	map_path_left(int path_x, int path_y,
// 				t_map_info *map_info)
// {
// 	if ((map_info->map_data)[path_y][path_x - 1].type != WALL)
// 		return (1);
// 	else
// 		return (0);
// }

// static int	map_path_up(int path_x, int path_y,
// 				t_map_info *map_info)
// {
// 	if ((map_info->map_data)[path_y - 1][path_x].type != WALL)
// 		return (1);
// 	else
// 		return (0);
// }

// static int	map_path_down(int path_x, int path_y,
// 				t_map_info *map_info)
// {
// 	if ((map_info->map_data)[path_y + 1][path_x].type != WALL)
// 		return (1);
// 	else
// 		return (0);
// }
