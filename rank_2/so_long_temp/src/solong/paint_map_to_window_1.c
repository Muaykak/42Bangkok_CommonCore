/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map_to_window_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:26:24 by srussame          #+#    #+#             */
/*   Updated: 2025/04/08 10:26:37 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_map_to_window(t_so_long *so_long, int map_off_x, int map_off_y)
{
	int				map_x;
	int				map_y;
	t_map_data		**map_data;
	t_list			*object_list;
	t_map_object	*object;

	if (so_long == NULL)
		return ;
	map_data = so_long->map_info->map_data;
	map_y = 0;
	ft_printf("map_draw_xy: %dx%d\n", so_long->window->map_draw_x, so_long->window->map_draw_y);
	while (map_y < so_long->window->map_draw_y && map_y + map_off_y < so_long->map_info->map_height)
	{
		map_x = 0;
		while (map_x < so_long->window->map_draw_x && map_x + map_off_x < so_long->map_info->map_width)
		{
			object_list = map_data[map_y + map_off_y][map_x + map_off_x].object_list;
			while (object_list != NULL)
			{
				object = ((t_map_object *)(object_list->content));
				paint_img_to_img(so_long->window->img, object->object_img, map_x * so_long->grid_size, map_y * so_long->grid_size);
				object_list = object_list->next;
			}
			map_x++;
		}
		map_y++;
	}
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->window->win_ptr, so_long->window->img->img_ptr, 0, 0);
}
