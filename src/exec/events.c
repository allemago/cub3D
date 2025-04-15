/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:58:58 by imatek            #+#    #+#             */
/*   Updated: 2025/04/15 17:55:00 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	// Assurez-vous que ce nombre correspond au nombre d'images que vous avez
	{
		if (data->img[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->img[i].img);
			data->img[i].img = NULL; // Important pour eviter les double free
		}
		i++;
	}
	// if (data->assets) // Libérer les autres ressources
	// 	free_assets(data);
	if (data->window)
	{
		mlx_destroy_window(data->mlx_ptr, data->window);
		data->window = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr); // Libérer la structure MLX elle-même
		data->mlx_ptr = NULL;
	}
	free_all(data);
	exit(EXIT_SUCCESS);
}

int	ft_loop(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	ft_draw_minimap(data);
	ft_rotate_lr(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[4].img, 0,
		0);
	return (0);
}

int	ft_mouse_hook(int x, int y, t_data *data)
{
	(void)y;
	if (x < (WIDTH / 2))
	{
		ft_rotate(data, -ROTSPEED);
	}
	else if (x > (WIDTH / 2))
	{
		ft_rotate(data, ROTSPEED);
	}
	mlx_mouse_move(data->mlx_ptr, data->window, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	ft_events_mlx(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_mouse_hook,
		data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
}
