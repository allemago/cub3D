/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/22 12:53:13 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_game(t_data *data)
{
	ft_init_ray(data);
	ft_init_player(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_all(data, DESTROY);
		err_exit(MLX_INIT_MSG);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		free_all(data, DESTROY);
		err_exit(MLX_WIN_MSG);
	}
	ft_init_img(data);
	ft_events(data);
	mlx_loop(data->mlx_ptr);
}

void	ft_check_input(t_data *data, int argc, char *map_file)
{
	if (argc != 2 || !map_file[0] || is_str_inset(map_file, ALL_SPACES))
	{
		err_exit(ARGC_MSG);
	}
	if (!is_file_valid(data, map_file))
	{
		err_exit(ERR_EXT_MSG);
	}
	if (!check_elements(data))
	{
		err_free_exit(ERR_ELEM_MSG, data);
	}
	if (!check_map(data, data->height - 1))
	{
		err_free_exit(NULL, data);
	}
	if (!check_path(data))
	{
		err_free_exit(ERR_ITEM_MSG, data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_check_input(&data, argc, argv[1]);
	ft_game(&data);
	return (0);
}
