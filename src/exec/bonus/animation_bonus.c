/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:24:42 by imatek            #+#    #+#             */
/*   Updated: 2025/04/28 19:29:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_draw_anim(t_data *data, t_img img, int i, int j)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	while (x < img.width)
	{
		y = 0;
		while (y < img.height)
		{
			color = (*(unsigned int *)(img.pixels + (
							y * img.line_len + (x * (img.bpp / 8)))));
			if (color != 0xFF000000)
				ft_put_pixel(data, x + i, y + j, color);
			y++;
		}
		x++;
	}
}

static	void	ft_exec_anim(t_data *data, int frame, int *flag)
{
	if (frame == 0)
		ft_draw_anim(data, data->hand.frame[0], (WIDTH / 2), (HEIGHT / 2 + 40));
	else if (frame == 1)
		ft_draw_anim(data, data->hand.frame[1], (WIDTH / 2), (HEIGHT / 2 + 40));
	else if (frame == 2)
		ft_draw_anim(data, data->hand.frame[2], (WIDTH / 2), (HEIGHT / 2 + 40));
	else if (frame == 3)
	{
		ft_draw_anim(data, data->hand.frame[3], (WIDTH / 2), (HEIGHT / 2 + 40));
		if (data->map[data->ray.map_y][data->ray.map_x] == 'D')
		{
			data->door.is_open = true;
			ft_move_direction(data, data->player.dir_x,
				data->player.dir_y, 1);
		}
		*flag = 1;
	}
}

int	ft_anim_hand(t_data *data)
{
	int	frame;
	int	flag;

	frame = data->hand.time_frame / 14 % 4;
	flag = 0;
	if (data->player.espace && flag == 0)
		ft_exec_anim(data, frame, &flag);
	else
		ft_draw_anim(data, data->hand.frame[0], (WIDTH / 2), (HEIGHT / 2 + 40));
	if (data->player.espace && flag == 1)
		return (1);
	return (0);
}
