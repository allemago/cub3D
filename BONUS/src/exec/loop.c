/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:56:03 by imatek            #+#    #+#             */
/*   Updated: 2025/04/17 19:54:18 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_loop(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	ft_draw_hand(data, WIDTH / 3, (HEIGHT / 3 + 20));
	ft_draw_minimap(data);
	ft_rotate_lr(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[9].img, 0,
		0);
	return (0);
}
