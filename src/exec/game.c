/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/13 20:45:50 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	ft_init_img(data);
	ft_events_mlx(data);
}
