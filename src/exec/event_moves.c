/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:48:45 by imatek            #+#    #+#             */
/*   Updated: 2025/04/14 01:00:38 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_destroy(data);
	if (keycode == KEY_W)
		data->player.up = true;
	else if (keycode == KEY_S)
		data->player.down = true;
	else if (keycode == KEY_D)
		data->player.right = true;
	else if (keycode == KEY_A)
		data->player.left = true;
	else if (keycode == KEY_LEFT)
		data->player.rotate_left = true;
	else if (keycode == KEY_RIGHT)
		data->player.rotate_right = true;
	return (0);
}

int	ft_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->player.up = false;
	else if (keycode == KEY_S)
		data->player.down = false;
	else if (keycode == KEY_D)
		data->player.right = false;
	else if (keycode == KEY_A)
		data->player.left = false;
	else if (keycode == KEY_LEFT)
		data->player.rotate_left = false;
	else if (keycode == KEY_RIGHT)
		data->player.rotate_right = false;
	return (0);
}

static void	ft_moves_ud(t_data *data)
{
	if (data->player.up)
	{
		if (data->map[(int)((data->player.pos_y + data->player.dir_y * SPEED)
				+ MARGIN)][(int)data->player.pos_x] == '0')
			data->player.pos_y += (data->player.dir_y * SPEED);
		if (data->map[(int)data->player.pos_y][(int)((data->player.pos_x
					+ data->player.dir_x * SPEED) + MARGIN)] == '0')
			data->player.pos_x += (data->player.dir_x * SPEED);
	}
	if (data->player.down)
	{
		if (data->map[(int)((data->player.pos_y - data->player.dir_y * SPEED)
				+ MARGIN)][(int)data->player.pos_x] == '0')
			data->player.pos_y -= (data->player.dir_y * SPEED);
		if (data->map[(int)data->player.pos_y][(int)((data->player.pos_x
					- data->player.dir_x * SPEED) + MARGIN)] == '0')
			data->player.pos_x -= (data->player.dir_x * SPEED);
	}
}

static void	ft_moves_lr(t_data *data)
{
	if (data->player.left)
	{
		if (data->map[(int)((data->player.pos_y + data->player.plane_y * SPEED)
				+ MARGIN)][(int)data->player.pos_x] == '0')
			data->player.pos_y += (data->player.plane_y * SPEED);
		if (data->map[(int)data->player.pos_y][(int)((data->player.pos_x
					+ data->player.plane_x * SPEED) + MARGIN)] == '0')
			data->player.pos_x += (data->player.plane_x * SPEED);
	}
	if (data->player.right)
	{
		if (data->map[(int)((data->player.pos_y - data->player.plane_y * SPEED)
				+ MARGIN)][(int)data->player.pos_x] == '0')
			data->player.pos_y -= (data->player.plane_y * SPEED);
		if (data->map[(int)data->player.pos_y][(int)((data->player.pos_x
					- data->player.plane_x * SPEED) + MARGIN)] == '0')
			data->player.pos_x -= (data->player.plane_x * SPEED);
	}
}

static void	ft_rotate_lr(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (data->player.rotate_left)
	{
		old_dir_x = data->player.dir_x;
		data->player.dir_x = (data->player.dir_x * cos(ROTSPEED))
			- (data->player.dir_y * sin(ROTSPEED));
		data->player.dir_y = (old_dir_x * sin(ROTSPEED)) + (data->player.dir_y
				* cos(ROTSPEED));
		old_plane_x = data->player.plane_x;
		data->player.plane_x = (data->player.plane_x * cos(ROTSPEED))
			- (data->player.plane_y * sin(ROTSPEED));
		data->player.plane_y = (old_plane_x * sin(ROTSPEED))
			+ (data->player.plane_y * cos(ROTSPEED));
	}
	if (data->player.rotate_right)
	{
		old_dir_x = data->player.dir_x;
		data->player.dir_x = (data->player.dir_x * cos(-ROTSPEED))
			- (data->player.dir_y * sin(-ROTSPEED));
		data->player.dir_y = (old_dir_x * sin(-ROTSPEED)) + (data->player.dir_y
				* cos(-ROTSPEED));
		old_plane_x = data->player.plane_x;
		data->player.plane_x = (data->player.plane_x * cos(-ROTSPEED))
			- (data->player.plane_y * sin(-ROTSPEED));
		data->player.plane_y = (old_plane_x * sin(-ROTSPEED))
			+ (data->player.plane_y * cos(-ROTSPEED));
	}
}

void	ft_moves(t_data *data)
{
	if (data->player.up || data->player.down)
		ft_moves_ud(data);
	else if (data->player.left || data->player.right)
		ft_moves_lr(data);
	else if (data->player.rotate_left || data->player.rotate_right)
		ft_rotate_lr(data);
}
