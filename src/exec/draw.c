/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/03/20 17:23:23 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel(t_text *img, int x, int y, int color)
{
	int	dest;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dest = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(dest + img->pixels) = color;
}

void	ft_draw_player(t_text *img, int x, int y, int size, int color)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		ft_put_pixel(img, x + i, y, color);
		ft_put_pixel(img, x, y + i, color);
		ft_put_pixel(img, x + size, y + i, color);
		ft_put_pixel(img, x + i, y + size, color);
		i++;
	}
}

void	ft_clear_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_put_pixel(data->img, j, i, 0);
			j++;
		}
		i++;
	}
}
