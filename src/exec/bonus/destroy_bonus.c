/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 14:58:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	destroy_all_bonus(t_data *data)
{
	int	i;

	i = 0;
	if (data->door.frame[DOOR].img)
	{
		mlx_destroy_image(data->mlx_ptr, data->door.frame[DOOR].img);
		data->door.frame[DOOR].img = NULL;
	}
	while (i < 5)
	{
		if (data->img[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->img[i].img);
			data->img[i].img = NULL;
		}
		if (i < 4 && data->hand.frame[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->hand.frame[i].img);
			data->hand.frame[i].img = NULL;
		}
		i++;
	}
	destroy_mlx(data);
}
