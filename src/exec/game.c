/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Moon <Moon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/08 12:45:09 by Moon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Moon <Moon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:47 by imatek            #+#    #+#             */
/*   Updated: 2025/04/08 12:17:35 by Moon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_init_img(t_data *data)
{
	int	i;

	i = 0;
	data->img[0].path = data->north;
	data->img[1].path = data->south;
	data->img[2].path = data->east;
	data->img[3].path = data->west;
	while (i < 4)
	{
		data->img[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img[i].path, &data->img[i].width, &data->img[i].height);
		if (!data->img[i].img)
		{
			// ft_destroy(data);
			ft_putendl_fd("mlx_xpm_file failed", 2);
		}
		i++;
	}
	data->img[4].img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	i = 0;
	while (i < 5)
	{
		data->img[i].pixels = mlx_get_data_addr(data->img[i].img,
				&data->img[i].bpp, &data->img[i].line_len,
				&data->img[i].endian);
		i++;
	}
}

void	ft_init_game(t_data *data)
{
	ft_init_player(data);
	ft_init_ray(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_window failed", 2);
	}
	ft_init_img(data);
	ft_events_mlx(data);
}
