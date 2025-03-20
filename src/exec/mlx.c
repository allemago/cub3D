/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:47 by imatek            #+#    #+#             */
/*   Updated: 2025/03/20 17:58:35 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	if (data->img)
	{
		destroy_texture(data, data->img, 0, 1);
		free_ptr((void **)&data->img);
	}
	if (data->assets)
		free_assets(data);
	if (data->window)
		mlx_destroy_window(data->mlx_ptr, data->window);
	mlx_loop_end(data->mlx_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	// ne pas liberer manuellement mlx_ptr, destroy_display s'en occupe
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
	else if (keycode == KEY_RIGHT)
		data->player.rotate_right = true;
	else if (keycode == KEY_LEFT)
		data->player.rotate_left = true;
	return (0);
}

int	ft_keyrelease(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->up = false;
	else if (keycode == KEY_S)
		player->down = false;
	else if (keycode == KEY_D)
		player->right = false;
	else if (keycode == KEY_A)
		player->left = false;
	else if (keycode == KEY_RIGHT)
		player->rotate_right = false;
	else if (keycode == KEY_LEFT)
		player->rotate_left = false;
	return (0);
}

void	ft_move(t_player *player)
{
	int	speed;

	speed = 2;
	if (player->up)
		player->pos_y -= speed;
	if (player->down)
		player->pos_y += speed;
	if (player->right)
		player->pos_x += speed;
	if (player->left)
		player->pos_x -= speed;
}

int	ft_loop(t_data *data)
{
	ft_move(&data->player);
	ft_clear_player(data);
	ft_draw_player(data->img, data->player.pos_x, data->player.pos_y, 8, RED_INT);
	ft_ray_direction(&data->player, &data->player.ray);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img->img, 0, 0);
	return (0);
}

void	ft_events_mlx(t_data *data)
{
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, &data->player);
	mlx_loop_hook(data->mlx_ptr, ft_loop, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease,
		&data->player);
	mlx_loop(data->mlx_ptr);
}

void	ft_init_mlx(t_data *data)
{
	ft_init_player(data);
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
	data->img->img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img->img)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_image failed", 2);
	}
	data->img->pixels = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img->img, 0, 0);
	ft_events_mlx(data);
}
