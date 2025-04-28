/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 13:26:40 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_map_items(t_data *data, char item, int i, int j)
{
	if (is_c_inset(item, "NSEW"))
	{
		if (data->facing)
			return (ft_printf_fd(2, ERR_PLAYER_MSG), 0);
		data->pars->player_x = j;
		data->pars->player_y = i;
		data->facing = item;
		data->map[i][j] = '0';
	}
	else if (!is_c_inset(item, "01 "))
		return (ft_printf_fd(2, ERR_ITEM_MSG), 0);
	if (item == '1' && !is_open(data->map, '&', i, j))
		return (ft_printf_fd(2, ERR_WALL_MSG), 0);
	if (is_c_inset(item, "NSEW0") && !is_open(data->map, '|', i, j))
		return (ft_printf_fd(2, ERR_ITEM_MSG), 0);
	return (1);
}

static int	check_walls(char **map, int i)
{
	int	j;

	j = 0;
	pass_spaces(map[i], &j);
	while (map[i][j])
	{
		if (map[i][j] != '1' || (map[i][j] == '1' && !is_open(map, '&', i, j)))
			return (0);
		j++;
		if (is_c_inset(map[i][j], ALL_SPACES))
			pass_spaces(&map[i][j], &j);
	}
	return (1);
}

int	check_map(t_data *data, int last)
{
	int	i;
	int	j;

	i = 0;
	while (data->pars->map_check[i])
	{
		if ((i == 0 || i == last) && !check_walls(data->pars->map_check, i))
			return (ft_printf_fd(2, ERR_WALL_MSG), 0);
		else
		{
			j = 0;
			pass_spaces(data->pars->map_check[i], &j);
			if (data->pars->map_check[i][j] != '1'
				|| data->map[i][go_edge_char(data->map[i], LAST_C)] != '1')
				return (ft_printf_fd(2, ERR_WALL_MSG), 0);
			while (data->pars->map_check[i][j])
			{
				if (!check_map_items(data, data->pars->map_check[i][j], i, j))
					return (0);
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
		start = get_element(data, data->pars->map_check[i],
				ft_strlen(data->pars->map_check[i]));
		if (!start || !is_c_inset(data->pars->map_check[i][start], ALL_SPACES))
			return (0);
		pass_spaces(&data->pars->map_check[i][start], &start);
		if (!data->pars->map_check[i][start])
			return (0);
		if (!set_element(data, data->pars->map_check[i], start, 0))
			return (0);
		i++;
	}
	if ((!data->north || !data->south || !data->west
			|| !data->east || !data->f_color || !data->c_color)
		|| !fill_map_game(data, i) || !reset_maps(data, 0, 0))
		return (0);
	return (1);
}
