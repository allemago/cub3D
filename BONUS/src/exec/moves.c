/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:48:45 by imatek            #+#    #+#             */
/*   Updated: 2025/04/18 18:15:22 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_moves_up(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->player.up == true)
	{
		new_x = data->player.pos_x + data->player.dir_x * SPEED;
		new_y = data->player.pos_y + data->player.dir_y * SPEED;
		if (is_c_inset(data->map[(int)(new_y)][(int)(data->player.pos_x)],
				"0D"))
			data->player.pos_y = new_y;
		if (is_c_inset(data->map[(int)(data->player.pos_y)][(int)(new_x)],
				"0D"))
			data->player.pos_x = new_x;
	}
}

static void	ft_moves_down(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->player.down == true)
	{
		new_x = data->player.pos_x - data->player.dir_x * SPEED;
		new_y = data->player.pos_y - data->player.dir_y * SPEED;
		if (is_c_inset(data->map[(int)(new_y)][(int)(data->player.pos_x)],
				"0D"))
			data->player.pos_y = new_y;
		if (is_c_inset(data->map[(int)(data->player.pos_y)][(int)(new_x)],
				"0D"))
			data->player.pos_x = new_x;
	}
}

static void	ft_moves_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.plane_x * SPEED;
	new_y = data->player.pos_y - data->player.plane_y * SPEED;
	if (data->player.left == true)
	{
		if (is_c_inset(data->map[(int)(new_y)][(int)(data->player.pos_x)],
				"0D"))
			data->player.pos_y = new_y;
		if (is_c_inset(data->map[(int)(data->player.pos_y)][(int)(new_x)],
				"0D"))
			data->player.pos_x = new_x;
	}
}
static void	ft_moves_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.plane_x * SPEED;
	new_y = data->player.pos_y + data->player.plane_y * SPEED;
	if (data->player.right == true)
	{
		if (is_c_inset(data->map[(int)(new_y)][(int)(data->player.pos_x)],
				"0D"))
			data->player.pos_y = new_y;
		if (is_c_inset(data->map[(int)(data->player.pos_y)][(int)(new_x)],
				"0D"))
			data->player.pos_x = new_x;
	}
}

void	ft_rotate(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(angle) - data->player.dir_y
		* sin(angle);
	data->player.dir_y = old_dir_x * sin(angle) + data->player.dir_y
		* cos(angle);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle) + data->player.plane_y
		* cos(angle);
}
void	ft_rotate_lr(t_data *data)
{
	if (data->player.rotate_right)
		ft_rotate(data, ROTSPEED);
	if (data->player.rotate_left)
		ft_rotate(data, -ROTSPEED);
}

void	ft_moves(t_data *data)
{
	if (data->player.up == true)
		ft_moves_up(data);
	else if (data->player.down == true)
		ft_moves_down(data);
	else if (data->player.left == true)
		ft_moves_left(data);
	else if (data->player.right == true)
		ft_moves_right(data);
	// if (data->player.espace)
	// 	ft_animation(data, data->img);
}

void	ft_door_animation(t_data *data)
{
	if (data->player.espace == false)
		data->player.door = false;
	if (data->player.espace == true && data->player.door == false)
	{
		if (data->map[data->ray.map_y][data->ray.map_x] == 'D')
			data->map[data->ray.map_y][data->ray.map_x] = 'O';
		else if (data->map[data->ray.map_y][data->ray.map_x] == 'O')
			data->map[data->ray.map_y][data->ray.map_x] = 'D';
		data->player.door = false;
	}
}
