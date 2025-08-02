/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 19:59:44 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	init_door(t_data *data)
{
	data->door.frame[DOOR].img = NULL;
	data->door.frame[DOOR].pixels = NULL;
	data->door.frame[DOOR].path = NULL;
	data->door.current_pos = 0;
	data->door.is_open = false;
}

static	void	init_hand(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->hand.frame[i].img = NULL;
		data->hand.frame[i].pixels = NULL;
		data->hand.frame[i].path = NULL;
		i++;
	}
	data->hand.time_frame = 0;
}

static	void	init_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		data->img[i].img = NULL;
		data->img[i].pixels = NULL;
		data->img[i].path = NULL;
		i++;
	}
	init_hand(data);
	init_door(data);
}

static	void	init_pars(t_data *data)
{
	data->pars->line = NULL;
	data->pars->x = 0;
	data->pars->y = 0;
	data->pars->player_x = 0;
	data->pars->player_y = 0;
	data->pars->fd_map = -1;
	data->pars->rgb = NULL;
	data->pars->map_check = NULL;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->window = NULL;
	init_img(data);
	data->texture = NULL;
	data->map = NULL;
	data->height = 0;
	data->width = 0;
	data->facing = 0;
	data->f_color = NULL;
	data->c_color = NULL;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	init_pars(data);
}
