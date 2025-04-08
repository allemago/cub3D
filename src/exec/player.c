/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Moon <Moon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:47:02 by imatek            #+#    #+#             */
/*   Updated: 2025/04/08 11:38:54 by Moon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void ft_N_face(t_data *data)
{
    if (data->facing == 'N')
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
}

static void ft_S_face(t_data *data)
{
    if (data->facing == 'S')
	{
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
}

static void ft_W_face(t_data *data)
{
    if (data->facing == 'W')
	{
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
}
static void ft_E_face(t_data *data)
{
    if (data->facing == 'E')
	{
		data->player.plane_x = 0;
		data->player.plane_y = - 0.66;
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
}

void ft_set_player(t_data *data)
{
	data->player.pos_x = data->pars->player_x;
	data->player.pos_y = data->pars->player_y;
	ft_N_face(data);
	ft_S_face(data);
	ft_W_face(data);
	ft_E_face(data);
}

void	ft_init_player(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
	data->player.up = false;
	data->player.down = false;
	data->player.right = false;
	data->player.left = false;
	data->player.rotate_left = false;
	data->player.rotate_right = false;
	ft_set_player(data);
}
