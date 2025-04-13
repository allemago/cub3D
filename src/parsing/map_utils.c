/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:09:35 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/13 20:27:02 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	reset_maps(t_data *data, int i, int j)
{
	free_tab(&data->pars->map_check);
	data->pars->map_check = ft_calloc((data->height + 1), sizeof(char *));
	check_alloc(data->pars->map_check, data);
	while (data->map[i])
	{
		data->pars->map_check[i] = ft_strdup(data->map[i]);
		check_alloc(data->pars->map_check[i], data);
		i++;
	}
	data->pars->map_check[i] = NULL;
	i = 0;
	while (data->map[i] && data->pars->map_check[i])
	{
		while (data->map[i][j] && data->pars->map_check[i][j])
		{
			if (is_c_inset(data->map[i][j], "\t\n\v\f\r"))
			{
				data->map[i][j] = ' ';
				data->pars->map_check[i][j] = ' ';
			}
			j++;
		}
		i++;
	}
}

static int	get_map_size(t_data *data, char **map_check, int *i)
{
	int	start;
	int	len;

	start = *i;
	while (map_check[start] && is_line_empty(map_check[start]))
		start++;
	if (map_check[start] == NULL)
		return (0);
	data->height = data->pars->y - start;
	*i = start;
	while (map_check[start])
	{
		len = go_edge_char(map_check[start], LAST_C) + 1;
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

	if (!get_map_size(data, data->pars->map_check, &i))
		return (0);
	data->map = ft_calloc((data->height + 1), sizeof(char *));
	check_alloc(data->map, data);
	j = 0;
	while (data->pars->map_check[i])
	{
		if (is_line_empty(data->pars->map_check[i]))
			return (data->map[j] = NULL, go_end_map(data, i));
		data->map[j] = ft_calloc((data->width + 1), sizeof(char));
		check_alloc(data->map[j], data);
		data->map[j][data->width] = '\0';
		ft_memset(data->map[j], ' ', data->width);
		len = go_edge_char(data->pars->map_check[i], LAST_C) + 1;
		ft_memcpy(data->map[j++], data->pars->map_check[i++], len);
	}
	data->map[j] = NULL;
	reset_maps(data, 0, 0);
	return (1);
}

static char	**add_to_map(t_data *data, char *line)
{
	char	**new_map;
	int		i;

	check_alloc(line, data);
	new_map = ft_calloc((data->pars->y + 1), sizeof(char *));
	check_alloc(new_map, data);
	if (data->pars->map_check)
	{
		i = 0;
		while (data->pars->map_check[i])
		{
			new_map[i] = ft_strdup(data->pars->map_check[i]);
			check_alloc(new_map[i], data);
			i++;
		}
	}
	free_tab(&data->pars->map_check);
	new_map[data->pars->y - 1] = line;
	new_map[data->pars->y] = NULL;
	return (new_map);
}

/*
**	manage_file function,
**	'O' to open the file
** 	'C' to close the file.
*/
int	fill_map_check(t_data *data)
{
	while (data->pars->fd_map > 0)
	{
		data->pars->line = get_next_line(data->pars->fd_map);
		if (data->pars->line == NULL)
		{
			manage_file(data, 'C');
			break ;
		}
		if (is_line_empty(data->pars->line) && data->pars->y < 7)
			free_ptr((void **)&data->pars->line);
		else
		{
			data->pars->y++;
			data->pars->map_check = add_to_map(data,
					ft_strtrim(data->pars->line, "\n"));
			free_ptr((void **)&data->pars->line);
		}
	}
	if (data->pars->y < 9)
		return (0);
	return (1);
}
