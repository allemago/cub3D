/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:35:47 by imatek            #+#    #+#             */
/*   Updated: 2025/03/18 11:26:27 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_ray_direction(t_player *player, t_ray *ray)
{
	int		i;
	double	camera_x;

	i = 0;
	while (i < WIDTH)
	{
		camera_x = 2 * i / (double)WIDTH - 1;
		ray->dir_x = player->dir_x + player->plane_x * camera_x;
		ray->dir_y = player->dir_y + player->plane_y * camera_x;
		ray->delta_dist_x = fabs(1 / ray->dir_x);
		ray->delta_dist_y = fabs(1 / ray->dir_y);
		ray->map_x = player->pos_x;
		ray->map_y = player->pos_y;
		i++;
	}
}
