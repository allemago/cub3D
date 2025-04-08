/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/07 14:51:45 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_assets(t_data *data)
{
	data->assets = ft_calloc(1, sizeof(t_assets));
	check_alloc(data->assets, data);
	data->assets->w_north = NULL;
	data->assets->w_south = NULL;
	data->assets->w_west = NULL;
	data->assets->w_east = NULL;
	data->assets->sky = NULL;
	data->assets->floor = NULL;
	data->assets->door = NULL;
	data->assets->donut = NULL;
	data->assets->effect = NULL;
	data->assets->hand = NULL;
}

void	init_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		data->img[i].img = NULL;
		data->img[i].path = NULL;
		i++;
	}
}

void	init_pars(t_data *data)
{
	data->pars->x = 0;
	data->pars->y = 0;
	data->pars->player_x = 0;
	data->pars->player_y = 0;
	data->pars->fd_map = -1;
	data->pars->rgb = NULL;
	data->pars->map_check = NULL;
	data->pars->line = NULL;
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->height = 0;
	data->width = 0;
	data->f_color = NULL;
	data->c_color = NULL;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->facing = 0;
	init_pars(data);
	init_img(data);
	init_assets(data);
}
