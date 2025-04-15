/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:47:02 by imatek            #+#    #+#             */
/*   Updated: 2025/04/14 17:45:40 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_N_face(t_data *data)
{
	if (data->facing == 'N')
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
}

static void	ft_S_face(t_data *data)
{
	if (data->facing == 'S')
	{
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
}

static void	ft_W_face(t_data *data)
{
	if (data->facing == 'W')
	{
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
}
static void	ft_E_face(t_data *data)
{
	if (data->facing == 'E')
	{
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
}

void	ft_set_player(t_data *data)
{
	int		i;
	size_t	j;
	int		len;

	i = 0;
	len = 0;
	while (data->map[len])
		len++;
	while (i < len)
	{
		j = 0;
		while (j < ft_strlen(&data->map[i][j]))
		{
			if (data->map[i][j])
			{
				data->player.pos_x = (double)data->pars->player_x + 0.5;
				data->player.pos_y = (double)data->pars->player_y + 0.5;
				if (data->facing == 'N')
					ft_N_face(data);
				else if (data->facing == 'S')
					ft_S_face(data);
				else if (data->facing == 'W')
					ft_W_face(data);
				else if (data->facing == 'E')
					ft_E_face(data);
			}
			j++;
		}
		i++;
	}
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
}
