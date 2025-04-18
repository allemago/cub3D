/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/18 20:11:42 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_ptr(void **ptr)
{
	if (ptr && *ptr)
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

void	destroy_texture(t_data *data, t_img *texture)
{
		free_ptr((void **)&texture->pixels);
		mlx_destroy_image(data->mlx_ptr, texture->img);
		texture->img = NULL;
}

void	free_all(t_data *data)
{
	if (data->f_color != NULL)
		free_ptr((void **)&data->f_color);
	if (data->c_color != NULL)
		free_ptr((void **)&data->c_color);
	if (data->north)
		free_ptr((void **)&data->north);
	if (data->south)
		free_ptr((void **)&data->south);
	if (data->east)
		free_ptr((void **)&data->east);
	if (data->west)
		free_ptr((void **)&data->west);
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
