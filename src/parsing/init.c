/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/18 16:17:56 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_temp(t_data *data)
{
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
	data->f_color = NULL;
	data->c_color = NULL;
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

static int	set_rgb(t_data *data, char *info, char c)
{
	char	**rgb;

	rgb = ft_split(info, ',');
	free_ptr((void **)&info);
	check_alloc(rgb, data);
	if (rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL
		|| !is_rgb_valid(rgb))
		return (0);
	if (c == 'F')
	{
		data->f_color = malloc(sizeof(int) * 3);
		check_alloc(data->f_color, data);
		data->f_color[0] = ft_atoi(rgb[0]);
		data->f_color[1] = ft_atoi(rgb[1]);
		data->f_color[2] = ft_atoi(rgb[2]);
	}
	else if (c == 'C')
	{
		data->c_color = malloc(sizeof(int) * 3);
		check_alloc(data->c_color, data);
		data->c_color[0] = ft_atoi(rgb[0]);
		data->c_color[1] = ft_atoi(rgb[1]);
		data->c_color[2] = ft_atoi(rgb[2]);
	}
	return (1);
}

static char	*get_element_info(t_data *data, char *temp, int *index)
{
	char	*info;
	int		end;

	end = 0;
	while (temp[end] && !search_c_set(temp[end], ALL_SPACES))
		end++;
	info = ft_strndup(temp, end);
	check_alloc(info, data);
	*index = end;
	return (info);
}

int	set_element(t_data *data, char *line, int start, int index)
{
	char	*info;

	info = get_element_info(data, &line[start], &index);
	pass_spaces(&line[start + index], &index);
	if (line[start + index])
		return (0);
	if (search_str_set(line, "FC"))
	{
		if (!set_rgb(data, info, search_str_set(line, "FC")))
			return (0);
	}
	else
	{
		if (is_directory(info) || access(info, O_RDONLY))
			return (perror(info), 0);
		if (ft_strnstr(line, "NO", ft_strlen(line)))
			data->north = info;
		else if (ft_strnstr(line, "SO", ft_strlen(line)))
			data->south = info;
		else if (ft_strnstr(line, "WE", ft_strlen(line)))
			data->west = info;
		else if (ft_strnstr(line, "EA", ft_strlen(line)))
			data->east = info;
	}
	return (1);
}
