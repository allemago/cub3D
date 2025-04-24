/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:24:42 by imatek            #+#    #+#             */
/*   Updated: 2025/04/24 13:44:30 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_draw_anim(t_data *data, t_img img, int i, int j)
{
	int x;
	int y;
	unsigned int color;

	x = 0;
	while (x < img.width)
	{
		y = 0;
		while (y < img.height)
		{
			color = (*(unsigned int *)(img.pixels + (y * img.line_len + (x * (img.bpp / 8)))));
			if (color != 0xFF000000)
				ft_put_pixel(data, x + i, y + j, color);
			y++;
		}
		x++;
	}
}

int ft_anim_hand(t_data *data)
{
	int frame;
	int flag = 0;

	frame = data->hand.time_frame / 14 % 4;
	if (data->player.espace && flag == 0)
	{
		if (frame == 0)
			ft_draw_anim(data, data->hand.frame[0], WIDTH / 3, (HEIGHT / 2 + 40));
		else if (frame == 1)
			ft_draw_anim(data, data->hand.frame[1], WIDTH / 3, (HEIGHT / 2 + 40));
		else if (frame == 2)
			ft_draw_anim(data, data->hand.frame[2], WIDTH / 3, (HEIGHT / 2 + 40));
		else if (frame == 3)
		{
			ft_draw_anim(data, data->hand.frame[2], WIDTH / 3, (HEIGHT / 2 + 40));
			flag = 1;
		}
	}
	else
		ft_draw_anim(data, data->hand.frame[0], WIDTH / 3, (HEIGHT / 2 + 40));
	if (data->player.espace && flag == 1)
		return (1);
	return (0);
}    
