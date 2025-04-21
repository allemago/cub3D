/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/21 12:57:13 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	err_exit(char *str)
{
	ft_printf_fd(2, str);
	exit(EXIT_FAILURE);
}

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

static void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (data->img[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->img[i].img);
			data->img[i].img = NULL;
		}
		i++;
	}
	if (data->window)
	{
		mlx_destroy_window(data->mlx_ptr, data->window);
		data->window = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

void	free_all(t_data *data, int is_destroy)
{
	if (is_destroy == DESTROY)
		destroy_all(data);
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
