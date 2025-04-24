/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/24 13:25:52 by imatek           ###   ########.fr       */
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

void destroy_mlx(t_data *data)
{
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

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->img[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->img[i].img);
			data->img[i].img = NULL;
		}
		if (i < 4 && data->door.frame[i].img)
		{
			mlx_destroy_image(data->mlx_ptr, data->door.frame[i].img);
			data->door.frame[i].img = NULL;
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
