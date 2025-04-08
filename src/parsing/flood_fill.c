/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:19 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/01 17:08:25 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	flood_fill(t_data *data, int i, int j)
{
	if (i <= 0 || i >= data->height - 1 || j <= 0 || j >= data->width - 1)
		return ;
	if (is_c_inset(data->pars->map_check[i][j], " .1"))
		return ;
	data->pars->map_check[i][j] = '.';
	flood_fill(data, i - 1, j);
	flood_fill(data, i + 1, j);
	flood_fill(data, i, j - 1);
	flood_fill(data, i, j + 1);
}

int	check_path(t_data *data)
{
	int	i;
	int	j;

	flood_fill(data, data->pars->player_y, data->pars->player_x);
	i = 0;
	while (data->pars->map_check[i])
	{
		j = 0;
		while (data->pars->map_check[i][j])
		{
			if (!is_c_inset(data->pars->map_check[i][j], " .1"))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
