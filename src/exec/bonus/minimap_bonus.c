/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:21:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/23 13:24:43 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_blip(t_data *data, int x, int y, uint32_t color)
{
	int		i;
	int		j;
	int		pixel_x;
	int		pixel_y;
	t_radar	radar;

	radar = data->radar;
	i = 0;
	while (i < radar.tile)
	{
		j = 0;
		while (j < radar.tile)
		{
			pixel_y = MINI_MARGE_Y + (y * radar.tile + j);
			pixel_x = MINI_MARGE_X - (data->width * radar.tile);
			pixel_x += x * radar.tile + i;
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
	if (tile == '0' || tile == 'X' || tile == 'P')
		draw_blip(data, j, i, COLOR_FLOOR);
	if (tile == 'P')
		draw_blip(data, j, i, COLOR_PLAYER);
}

static void	calculate_radar(t_data *data)
{
	data->radar.tile_x = MINI_MAX / data->width;
	data->radar.tile_y = MINI_MAX / data->height;
	if (data->radar.tile_x < data->radar.tile_y)
		data->radar.tile = data->radar.tile_x;
	else
		data->radar.tile = data->radar.tile_y;
	if (data->radar.tile < 3)
		data->radar.tile = 3;
	if (data->radar.tile > 8)
		data->radar.tile = 8;
}

void	ft_draw_minimap(t_data *data)
{
	int	i;
	int	j;

	data->map[(int)data->player.pos_y][(int)data->player.pos_x] = 'P';
	calculate_radar(data);
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
	data->map[(int)data->player.pos_y][(int)data->player.pos_x] = '0';
}
