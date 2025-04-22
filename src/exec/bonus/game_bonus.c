/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:30:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/22 15:51:09 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_loop_bonus(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	ft_animation(data);
	// ft_draw_hand(data, WIDTH / 3, (HEIGHT / 2 + 40));
	ft_draw_minimap(data);
	ft_rotate(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[9].img, 0,
		0);
	return (0);
}

void	ft_events_bonus(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop_bonus, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_mouse_hook,
		data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
}

// void	ft_door_animation(t_data *data)
// {
// 	if (data->player.espace == false)
// 		data->player.door = false;
// 	if (data->player.espace == true && data->player.door == false)
// 	{
// 		if (data->map[data->ray.map_y][data->ray.map_x] == 'D')
// 			data->map[data->ray.map_y][data->ray.map_x] = 'O';
// 		else if (data->map[data->ray.map_y][data->ray.map_x] == 'O')
// 			data->map[data->ray.map_y][data->ray.map_x] = 'D';
// 		data->player.door = false;
// 	}
// }
