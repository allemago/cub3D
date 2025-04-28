/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:48:45 by imatek            #+#    #+#             */
/*   Updated: 2025/04/28 19:31:17 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_direction(t_data *data, double x, double y, double sign)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + (sign * x) * SPEED;
	new_y = data->player.pos_y + (sign * y) * SPEED;
	if ((data->map[(int)(new_y)][(int)(data->player.pos_x)] == '0')
			|| (data->door.is_open
		&& data->map[(int)(new_y)][(int)(data->player.pos_x)] != '1'))
	{
		data->player.pos_y = new_y;
	}
	if ((data->map[(int)(data->player.pos_y)][(int)(new_x)] == '0')
			|| (data->door.is_open
		&& data->map[(int)(data->player.pos_y)][(int)(new_x)] != '1'))
	{
		data->player.pos_x = new_x;
	}
	data->door.current_pos = data->map[(int)(
			data->player.pos_y)][(int)(data->player.pos_x)];
}

void	ft_moves(t_data *data)
{	
	if (data->player.up)
		ft_move_direction(data, data->player.dir_x, data->player.dir_y, 1);
	else if (data->player.down)
		ft_move_direction(data, data->player.dir_x, data->player.dir_y, -1);
	else if (data->player.right)
		ft_move_direction(data, data->player.plane_x, data->player.plane_y, 1);
	else if (data->player.left)
		ft_move_direction(data, data->player.plane_x, data->player.plane_y, -1);
	if (data->door.current_pos == '0' || data->door.current_pos == '1')
	{
		data->door.is_open = false;
		data->door.current_pos = 0;
	}
}

void	ft_calculate_rotate(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(angle
			) - data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle
			) + data->player.dir_y * cos(angle);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(angle
			) - data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle
			) + data->player.plane_y * cos(angle);
	ft_change_face(data);
}

void	ft_rotate(t_data *data)
{
	if (data->player.rotate_right)
		ft_calculate_rotate(data, ROTSPEED);
	else if (data->player.rotate_left)
		ft_calculate_rotate(data, -ROTSPEED);
}
