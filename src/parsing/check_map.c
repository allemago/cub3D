/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:08 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 13:22:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!search_set(line[i], ALL_SPACES))
			return (0);
		i++;
	}
	return (1);
}

/*
**	To avoid checking inside walls :
**	i = 1; to start from second row of the map,
**	j = 1; to start from second column of the map.
**
**	Inside temp->item[2] = {0, 0};
**	item[0] for player,
**	item[1] for exit.
*/
int	check_map_items(t_data *data, int i, int j)
{
	while (i++ < data->temp->y - 1)
	{
		j = 0;
		while (j++ < data->temp->x - 1)
		{
			if (search_set(data->temp->map_check[i][j], "NSEW"))
			{
				data->player_x = j;
				data->player_y = i;
				data->facing = data->temp->map_check[i][j];
			}
			else if (data->temp->map_check[i][j] != '0'
				&& data->temp->map_check[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->temp->y)
	{
		if (data->temp->map_check[i][0] != '1'
			|| data->temp->map_check[i][data->temp->x - 1] != '1')
			return (0);
		j = 0;
		if (i == 0 || i == data->temp->y - 1)
		{
			while (j < data->temp->x)
			{
				if (data->temp->map_check[i][j] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

char	**add_to_map(t_data *data, char *line)
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
**
**	temp->line == NULL --> true when file read ends.
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
		if (!is_line_empty(data->temp->line))
		{
			data->temp->y++;
			data->temp->map_check = add_to_map(data,
					ft_strtrim(data->temp->line, "\n"));
		}
		free_ptr((void **)&data->temp->line);
	}
	if (data->temp->y < 9)
		return (0);
	return (1);
}

int	add_rgb(t_data *data, char *info, int i)
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

char	*get_id_info(t_data *data, char *temp, int *index)
{
	char	*info;
	int		end;

	end = 0;
	while (temp[end] && !search_set(temp[end], ALL_SPACES))
		end++;
	info = ft_strndup(temp, end);
	check_alloc(info, data);
	*index = end;
	return (info);
}

char	*pass_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && search_set(str[i], ALL_SPACES))
		i++;
	return (&str[i]);
}

int	set_elements(t_data *data, char *temp, int i, int index)
{
	char	*info;

	info = get_id_info(data, temp, &index);
	temp += index;
	temp = pass_spaces(temp);
	if (temp[0])
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
	else
		if (!add_rgb(data, info, i))
			return (0);
	return (1);
}

char	*get_identifier(char *line, char *temp, int i)
{
	int	n;

	n = ft_strlen(line);
	if (i == 0)
		temp = ft_strnstr(line, "NO", n);
	else if (i == 1)
		temp = ft_strnstr(line, "SO", n);
	else if (i == 2)
		temp = ft_strnstr(line, "WE", n);
	else if (i == 3)
		temp = ft_strnstr(line, "EA", n);
	else if (i == 4)
		temp = ft_strnstr(line, "F", n);
	else if (i == 5)
		temp = ft_strnstr(line, "C", n);
	if (i < 4)
		n = 2;
	else
		n = 1;
	if (temp == NULL || !search_set(temp[n], ALL_SPACES))
		return (NULL);
	return (&temp[n]);
}

void	load_map(t_data *data, int i)
{
	int	j;

	data->map = malloc(sizeof(char *) * ((data->temp->y - i) + 1));
	check_alloc(data->map, data);
	j = 0;
	while (data->temp->map_check[i])
	{
		data->map[j] = ft_strdup(data->temp->map_check[i]);
		check_alloc(data->map[j], data);
		j++;
		i++;
	}
	data->map[j] = NULL;
}

int	check_identifier(t_data *data, int i)
{
	char	*temp;

	temp = NULL;
	if (!fill_map_check(data))
		return (0);
	while (i < 6)
	{
		temp = get_identifier(data->temp->map_check[i], temp, i);
		if (!temp)
			return (0);
		temp = pass_spaces(temp);
		if (!temp[0])
			return (0);
		if (!set_elements(data, temp, i, 0))
			return (0);
		i++;
	}
	load_map(data, i);
	return (1);
}

int	is_map_valid(t_data *data)
{
	if (!check_identifier(data, 0))
		return (ft_printf_fd(2, "Error: Invalid map.\n"), 0);
	/*	if (check_walls(data) == 0)
			return (ft_printf_fd(2, "Error: Map must be surrounded by 1.\n"),
				0);*/
	return (1);
}
