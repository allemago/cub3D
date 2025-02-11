/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 16:58:55 by magrabko         ###   ########.fr       */
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
	data->move_counter = 1;
	data->item_count = 0;
	data->item_found = 0;
	data->on_exit = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->size_x = 0;
	data->size_y = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->img_x = 0;
	data->img_y = 0;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->sprite = NULL;
	data->temp = NULL;
}
