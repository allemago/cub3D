/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:47:02 by imatek            #+#    #+#             */
/*   Updated: 2025/04/22 15:02:22 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_face(t_data *data, double d_y, double p_x, double p_y)
{
	data->player.dir_y = d_y;
	data->player.plane_x = p_x;
	data->player.plane_y = p_y;
}

static void	ft_set_face(t_data *data)
{
	if (is_c_inset(data->facing, "NSEW"))
	{
		if (data->facing == 'N' && data->player.dir_x == 0)
			ft_face(data, -1, 0.66, 0);
		else if (data->facing == 'S' && data->player.dir_x == 0)
			ft_face(data, 1, -0.66, 0);
		else if (data->facing == 'W' && data->player.dir_x == -1)
			ft_face(data, 0, 0, 0.66);
		else if (data->facing == 'E' && data->player.dir_x == 1)
			ft_face(data, 0, 0, -0.66);
	}
}

static void	ft_set_player(t_data *data)
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
		while (j < ft_strlen(data->map[i]))
		{
			if (is_c_inset(data->map[i][j], "0D"))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_player(t_data *data)
{
	data->player.pos_x = data->pars->player_y;
	data->player.pos_y = data->pars->player_x;
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
	ft_set_face(data);
	ft_set_player(data);
}
