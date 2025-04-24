/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:06:01 by imatek            #+#    #+#             */
/*   Updated: 2025/04/24 13:47:57 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int ft_anim_hand(t_data *data)
// {
// 	int frame;
// 	int flag = 0;

// 	frame = data->hand.time_frame / 14 % 4;
// 	if (data->player.espace && flag == 0)
// 	{
// 		if (frame == 0)
// 			ft_draw_anim(data, data->hand.frame[0], WIDTH / 3, (HEIGHT / 2 + 40));
// 		else if (frame == 1)
// 			ft_draw_anim(data, data->hand.frame[1], WIDTH / 3, (HEIGHT / 2 + 40));
// 		else if (frame == 2)
// 			ft_draw_anim(data, data->hand.frame[2], WIDTH / 3, (HEIGHT / 2 + 40));
// 		else if (frame == 3)
// 		{
// 			ft_draw_anim(data, data->hand.frame[2], WIDTH / 3, (HEIGHT / 2 + 40));
// 			flag = 1;
// 		}
// 	}
// 	else
// 		ft_draw_anim(data, data->hand.frame[0], WIDTH / 3, (HEIGHT / 2 + 40));
// 	if (data->player.espace && flag == 1)
// 		return (1);
// 	return (0);
// }

// void ft_anim_door(t_data * data)
// {
//     if(data->map[(int)data->ray.map_y][(int)data->ray.map_x] == 'X' && ft_anim_hand(data))
//     {
//         ft_open_door(data);
//         data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'd';
//     }
//     else if (data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'd')
//         data->map[(int)data->ray.map_y][(int)data->ray.map_x] = 'D';
// }
