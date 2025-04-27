/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:32 by imatek            #+#    #+#             */
/*   Updated: 2025/04/27 20:11:57 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_add_img(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		data->img[i].pixels = mlx_get_data_addr(data->img[i].img,
				&data->img[i].bpp, &data->img[i].line_len,
				&data->img[i].endian);
		if (!data->img[i].pixels)
		{
			free_all(data, DESTROY);
			err_exit(GDA_FAIL_MSG);
		}
		i++;
	}
}

void	ft_set_path(t_data *data)
{
	data->img[NORTH].path = data->north;
	data->img[SOUTH].path = data->south;
	data->img[EAST].path = data->east;
	data->img[WEST].path = data->west;
}

void	ft_init_img(t_data *data)
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
	data->img[4].img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	ft_add_img(data);
}

void	ft_init_ray(t_data *data)
{
	data->ray.step_x = 0;
	data->ray.step_y = 0;
	data->ray.side_dist_x = 0;
	data->ray.side_dist_y = 0;
	data->ray.camera_x = 0;
	data->ray.dir_x = 0;
	data->ray.dir_y = 0;
	data->ray.delta_dist_x = 0;
	data->ray.delta_dist_y = 0;
	data->ray.map_x = 0;
	data->ray.map_y = 0;
	data->ray.wall_side = 0;
	data->ray.perpwalldist = 0;
	data->ray.line_height = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->ray.tex_x = 0;
	data->ray.step = 0;
	data->ray.tex_pos = 0;
	data->ray.wall_x = 0;
}
