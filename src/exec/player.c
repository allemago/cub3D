/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:47:02 by imatek            #+#    #+#             */
/*   Updated: 2025/04/28 19:30:49 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_change_face(t_data *data)
{
	if (data->player.dir_y < -0.7 && data->player.dir_x < 0.3
		&& data->player.dir_x > -0.3)
		data->facing = 'N';
	else if (data->player.dir_y > 0.7 && data->player.dir_x < 0.3
		&& data->player.dir_x > -0.3)
		data->facing = 'S';
	else if (data->player.dir_x < -0.7 && data->player.dir_y < 0.3
		&& data->player.dir_y > -0.3)
		data->facing = 'W';
	else if (data->player.dir_x > 0.7 && data->player.dir_y < -0.3
		&& data->player.dir_y < 0.3)
		data->facing = 'E';
}

static void	ft_set_face(t_data *data)
{
	if (data->facing == 'N')
	{
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
	}
	else if (data->facing == 'S')
	{
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
	}
	else if (data->facing == 'W')
	{
		data->player.dir_x = -1;
		data->player.plane_y = -0.66;
	}
	else if (data->facing == 'E')
	{
		data->player.dir_x = 1;
		data->player.plane_y = 0.66;
	}
}

void	ft_init_player(t_data *data)
{
	data->player.pos_y = (double)data->pars->player_y + 0.5;
	data->player.pos_x = (double)data->pars->player_x + 0.5;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0.0;
	data->player.plane_y = 0.0;
	data->player.up = false;
	data->player.down = false;
	data->player.right = false;
	data->player.left = false;
	data->player.rotate_left = false;
	data->player.rotate_right = false;
	data->player.espace = false;
	ft_set_face(data);
}
