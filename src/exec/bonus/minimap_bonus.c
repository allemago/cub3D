/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:21:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/21 18:30:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	process_tile(t_data *data, char tile, int i, int j)
{
	if (tile == '1')
		draw_blip(data, j, i, COLOR_WALL);
	if (tile == 'D')
		draw_blip(data, j, i, COLOR_DOOR);
	if (tile == '0' || tile == 'P')
		draw_blip(data, j, i, COLOR_FLOOR);
	if (tile == 'P')
		draw_blip(data, j, i, COLOR_PLAYER);
}
/* 	if (tile == 'V' || tile == ' ')
		draw_blip(data, j, i, COLOR_VOID); */

static char	**init_radar_map(t_data *data, t_radar *radar)
{
	char	**radar_map;
	int		i;

	radar_map = malloc(sizeof(char *) * (radar->len_y + 1));
	if (!radar_map)
	{
		free_all(data, DESTROY);
		err_exit(RADAR_MEM_MSG);
	}
	radar_map[radar->len_y] = NULL;
	i = 0;
	while (i < radar->len_y)
	{
		radar_map[i] = ft_calloc(radar->len_x + 1, sizeof(char));
		if (!radar_map[i])
		{
			free_tab(&radar_map);
			free_all(data, DESTROY);
			err_exit(RADAR_MEM_MSG);
		}
		ft_memset(radar_map[i], 'V', radar->len_x);
		i++;
	}
	return (radar_map);
}

static char	**get_radar(t_data *data, t_radar *radar)
{
	char	**radar_map;
	int		i;
	int		max_x;

	radar_map = init_radar_map(data, radar);
	i = 0;
	while (i < radar->len_y && radar->y < data->height)
	{
		if (ft_strlen(&data->map[radar->y][radar->x]) > (size_t)radar->len_x)
			max_x = radar->len_x;
		else
			max_x = ft_strlen(&data->map[radar->y][radar->x]);
		ft_memcpy(radar_map[i], &data->map[radar->y][radar->x], max_x);
		i++;
		radar->y++;
	}
	return (radar_map);
}

static void	calculate_radar(t_data *data)
{
	if (data->width < 20)
		data->radar.len_x = data->width;
	else
		data->radar.len_x = 20;
	if (data->height < 20)
		data->radar.len_y = data->height;
	else
		data->radar.len_y = 20;
	if (((int)data->player.pos_x - ((data->radar.len_x) / 2)) >= 0)
		data->radar.x = (int)data->player.pos_x - ((data->radar.len_x) / 2);
	else
		data->radar.x = 0;
	if (((int)data->player.pos_y - ((data->radar.len_y) / 2)) >= 0)
		data->radar.y = (int)data->player.pos_y - ((data->radar.len_y) / 2);
	else
		data->radar.y = 0;
}

void	ft_draw_minimap(t_data *data)
{
	char	**radar_map;
	int		i;
	int		j;

	data->map[(int)data->player.pos_y][(int)data->player.pos_x] = 'P';
	calculate_radar(data);
	radar_map = get_radar(data, &data->radar);
	i = 0;
	while (radar_map[i])
	{
		j = 0;
		while (radar_map[i][j])
		{
			process_tile(data, radar_map[i][j], i, j);
			j++;
		}
		i++;
	}
	data->map[(int)data->player.pos_y][(int)data->player.pos_x] = '0';
}
