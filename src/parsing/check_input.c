/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/16 20:57:56 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_map_items(t_data *data, char item, int i, int j)
{
	if (search_c_set(item, "NSEW"))
	{
		data->player_x = j;
		data->player_y = i;
		data->facing = item;
	}
	else if (item != '0' && item != '1' && item != ' ')
		return (0);
	return (1);
}

static int	check_walls(char *line)
{
	int	i;

	i = 0;
	pass_spaces(line, &i);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	while (data->map[i])
	{
		if (i == 0 || i == data->height - 1)
			if (!check_walls(data->map[i]))
				return (ft_printf_fd(2, ERR_WALL_MSG), 0);
		j = 0;
		pass_spaces(data->map[i], &j);
		last = ft_strlen(data->map[i]) - 1;
		if (data->map[i][j] != '1' || data->map[i][last] != '1')
			return (ft_printf_fd(2, ERR_WALL_MSG), 0);
		while (data->map[i][j])
		{
			if (!check_map_items(data, data->map[i][j], i, j))
				return (ft_printf_fd(2, ERR_ITEM_MSG), 0);
			j++;
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
		start = get_element(data->temp->map_check[i]);
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
	load_map(data, i);
	return (1);
}

/* 

	Reste à faire:

	Pour vérifier uniquement les éléments avant la map:
	incrémenter un index jusqu'à 6 quand ligne != vide.
	Si index == 6, continuer à passer les lignes si elles sont vides.
	Puis copier le fichier à partir de cet index.

	Ajouter vérification si un élément est en double (2 x NO, SO, etc...);
	dans set_element.
	
*/
