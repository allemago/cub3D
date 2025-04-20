/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:58:58 by imatek            #+#    #+#             */
/*   Updated: 2025/04/20 11:18:52 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	free_all(data, DESTROY);
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

int	ft_mouse_hook(int x, int y, t_data *data)
{
	(void)y;
	if (x < (WIDTH / 2))
	{
		ft_calculate_rotate(data, -ROTSPEED);
	}
	else if (x > (WIDTH / 2))
	{
		ft_calculate_rotate(data, ROTSPEED);
	}
	mlx_mouse_move(data->mlx_ptr, data->window, WIDTH / 2, HEIGHT / 2);
	return (0);
}
