/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:54:43 by imatek            #+#    #+#             */
/*   Updated: 2025/04/13 20:57:41 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_set_texture(t_data *data, int x)
{
	int	color;
	int	y;

	if (data->ray.wall_side == 0 && data->ray.dir_x > 0)
		data->texture = &data->img[NORTH];
	else if (data->ray.wall_side == 0 && data->ray.dir_x < 0)
		data->texture = &data->img[SOUTH];
	else if (data->ray.wall_side == 1 && data->ray.dir_y > 0)
		data->texture = &data->img[EAST];
	else if (data->ray.wall_side == 1 && data->ray.dir_y < 0)
		data->texture = &data->img[WEST];
	if (data->ray.wall_side == 0)
		data->ray.wall_x = data->player.pos_y + (data->ray.perpwalldist
				* data->ray.dir_y);
	else
		data->ray.wall_x = data->player.pos_x + (data->ray.perpwalldist
				* data->ray.dir_x);
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.tex_x = (int)(data->ray.wall_x * (double)TEXTURE_SIZE);
	if ((data->ray.wall_side == 0 && data->ray.dir_x > 0)
		|| (data->ray.wall_side == 1 && data->ray.dir_y < 0))
		data->ray.tex_x = TEXTURE_SIZE - data->ray.tex_x - 1;
	data->ray.step = (1.0 * TEXTURE_SIZE) / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - (HEIGHT / 2)
			+ (data->ray.line_height / 2)) * data->ray.step;
	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (TEXTURE_SIZE - 1);
		data->ray.tex_pos += data->ray.step;
		color = *((unsigned int *)(data->texture->pixels + data->ray.tex_y
					* data->texture->line_len + data->ray.tex_x
					* (data->texture->bpp / 8)));
		ft_put_pixel(data, x, y, color);
		y++;
	}
}
