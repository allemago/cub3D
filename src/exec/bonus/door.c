/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:06:01 by imatek            #+#    #+#             */
/*   Updated: 2025/04/27 12:21:37 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_anim_door(t_data *data)
{
	int frame;
	int flag;

	flag = 0;
	frame = data->door.time_frame / 10 % 4;
	if (data->player.espace && flag == 0)
	{
		if (frame == 0)
			ft_draw_anim(data, data->door.frame[DOOR1], 0, 0);
		else if (frame == 1)
			ft_draw_anim(data, data->door.frame[DOOR2], 0, 0);
		else if (frame == 2)
			ft_draw_anim(data, data->door.frame[DOOR3], 0, 0);
		else if (frame == 3)
		{
			ft_draw_anim(data, data->door.frame[DOOR4], 0, 0);
			flag = 1;
		}
	}
	else
		ft_draw_anim(data, data->door.frame[DOOR1], WIDTH / 3, (HEIGHT / 2 + 40));
	if (data->player.espace && data->map[data->ray.map_y][data->ray.map_x] == 'D' && flag == 1)
		return (1);
	return (0);
}

// void ft_open_door(t_data * data)
// {
//     if(data->map[(int)data->ray.map_y][(int)data->ray.map_x] == 'X' && ft_anim_hand(data))
//     {
//         ft_open_door(data);
//         data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'd';
//     }
//     else if (data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'd')
//         data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'D';
// }
