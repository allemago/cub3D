/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:47:02 by imatek            #+#    #+#             */
/*   Updated: 2025/04/16 15:19:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			if (is_c_inset(data->map[i][j], "0D"))
			{
				data->player.pos_x = (double)data->pars->player_x + 0.5;
				data->player.pos_y = (double)data->pars->player_y + 0.5;
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
	ft_set_player(data);
	ft_set_face(data);
}
