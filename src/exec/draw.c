/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Moon <Moon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/04/08 12:38:19 by Moon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	int	dest;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dest = (y * data->img->line_len) + (x * (data->img->bpp / 8));
	*(unsigned int *)(dest + data->img->pixels) = color;
}

int	convert_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			if (y < HEIGHT / 2)
				ft_put_pixel(data, x, y, convert_rgb(data->c_color[0], data->c_color[1], data->c_color[2]));
			else
				ft_put_pixel(data, x, y, convert_rgb(data->f_color[0], data->f_color[1], data->f_color[2]));
			y++;
		}
		x++;
	}
}
