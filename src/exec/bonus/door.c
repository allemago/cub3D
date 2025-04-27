/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:06:01 by imatek            #+#    #+#             */
/*   Updated: 2025/04/27 17:34:05 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_anim_door(t_data *data)
{
	int	frame;
	int	flag;

	flag = 0;
	frame = data->door.time_frame / 14 % 4;
	if (data->player.espace && flag == 0)
	{
		if (frame == 0)
			ft_draw_anim(data, data->door.frame[DOOR1], 0, 0);
		else if (frame == 1)
			ft_draw_anim(data, data->door.frame[DOOR2], 0, 0);
		else if (frame == 2)
			ft_draw_anim(data, data->door.frame[DOOR3], 0, 0);
		else if (frame == 3)
			ft_draw_anim(data, data->door.frame[DOOR4], 0, 0);
		flag = 1;
	}
	else
		ft_draw_anim(data, data->door.frame[DOOR1
		], WIDTH / 2, (HEIGHT / 2 + 40));
	if (data->player.espace && data->map[data->ray.map_y
		][data->ray.map_x] == 'D' && flag == 1)
		return (1);
	return (0);
}
