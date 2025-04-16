/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:56:45 by imatek            #+#    #+#             */
/*   Updated: 2025/04/16 12:58:29 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
 
int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_destroy(data);
	if (keycode == KEY_W)
		data->player.up = true;
	else if (keycode == KEY_S)
		data->player.down = true;
	else if (keycode == KEY_D)
		data->player.right = true;
	else if (keycode == KEY_A)
		data->player.left = true;
	else if (keycode == KEY_LEFT)
		data->player.rotate_left = true;
	else if (keycode == KEY_RIGHT)
		data->player.rotate_right = true;
	return (0);
}

int	ft_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->player.up = false;
	else if (keycode == KEY_S)
		data->player.down = false;
	else if (keycode == KEY_D)
		data->player.right = false;
	else if (keycode == KEY_A)
		data->player.left = false;
	else if (keycode == KEY_LEFT)
		data->player.rotate_left = false;
	else if (keycode == KEY_RIGHT)
		data->player.rotate_right = false;
	return (0);
}


int	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (data->img[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->img[i].img);
			data->img[i].img = NULL;
		}
	}
	if (data->window)
	{
		mlx_destroy_window(data->mlx_ptr, data->window);
		data->window = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	free_all(data);
	exit(EXIT_SUCCESS);
}

void	ft_events(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
}
