/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:30:14 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 16:56:18 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_mouse_hook(int x, int y, t_data *data)
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

static int	ft_loop_bonus(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	if (!ft_anim_hand(data))
		data->hand.time_frame++;
	ft_draw_minimap(data);
	ft_rotate(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[4].img, 0,
		0);
	return (0);
}

void	ft_events_bonus(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop_bonus, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask, ft_mouse_hook,
		data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
}
