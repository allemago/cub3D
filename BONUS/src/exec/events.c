/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:58:58 by imatek            #+#    #+#             */
/*   Updated: 2025/04/18 20:36:26 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
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
	else if (keycode == KEY_ESPACE)
		data->player.espace = true;
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
	else if (keycode == KEY_ESPACE)
		data->player.espace = false;
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
