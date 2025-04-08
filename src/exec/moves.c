/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Moon <Moon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:48:45 by imatek            #+#    #+#             */
/*   Updated: 2025/04/08 12:41:22 by Moon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>


static void	ft_moves_ud(t_data *data)
{
	if (data->player.up)
	{
		if (data->map[(int)data->player.pos_x][(int)((data->player.pos_y
					+ data->player.dir_y) * SPEED)])
			data->player.pos_x += SPEED * data->player.dir_x;
		if (data->map[(int)((data->player.pos_x + data->player.dir_x)
				* SPEED)][(int)data->player.pos_y])
			data->player.pos_y += SPEED * data->player.dir_y;
	}
	if (data->player.down)
	{
		if (data->map[(int)data->player.pos_x][(int)((data->player.pos_y
					+ data->player.dir_y) * SPEED)])
			data->player.pos_x -= SPEED * data->player.dir_x;
		if (data->map[(int)((data->player.pos_x + data->player.dir_x)
				* SPEED)][(int)data->player.pos_y])
			data->player.pos_y -= SPEED * data->player.dir_y;
	}
}

static void	ft_moves_lr(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	if (data->player.right)
	{
		data->player.dir_x = (data->player.dir_x * cos(-ROTSPEED))
			- (data->player.dir_y * sin(-ROTSPEED));
		data->player.dir_y = (old_dir_x * sin(-ROTSPEED)) + (data->player.dir_y
				* cos(-ROTSPEED));
		data->player.plane_x = (data->player.plane_x * cos(-ROTSPEED))
			- (data->player.plane_y * sin(-ROTSPEED));
		data->player.plane_y = (old_plane_x * sin(-ROTSPEED))
			+ (data->player.plane_y * cos(-ROTSPEED));
	}
	if (data->player.left)
	{
		data->player.dir_x = (data->player.dir_x * cos(ROTSPEED))
			- (data->player.dir_y * sin(ROTSPEED));
		data->player.dir_y = (old_dir_x * sin(ROTSPEED)) + (data->player.dir_y
				* cos(ROTSPEED));
		data->player.plane_x = (data->player.plane_x * cos(ROTSPEED))
			- (data->player.plane_y * sin(ROTSPEED));
		data->player.plane_y = (old_plane_x * sin(ROTSPEED))
			+ (data->player.plane_y * cos(ROTSPEED));
	}
}

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

void	ft_moves(t_data *data)
{
	ft_moves_ud(data);
	ft_moves_lr(data);
}
