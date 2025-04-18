/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/18 20:52:38 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_loop(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	ft_rotate_lr(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[4].img, 0,
		0);
	return (0);
}

void	ft_events(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
}

void	ft_game(t_data *data)
{
	ft_init_player(data);
	ft_init_ray(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putendl_fd("mlx_init failed", 2);
		ft_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		ft_putendl_fd("mlx_new_window failed", 2);
		ft_destroy(data);
		exit(EXIT_FAILURE);
	}
	ft_create_img(data);
}
