/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/17 15:47:19 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	free_all(t_data *data)
{
	if (data->temp != NULL)
		free_temp(data);
	if (data->map != NULL)
		free_tab(&data->map);
	if (data->f_color != NULL)
		free_ptr((void **)&data->f_color);
	if (data->c_color != NULL)
		free_ptr((void **)&data->c_color);
	if (data->north != NULL)
		free_ptr((void **)&data->north);
	if (data->south != NULL)
		free_ptr((void **)&data->south);
	if (data->west != NULL)
		free_ptr((void **)&data->west);
	if (data->east != NULL)
		free_ptr((void **)&data->east);
}

void	free_temp(t_data *data)
{
	if (data->temp != NULL)
	{
		free_ptr((void **)&data->temp->file);
		free_ptr((void **)&data->temp->line);
		if (data->temp->rgb)
		{
			free_tab(&data->temp->rgb);
		}
		free_tab(&data->temp->map_check);
		free_ptr((void **)&data->temp);
	}
}
