/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:01:21 by imatek            #+#    #+#             */
/*   Updated: 2025/04/16 18:00:40 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_path(t_data *data)
{
	data->img[NORTH].path = data->north;
	data->img[SOUTH].path = data->south;
	data->img[EAST].path = data->east;
	data->img[WEST].path = data->west;
	data->img[DOOR].path = "./textures/DOOR.xpm";
	data->img[HAND].path = "./textures/HAND/HAND_1.xpm";
	data->img[HAND + 1].path = "./textures/HAND/HAND_2.xpm";
	data->img[HAND + 2].path = "./textures/HAND/HAND_3.xpm";
	data->img[HAND + 3].path = "./textures/HAND/HAND_4.xpm";
}

void	ft_init_img(t_data *data)
{
	int	i;

	set_path(data);
	i = 0;
	while (i < 9)
	{
		data->img[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img[i].path, &data->img[i].width, &data->img[i].height);
		if (!data->img[i].img)
			return ((void)free_all(data, DESTROY), err_exit(XTI_FAIL_MSG));
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
			return ((void)free_all(data, DESTROY), err_exit(GDA_FAIL_MSG));
		i++;
	}
}
