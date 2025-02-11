/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 23:57:39 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_temp(t_data *data)
{
	data->temp->item = ft_calloc(2, sizeof(int));
	if (data->temp->item == NULL)
		err_free_exit(strerror(errno), data);
	data->temp->x = 0;
	data->temp->y = 0;
	data->temp->fd_map = -1;
	data->temp->map_check = NULL;
	data->temp->line = NULL;
}

void	init_data(t_data *data)
{
	data->player_x = 0;
	data->player_y = 0;
	data->width = 0;
	data->height = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->img_x = 0;
	data->img_y = 0;
	data->f_color = {0, 0, 0};
	data->facing = 0;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->temp = NULL;
	data->sprite = NULL;
}
