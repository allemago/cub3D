/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:25:16 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/24 16:25:31 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_door_walled(char **map, int i, int j)
{
	bool	is_next;

	is_next = false;
	if ((map[i][j + 1] && map[i][j + 1] == '1')
		&& (j - 1 >= 0 && map[i][j - 1] == '1'))
		is_next = true;
	if ((map[i + 1] && map[i + 1][j] == '1')
		&& (i - 1 >= 0 && map[i - 1][j] == '1'))
		is_next = true;
	return (is_next);
}

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
	else if (!is_c_inset(item, "01D "))
		return (ft_printf_fd(2, ERR_ITEM_MSG), 0);
	if (item == '1' && !is_open(data->map, '&', i, j))
		return (ft_printf_fd(2, ERR_WALL_MSG), 0);
	if (is_c_inset(item, "NSEW0D") && !is_open(data->map, '|', i, j))
		return (ft_printf_fd(2, ERR_ITEM_MSG), 0);
	if (item == 'D' && !is_door_walled(data->map, i, j))
		return (ft_printf_fd(2, ERR_DOOR_MSG), 0);
	return (1);
}

static int	check_wall_b(char **map, int i)
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

int	check_map_bonus(t_data *data, int last)
{
	int	i;
	int	j;

	i = 0;
	while (data->pars->map_check[i])
	{
		if ((i == 0 || i == last) && !check_wall_b(data->pars->map_check, i))
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
