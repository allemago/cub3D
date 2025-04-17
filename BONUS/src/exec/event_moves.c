/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:48:45 by imatek            #+#    #+#             */
/*   Updated: 2025/04/17 18:25:30 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_moves_ud(t_data *data)
{
	if (data->player.up)
	{
		if (is_c_inset(data->map[(int)(data->player.pos_y + data->player.dir_y
				* (SPEED + MARGIN))][(int)data->player.pos_x], "0D"))
			data->player.pos_y += data->player.dir_y * SPEED;
		if (is_c_inset(data->map[(int)data->player.pos_y][(int)(data->player.pos_x
				+ data->player.dir_x * (SPEED + MARGIN))], "0D"))
			data->player.pos_x += data->player.dir_x * SPEED;
	}
	else if (data->player.down)
	{
		if (is_c_inset(data->map[(int)(data->player.pos_y - data->player.dir_y
				* (SPEED + MARGIN))][(int)data->player.pos_x], "0D"))
			data->player.pos_y -= data->player.dir_y * SPEED;
		if (is_c_inset(data->map[(int)data->player.pos_y][(int)(data->player.pos_x
				- data->player.dir_x * (SPEED + MARGIN))], "0D"))
			data->player.pos_x -= data->player.dir_x * SPEED;
	}
}

static void	ft_moves_lr(t_data *data)
{
	if (data->player.right)
	{
		if (is_c_inset(data->map[(int)(data->player.pos_y + data->player.plane_y * (SPEED + MARGIN))][(int)data->player.pos_x], "0D"))
			data->player.pos_y += data->player.plane_y * SPEED;
		if (is_c_inset(data->map[(int)data->player.pos_y][(int)(data->player.pos_x + data->player.plane_x * (SPEED + MARGIN))], "0D"))
			data->player.pos_x += data->player.plane_x * SPEED;
	}
	else if (data->player.left)
	{
		if (is_c_inset(data->map[(int)(data->player.pos_y - data->player.plane_y * (SPEED + MARGIN))][(int)data->player.pos_x], "0D"))
			data->player.pos_y -= data->player.plane_y * SPEED;
		if (is_c_inset(data->map[(int)data->player.pos_y][(int)(data->player.pos_x - data->player.plane_x * (SPEED + MARGIN))], "0D"))
			data->player.pos_x -= data->player.plane_x * SPEED;
	}
}

void	ft_rotate(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(angle) - data->player.dir_y
		* sin(angle);
	data->player.dir_y = old_dir_x * sin(angle) + data->player.dir_y
		* cos(angle);
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle) + data->player.plane_y
		* cos(angle);
}
void	ft_rotate_lr(t_data *data)
{
	if (data->player.rotate_right)
		ft_rotate(data, ROTSPEED );
	if (data->player.rotate_left)
		ft_rotate(data, -ROTSPEED);
}

void	ft_moves(t_data *data)
{
	ft_moves_ud(data);
	ft_moves_lr(data);
	// if (data->player.espace)
	// 	ft_animation(data, 0, 0);
}
