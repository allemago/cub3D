/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:03:28 by imatek            #+#    #+#             */
/*   Updated: 2025/04/27 18:04:52 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	ft_add_door(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->door.frame[i].pixels = mlx_get_data_addr(data->door.frame[i].img,
				&data->door.frame[i].bpp, &data->door.frame[i].line_len,
				&data->door.frame[i].endian);
		if (!data->door.frame[i].pixels)
		{
			free_all(data, DESTROY);
			err_exit(GDA_FAIL_MSG);
		}
		i++;
	}
}

static	void	ft_set_door(t_data *data)
{
	data->door.frame[DOOR1].path = "./textures/DOOR/DOOR_1.xpm";
	data->door.frame[DOOR2].path = "./textures/DOOR/DOOR_2.xpm";
	data->door.frame[DOOR3].path = "./textures/DOOR/DOOR_3.xpm";
	data->door.frame[DOOR4].path = "./textures/DOOR/DOOR_4.xpm";
}

void	ft_init_door(t_data *data)
{
	int	i;

	ft_set_door(data);
	i = 0;
	while (i < 4)
	{
		data->door.frame[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->door.frame[i].path, &data->door.frame[i
			].width, &data->door.frame[i].height);
		if (!data->door.frame[i].img)
		{
			free_all(data, DESTROY);
			err_exit(XTI_FAIL_MSG);
		}
		i++;
	}
	ft_add_door(data);
}
