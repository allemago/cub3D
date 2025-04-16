/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:17:45 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/16 17:44:08 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_n_face(t_data *data)
{
	if (data->facing == 'N')
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
}

static void	ft_s_face(t_data *data)
{
	if (data->facing == 'S')
	{
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
}

static void	ft_w_face(t_data *data)
{
	if (data->facing == 'W')
	{
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
}

static void	ft_e_face(t_data *data)
{
	if (data->facing == 'E')
	{
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
}

void	ft_set_face(t_data *data)
{
	if (is_c_inset(data->facing, "NSEW"))
	{
		if (data->facing == 'N')
			ft_n_face(data);
		else if (data->facing == 'S')
			ft_s_face(data);
		else if (data->facing == 'W')
			ft_w_face(data);
		else if (data->facing == 'E')
			ft_e_face(data);
	}
}
