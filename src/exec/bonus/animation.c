/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:24:42 by imatek            #+#    #+#             */
/*   Updated: 2025/04/22 15:55:00 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_draw_hand(t_data *data, t_img *img, int i, int j)
{
	int x;
	int y;
	unsigned int color;

	x = 0;
	while (x < img[i].width)
	{
		y = 0;
		while (y < img[i].height)
		{
			color = (*(unsigned int *)(img[i].pixels + (y * img[i].line_len + (x * (img[i].bpp / 8)))));
			if (color != 0xFF000000)
				ft_put_pixel(data, x + i, y + j, color);
			y++;
		}
		x++;
	}
}

void ft_animation(t_data *data)
{
	if (data->player.espace == true)
	{
		while (data->player.time_frame)
		{
			ft_draw_hand(data, data->img[5].img, WIDTH / 3, (HEIGHT / 2 + 40));
			data->player.time_frame--;
		}
		while (data->player.time_frame == 15)
		{
			ft_draw_hand(data, data->img[6].img, WIDTH / 3, (HEIGHT / 2 + 40));
			data->player.time_frame--;
		}
		while (data->player.time_frame == 10)
		{
			ft_draw_hand(data, data->img[7].img, WIDTH / 3, (HEIGHT / 2 + 40));
			data->player.time_frame--;
		}
		while (data->player.time_frame == 5)
		{
			ft_draw_hand(data, data->img[8].img, WIDTH / 3, (HEIGHT / 2 + 40));
			data->player.time_frame--;
		}
	}
	else
		ft_draw_hand(data, data->img[7].img, WIDTH / 3, (HEIGHT / 2 + 40));
}
