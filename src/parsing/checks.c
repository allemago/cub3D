/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/18 16:23:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_map_items(t_data *data, char item, int i, int j)
{
	if (search_c_set(item, "NSEW"))
	{
		data->player_x = j;
		data->player_y = i;
		if (!data->facing)
			data->facing = item;
		else
			return (0);
	}
	else if (item != '0' && item != '1' && item != ' ')
		return (0);
	if (item == '1' && !check_around(data->map, '&', i, j))
		return (0);
	if (search_c_set(item, "NSEW0") && !check_around(data->map, '|', i, j))
		return (0);
	return (1);
}

static int	check_walls(char **map, int i)
{
	int	j;

	j = 0;
	pass_spaces(map[i], &j);
	while (map[i][j])
	{
		if (map[i][j] != '1' || (map[i][j] == '1' && !check_around(map, '&', i,
					j)))
			return (0);
		j++;
		if (search_c_set(map[i][j], ALL_SPACES))
		{
			pass_spaces(&map[i][j], &j);
		}
	}
	return (1);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		if ((i == 0 || i == data->height - 1) && !check_walls(data->map, i))
			return (ft_printf_fd(2, ERR_WALL_MSG), 0);
		else
		{
			j = 0;
			pass_spaces(data->map[i], &j);
			if (data->map[i][j] != '1'
				|| data->map[i][go_last_char(data->map[i])] != '1')
				return (ft_printf_fd(2, ERR_WALL_MSG), 0);
			while (data->map[i][j])
			{
				if (!check_map_items(data, data->map[i][j], i, j))
					return (ft_printf_fd(2, ERR_ITEM_MSG), 0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	check_elements(t_data *data)
{
	int	start;
	int	i;

	if (!fill_map_check(data))
		return (0);
	i = 0;
	while (i < 6)
	{
		start = get_element(data, data->temp->map_check[i],
				ft_strlen(data->temp->map_check[i]));
		if (!start)
			return (0);
		pass_spaces(&data->temp->map_check[i][start], &start);
		if (!data->temp->map_check[i][start])
			return (0);
		if (!set_element(data, data->temp->map_check[i], start, 0))
			return (0);
		i++;
	}
	if (!data->north || !data->south || !data->west || !data->east
		|| !data->f_color || !data->c_color)
		return (0);
	if (!fill_map_game(data, i))
		return (0);
	return (1);
}

void	check_input(t_data *data, int argc, char *map_file)
{
	if (argc != 2 || !map_file[0] || search_str_set(map_file, ALL_SPACES))
	{
		ft_printf_fd(2, ARGC_MSG);
		exit(1);
	}
	if (!is_file_valid(data, map_file))
	{
		ft_printf_fd(2, ERR_EXT_MSG);
		exit(1);
	}
	if (!check_elements(data))
	{
		err_free_exit(ERR_ELEM_MSG, data);
	}
	if (!check_map(data))
	{
		err_free_exit(NULL, data);
	}
	free_temp(data);
}
