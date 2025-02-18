/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:09:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/18 15:17:10 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map_size(t_data *data, char **map_check, int *i)
{
	int	start;
	int	len;

	start = *i;
	while (map_check[start] && is_line_empty(map_check[start]))
		start++;
	if (map_check[start] == NULL)
		return (0);
	data->height = data->temp->y - start;
	*i = start;
	while (map_check[start])
	{
		len = ft_strlen(map_check[start]);
		if (data->width < len)
			data->width = len;
		start++;
	}
	return (1);
}

int	fill_map_game(t_data *data, int i)
{
	int	j;
	int	len;

	if (!get_map_size(data, data->temp->map_check, &i))
		return (0);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	check_alloc(data->map, data);
	j = 0;
	while (data->temp->map_check[i])
	{
		if (is_line_empty(data->temp->map_check[i]))
			return (data->map[j] = NULL, check_end(data, i));
		data->map[j] = malloc(sizeof(char) * data->width + 1);
		check_alloc(data->map[j], data);
		data->map[j][data->width] = '\0';
		ft_memset(data->map[j], ' ', data->width);
		len = ft_strlen(data->temp->map_check[i]);
		ft_memcpy(data->map[j++], data->temp->map_check[i++], len);
	}
	data->map[j] = NULL;
	return (1);
}

static char	**add_to_map(t_data *data, char *line)
{
	char	**new_map;
	int		i;

	check_alloc(line, data);
	new_map = malloc(sizeof(char *) * (data->temp->y + 1));
	check_alloc(new_map, data);
	if (data->temp->map_check)
	{
		i = 0;
		while (data->temp->map_check[i])
		{
			new_map[i] = ft_strdup(data->temp->map_check[i]);
			check_alloc(new_map[i], data);
			i++;
		}
	}
	free_tab(&data->temp->map_check);
	new_map[data->temp->y - 1] = line;
	new_map[data->temp->y] = NULL;
	return (new_map);
}

/*
**	manage_file function,
**	'O' to open the file
** 	'C' to close the file.
*/
int	fill_map_check(t_data *data)
{
	while (data->temp->fd_map > 0)
	{
		data->temp->line = get_next_line(data->temp->fd_map);
		if (data->temp->line == NULL)
		{
			manage_file(data, 'C');
			break ;
		}
		if (is_line_empty(data->temp->line) && data->temp->y < 7)
			free_ptr((void **)&data->temp->line);
		else
		{
			data->temp->y++;
			data->temp->map_check = add_to_map(data,
					ft_strtrim(data->temp->line, "\n"));
			free_ptr((void **)&data->temp->line);
		}
	}
	if (data->temp->y < 9)
		return (0);
	return (1);
}
