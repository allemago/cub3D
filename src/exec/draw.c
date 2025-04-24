/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/04/24 13:30:19 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (!data || !data->img->img || x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	pixel = data->img[4].pixels + (y * data->img[4].line_len + (x
				* (data->img[4].bpp / 8)));
	*(unsigned int *)pixel = color;
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
