/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:14 by imatek            #+#    #+#             */
/*   Updated: 2025/04/20 11:48:28 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_aux_x(t_point *start, t_point *end, t_bresenham *rayon)
{
	int	temp;

	if (start->x > end->x)
	{
		temp = start->x;
		start->x = end->x;
		end->x = temp;
		temp = start->y;
		start->y = end->y;
		end->y = temp;
	}
	rayon->pixel_inc_y = -1;
	if (end->y >= start->y)
		rayon->pixel_inc_y = 1;
	rayon->pixel_y = start->y;
	rayon->pixel_x = start->x;
}

static void	ft_aux_y(t_point *start, t_point *end, t_bresenham *rayon)
{
	int	temp;

	if (start->y > end->y)
	{
		temp = start->x;
		start->x = end->x;
		end->x = temp;
		temp = start->y;
		start->y = end->y;
		end->y = temp;
	}
	rayon->pixel_inc_x = -1;
	if (end->x >= start->x)
		rayon->pixel_inc_x = 1;
	rayon->pixel_x = start->x;
	rayon->pixel_y = start->y;
}

static void	ft_draw_line_x(t_data *data, t_point *end, t_bresenham *rayon)
{
	int	d;

	d = 2 * rayon->delta_y - rayon->delta_x;
	while (rayon->pixel_x < end->x)
	{
		if (rayon->pixel_x >= 0 && rayon->pixel_x < WIDTH && rayon->pixel_y >= 0
			&& rayon->pixel_y < HEIGHT)
			ft_put_pixel(data, rayon->pixel_x, rayon->pixel_y, COLOR_PLAYER);
		if (d > 0)
		{
			rayon->pixel_y += rayon->pixel_inc_y;
			d -= 2 * rayon->delta_x;
		}
		d += 2 * rayon->delta_y;
		rayon->pixel_x++;
	}
}

static void	ft_draw_line_y(t_data *data, t_point *end, t_bresenham *rayon)
{
	int	d;

	d = 2 * rayon->delta_x - rayon->delta_y;
	while (rayon->pixel_y <= end->y)
	{
		if (rayon->pixel_x >= 0 && rayon->pixel_x < WIDTH && rayon->pixel_y >= 0
			&& rayon->pixel_y < HEIGHT)
			ft_put_pixel(data, rayon->pixel_x, rayon->pixel_y, COLOR_PLAYER);
		if (d > 0)
		{
			rayon->pixel_x += rayon->pixel_inc_x;
			d -= 2 * rayon->delta_y;
		}
		d += 2 * rayon->delta_x;
		rayon->pixel_y++;
	}
}

void	ft_draw_line(t_data *data, t_point start, t_point end)
{
	t_bresenham	bresenham;

	bresenham.delta_x = fabs(end.x - start.x);
	bresenham.delta_y = fabs(end.y - start.y);
	if (bresenham.delta_x > bresenham.delta_y)
	{
		ft_aux_x(&start, &end, &bresenham);
		ft_draw_line_x(data, &end, &bresenham);
	}
	else
	{
		ft_aux_y(&start, &end, &bresenham);
		ft_draw_line_y(data, &end, &bresenham);
	}
}
