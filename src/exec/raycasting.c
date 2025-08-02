/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:35:47 by imatek            #+#    #+#             */
/*   Updated: 2025/04/24 11:21:28 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	ft_calculate_step_and_side(t_data *data)
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.pos_x - data->ray.map_x
				) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.pos_x
				) * data->ray.delta_dist_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.pos_y - data->ray.map_y
				) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.pos_y
				) * data->ray.delta_dist_y;
	}
}

static	void	ft_ray_set(t_data *data, int i)
{
	data->ray.camera_x = 2 * i / (double)WIDTH - 1;
	data->ray.dir_x = data->player.dir_x + data->player.plane_x
		* data->ray.camera_x;
	data->ray.dir_y = data->player.dir_y + data->player.plane_y
		* data->ray.camera_x;
	data->ray.map_x = (int)data->player.pos_x;
	data->ray.map_y = (int)data->player.pos_y;
	if (data->ray.dir_x == 0)
		data->ray.delta_dist_x = 1e30;
	else
		data->ray.delta_dist_x = fabs(1 / data->ray.dir_x);
	if (data->ray.dir_y == 0)
		data->ray.delta_dist_y = 1e30;
	else
		data->ray.delta_dist_y = fabs(1 / data->ray.dir_y);
	ft_calculate_step_and_side(data);
}

static	void	ft_dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.wall_side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.wall_side = 1;
		}
		if (is_c_inset(data->map[data->ray.map_y][data->ray.map_x], "1D"))
			hit = 1;
	}
}

static	void	ft_wall_dist(t_data *data)
{
	if (data->ray.wall_side == 0)
		data->ray.perpwalldist = data->ray.side_dist_x - data->ray.delta_dist_x;
	else
		data->ray.perpwalldist = data->ray.side_dist_y - data->ray.delta_dist_y;
	data->ray.line_height = (int)(HEIGHT / data->ray.perpwalldist);
	data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_end >= HEIGHT)
		data->ray.draw_end = HEIGHT - 1;
}

void	ft_raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ft_ray_set(data, i);
		ft_dda(data);
		ft_wall_dist(data);
		ft_calculate_texture(data, i);
		i++;
	}
}
