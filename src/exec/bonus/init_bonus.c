/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:32 by imatek            #+#    #+#             */
/*   Updated: 2025/04/28 20:08:53 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_img_bonus(t_data *data)
{
	int	i;

	ft_set_path(data);
	i = 0;
	while (i < 4)
	{
		data->img[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img[i].path, &data->img[i].width, &data->img[i].height);
		if (!data->img[i].img)
		{
			free_all(data, DESTROY);
			err_exit(XTI_FAIL_MSG);
		}
		i++;
	}
	ft_init_hand(data);
	ft_init_door(data);
	data->img[4].img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	ft_add_img(data);
}

void	ft_init_door(t_data *data)
{
	data->door.frame[DOOR].path = "./textures/DOOR.xpm";
	data->door.frame[DOOR].img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->door.frame[DOOR].path, &data->door.frame[DOOR
		].width, &data->door.frame[DOOR].height);
	if (!data->door.frame[DOOR].img)
	{
		free_all(data, DESTROY);
		err_exit(XTI_FAIL_MSG);
	}
	data->door.frame[DOOR].pixels = mlx_get_data_addr(data->door.frame[DOOR
		].img, &data->door.frame[DOOR].bpp, &data->door.frame[DOOR].line_len,
			&data->door.frame[DOOR].endian);
	if (!data->door.frame[DOOR].pixels)
	{
		free_all(data, DESTROY);
		err_exit(GDA_FAIL_MSG);
	}
}
