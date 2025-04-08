/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 14:19:50 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_ptr(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_tab(char ***tab)
{
	size_t	i;

	if (tab == NULL || *tab == NULL)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free_ptr((void **)&(*tab)[i]);
		i++;
	}
	free_ptr((void **)tab);
}

void	destroy_texture(t_data *data, t_text *texture, int i, int n)
{
	if (n == 1)
	{
		free_ptr((void **)&texture->pixels);
		mlx_destroy_image(data->mlx_ptr, texture->img);
		texture->img = NULL;
	}
	else if (n == 4)
	{
		while (i < n)
		{
			free_ptr((void **)&data->assets->hand->frames[i].pixels);
			mlx_destroy_image(data->mlx_ptr, data->assets->hand->frames[i].img);
			data->assets->hand->frames[i++].img = NULL;
		}
	}
	else if (n == 11)
	{
		while (i < n)
		{
			free_ptr((void **)&data->assets->effect->frames[i].pixels);
			mlx_destroy_image(data->mlx_ptr,
				data->assets->effect->frames[i].img);
			data->assets->effect->frames[i++].img = NULL;
		}
	}
}

void	free_assets(t_data *data)
{
	destroy_texture(data, data->assets->w_north, 0, 1);
	destroy_texture(data, data->assets->w_south, 0, 1);
	destroy_texture(data, data->assets->w_west, 0, 1);
	destroy_texture(data, data->assets->w_east, 0, 1);
	destroy_texture(data, data->assets->sky, 0, 1);
	destroy_texture(data, data->assets->floor, 0, 1);
	destroy_texture(data, data->assets->door, 0, 1);
	destroy_texture(data, data->assets->donut, 0, 1);
	destroy_texture(data, NULL, 0, 4);
	destroy_texture(data, NULL, 0, 11);
	free_ptr((void **)&data->assets);
}

void	free_all(t_data *data)
{
	if (data->f_color != NULL)
		free_ptr((void **)&data->f_color);
	if (data->c_color != NULL)
		free_ptr((void **)&data->c_color);
	if (data->map != NULL)
		free_tab(&data->map);
	if (data->pars != NULL)
	{
		free_ptr((void **)&data->pars->file);
		free_ptr((void **)&data->pars->line);
		free_tab(&data->pars->rgb);
		free_tab(&data->pars->map_check);
		free_ptr((void **)&data->pars);
	}
}
