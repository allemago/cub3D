/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:01:21 by imatek            #+#    #+#             */
/*   Updated: 2025/04/16 13:34:40 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"


void	ft_init_img(t_data *data)
{
	int	i;

	i = 0;
	data->img[NORTH].path = data->north;
	data->img[SOUTH].path = data->south;
	data->img[EAST].path = data->east;
	data->img[WEST].path = data->west;
	data->img[DOOR].path = "./textures/XPM/DOOR.xpm";
	data->img[HAND].path = "./textures/XPM/HAND/HAND_1.xpm";
	data->img[HAND + 1].path = "./textures/XPM/HAND/HAND_2.xpm";
	data->img[HAND + 2].path = "./textures/XPM/HAND/HAND_3.xpm";
	data->img[HAND + 3].path = "./textures/XPM/HAND/HAND_4.xpm";

	while (i < 9)
	{
		data->img[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img[i].path, &data->img[i].width, &data->img[i].height);
		if (!data->img[i].img)
		{
			ft_putendl_fd("create img failed", 2);
			ft_destroy(data);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	data->img[9].img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	i = 0;
	while (i < 10)
	{
		data->img[i].pixels = mlx_get_data_addr(data->img[i].img,
				&data->img[i].bpp, &data->img[i].line_len,
				&data->img[i].endian);
		if (!data->img[i].pixels)
		{
			ft_putendl_fd("add img failed", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

