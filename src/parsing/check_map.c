/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 17:55:54 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
**	Opening the file with flag 'O',
**	closing the file with flag 'C'.
*/
void	fill_map(t_data *data, int i)
{
	alloc_map(&data->temp->map_check, data);
	manage_file(data, 'O');
	while (i < data->temp->y)
	{
		data->temp->line = get_next_line(data->temp->fd_map);
		check_alloc(data->temp->line, data);
		data->temp->map_check[i] = ft_strtrim(data->temp->line, "\n");
		check_alloc(data->temp->map_check[i], data);
		data->temp->x = ft_strlen(data->temp->map_check[i]);
		data->size_x = data->temp->x;
		free_ptr((void **)&data->temp->line);
		i++;
	}
	manage_file(data, 'C');
	alloc_map(&data->map, data);
	i = 0;
	while (i < data->temp->y)
	{
		data->map[i] = ft_strdup(data->temp->map_check[i]);
		check_alloc(data->map[i], data);
		printf("%s\n", data->map[i]);
		i++;
	}
}

/*
**	manage_file function,
**	'O' to open the file
** 	'C' to close the file.
**
**	temp->line == NULL --> true when file read ends.
*/
int	count_lines(t_data *data)
{
	while (data->temp->fd_map > 0)
	{
		data->temp->line = get_next_line(data->temp->fd_map);
		if (data->temp->line == NULL)
		{
			manage_file(data, 'C');
			break ;
		}
		data->temp->y++;
		free_ptr((void **)&data->temp->line);
	}
	data->size_y = data->temp->y;
	if (data->temp->y < 9)
		return (0);
	return (1);
}

int	is_map_valid(t_data *data)
{
	if (count_lines(data) == 0)
		return (ft_putstr_fd("Error: Invalid map.\n", 2), 0);
	fill_map(data, 0);
/* 	if (check_map_size(data) == 0)
		return (ft_putstr_fd("Error\nMap must be rectangular.\n", 2), 0);
	if (check_walls(data) == 0)
		return (ft_putstr_fd("Error\nMap must be surrounded by 1.\n", 2), 0);
	if (check_map_items(data, 0, 0) == 0)
		return (ft_putstr_fd("Error\nItem conditions not met.\n", 2), 0);
	if (check_path(data) == 0)
		return (ft_putstr_fd("Error\nExit/Collectibles not on path.\n", 2), 0); */
	return (1);
}
