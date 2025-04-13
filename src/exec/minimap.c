/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:21:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/14 01:01:12 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_blip(t_data *data, int x, int y, uint32_t color)
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
			pixel_x = MARGIN_X + (x * MINI_SCALE + i);
			pixel_y = MARGIN_Y - ((data->height - y - 1) * MINI_SCALE + j);
			ft_put_pixel(data, pixel_x, pixel_y, color);
			j++;
		}
		i++;
	}
}

static void	process_tile(t_data *data, char tile, int i, int j)
{
	if (tile == '1')
		draw_blip(data, j, i, COLOR_WALL);
	if (tile == 'D')
		draw_blip(data, j, i, COLOR_DOOR);
	if (tile == '0' || ((int)data->player.pos_x == j && (int)data->player.pos_y == i))
		draw_blip(data, j, i, COLOR_FLOOR);
	if ((int)data->player.pos_x == j && (int)data->player.pos_y == i)
		draw_blip(data, j, i, COLOR_PLAYER);
}

void	ft_draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			process_tile(data, data->map[i][j], i, j);
			j++;
		}
		i++;
	}
}
