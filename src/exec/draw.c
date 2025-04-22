/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/04/22 13:15:14 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (!data || !data->img->img || x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	pixel = data->img[9].pixels + (y * data->img[9].line_len + (x
				* (data->img[9].bpp / 8)));
	*(unsigned int *)pixel = color;
}

void	draw_blip(t_data *data, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	pixel_x;
	int	pixel_y;

	i = 0;
	while (i < MINI_SCALE)
	{
		j = 0;
		while (j < MINI_SCALE)
		{
			pixel_y = MINI_MARGE_Y + (y * MINI_SCALE + j);
			pixel_x = MINI_MARGE_X - (data->radar.len_x * MINI_SCALE);
			pixel_x += x * MINI_SCALE + i;
			ft_put_pixel(data, pixel_x, pixel_y, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_hand(t_data *data, int i, int j)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	while (x < data->img[7].width)
	{
		y = 0;
		while (y < data->img[7].height)
		{
			color = (*(unsigned int *)(data->img[7].pixels + (y
							* data->img[7].line_len + (x * (data->img[7].bpp
									/ 8)))));
			if (color != 0xFF000000)
				ft_put_pixel(data, x + i, y + j, color);
			y++;
		}
		x++;
	}
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
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y <= HEIGHT / 2)
				ft_put_pixel(data, x, y, convert_rgb(data->c_color[0],
						data->c_color[1], data->c_color[2]));
			else
				ft_put_pixel(data, x, y, convert_rgb(data->f_color[0],
						data->f_color[1], data->f_color[2]));
			y++;
		}
		x++;
	}
}
