/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 16:57:53 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_temp(t_data *data)
{
	data->temp->item = ft_calloc(2, sizeof(int));
	if (data->temp->item == NULL)
		err_free_exit(strerror(errno), data);
	data->temp->x = 0;
	data->temp->y = 0;
	data->temp->fd_map = -1;
	data->temp->map_check = NULL;
	data->temp->line = NULL;
}

void	init_data(t_data *data)
{
	data->player_x = 0;
	data->player_y = 0;
	data->width = 0;
	data->height = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->img_x = 0;
	data->img_y = 0;
	data->facing = 0;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->map = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->temp = NULL;
	data->sprite = NULL;
}

static int	set_rgb(t_data *data, char *info, int i)
{
	char	**rgb;

	rgb = ft_split(info, ',');
	free_ptr((void **)&info);
	check_alloc(rgb, data);
	if (rgb[3] != NULL)
		return (0);
	if (i == 4)
	{
		data->f_color[0] = ft_atoi(rgb[0]);
		data->f_color[1] = ft_atoi(rgb[1]);
		data->f_color[2] = ft_atoi(rgb[2]);
	}
	else if (i == 5)
	{
		data->c_color[0] = ft_atoi(rgb[0]);
		data->c_color[1] = ft_atoi(rgb[1]);
		data->c_color[2] = ft_atoi(rgb[2]);
	}
	return (1);
}

int	set_element(t_data *data, char *temp, int i)
{
	char	*info;
	int		index;

	info = get_element_info(data, temp, &index);
	pass_spaces(&temp[index], &index);
	if (temp[index])
		return (0);
	if (i < 4)
	{
		if (access(info, O_RDONLY))
			return (perror("indentifier"), 0);
		if (i == 0)
			data->north = info;
		else if (i == 1)
			data->south = info;
		else if (i == 2)
			data->west = info;
		else if (i == 3)
			data->east = info;
	}
	else if (!set_rgb(data, info, i))
		return (0);
	return (1);
}
