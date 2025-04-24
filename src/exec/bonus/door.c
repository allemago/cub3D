/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:06:01 by imatek            #+#    #+#             */
/*   Updated: 2025/04/24 11:28:09 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_open_door(t_data *data)
{
	int frame;

	frame = data->time_frame / 14 % 4;
    if (frame == 0)
        ft_draw_anim(data, data->img[5], WIDTH / 3, (HEIGHT / 2 + 40));
    else if (frame == 1)
        ft_draw_anim(data, data->img[6], WIDTH / 3, (HEIGHT / 2 + 40));
    else if (frame == 2)
        ft_draw_anim(data, data->img[7], WIDTH / 3, (HEIGHT / 2 + 40));
    else if (frame == 3)
        ft_draw_anim(data, data->img[8], WIDTH / 3, (HEIGHT / 2 + 40));
}  

void ft_anim_door(t_data * data)
{
    if(data->map[(int)data->ray.map_y][(int)data->ray.map_x] == 'X' && ft_anim_hand(data))
    {
        ft_open_door(data);
        data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'd';
    }
    else if (data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'd')
        data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'D';
}
