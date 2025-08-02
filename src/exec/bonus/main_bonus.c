/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:34:41 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 20:02:38 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_data *data, int is_destroy)
{
	if (is_destroy == DESTROY)
		destroy_all_bonus(data);
	if (data->f_color != NULL)
		free_ptr((void **)&data->f_color);
	if (data->c_color != NULL)
		free_ptr((void **)&data->c_color);
	if (data->north)
		free_ptr((void **)&data->north);
	if (data->south)
		free_ptr((void **)&data->south);
	if (data->east)
		free_ptr((void **)&data->east);
	if (data->west)
		free_ptr((void **)&data->west);
	if (data->map != NULL)
		free_tab(&data->map);
	if (data->pars != NULL)
	{
		free_ptr((void **)&data->pars->file);
		free_ptr((void **)&data->pars->line);
		free_tab(&data->pars->rgb);
		free_tab(&data->pars->map_check);
		free_ptr((void **)&data->pars);
	}
}

static	void	ft_game_bonus(t_data *data)
{
	ft_init_player(data);
	ft_init_ray(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_all(data, NO_DESTROY);
		err_exit(MLX_INIT_MSG);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		destroy_mlx(data);
		free_all(data, NO_DESTROY);
		err_exit(MLX_WIN_MSG);
	}
	ft_init_img_bonus(data);
	ft_events_bonus(data);
	mlx_loop(data->mlx_ptr);
}

static	void	ft_check_input(t_data *data, int argc, char *map_file)
{
	if (argc != 2 || !map_file[0] || is_str_inset(map_file, ALL_SPACES))
		err_exit(ARGC_MSG);
	if (!is_file_valid(data, map_file))
		err_exit(ERR_EXT_MSG);
	if (!check_elements(data))
		err_free_exit(ERR_ELEM_MSG, data);
	if (!check_map_bonus(data, data->height - 1))
		err_free_exit(NULL, data);
	if (!check_path(data))
		err_free_exit(ERR_ITEM_MSG, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_check_input(&data, argc, argv[1]);
	ft_game_bonus(&data);
	return (0);
}
