/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:54:43 by imatek            #+#    #+#             */
/*   Updated: 2025/04/28 18:02:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_texture(t_data *data, int x)
{
	unsigned int	color;
	int				y;

	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (TEXTURE_SIZE - 1);
		data->ray.tex_pos += data->ray.step;
		color = *((unsigned int *)(data->texture->pixels + data->ray.tex_y
					* data->texture->line_len + data->ray.tex_x
					* (data->texture->bpp / 8)));
		if (data->ray.wall_side == 1
			&& data->texture != &data->door.frame[DOOR])
			color = (color >> 1) & 8355711;
		if (color != 0xFF000000)
			ft_put_pixel(data, x, y, color);
		y++;
	}
}

static void	set_wall(t_data *data)
{
	if (data->ray.wall_side == 0 && data->ray.dir_x > 0)
		data->texture = &data->img[EAST];
	else if (data->ray.wall_side == 0 && data->ray.dir_x < 0)
		data->texture = &data->img[WEST];
	else if (data->ray.wall_side == 1 && data->ray.dir_y > 0)
		data->texture = &data->img[SOUTH];
	else if (data->ray.wall_side == 1 && data->ray.dir_y < 0)
		data->texture = &data->img[NORTH];
	if (data->ray.wall_side == 0)
		data->ray.wall_x = data->player.pos_y + (data->ray.perpwalldist
				* data->ray.dir_y);
	else
		data->ray.wall_x = data->player.pos_x + (data->ray.perpwalldist
				* data->ray.dir_x);
}

void	ft_calculate_texture(t_data *data, int x)
{
	set_wall(data);
	if (data->map[(int)data->ray.map_y][(int)data->ray.map_x] == 'D')
		data->texture = &data->door.frame[DOOR];
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.tex_x = (int)(data->ray.wall_x * (double)TEXTURE_SIZE);
	if ((data->ray.wall_side == 0 && data->ray.dir_x > 0)
		|| (data->ray.wall_side == 1 && data->ray.dir_y < 0))
		data->ray.tex_x = TEXTURE_SIZE - data->ray.tex_x - 1;
	data->ray.step = (1.0 * TEXTURE_SIZE) / data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - (HEIGHT / 2)
			+ (data->ray.line_height / 2)) * data->ray.step;
	draw_texture(data, x);
}
