/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/17 18:24:16 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_map(t_data *data, int i)
{
	int	j;

	while (data->temp->map_check[i] && is_line_empty(data->temp->map_check[i]))
		i++;
	if (data->temp->map_check[i] == NULL)
		return (0);
	data->height = data->temp->y - i;
	data->map = malloc(sizeof(char *) * (data->height + 1));
	check_alloc(data->map, data);
	j = 0;
	while (data->temp->map_check[i])
	{
		data->map[j] = ft_strdup(data->temp->map_check[i]);
		check_alloc(data->map[j], data);
		if (is_line_empty(data->map[j]))
		{
			if (!check_map_end(data->map, j))
				return (free_ptr((void **)&data->map[j]), 0);
			return (free_ptr((void **)&data->map[j]), data->map[j] = NULL, 1);
		}
		j++;
		i++;
	}
	data->map[j] = NULL;
	return (1);
}

static int	go_first_c(char *str)
{
	int	i;

	i = 0;
	while (str[i] && search_c_set(str[i], ALL_SPACES))
		i++;
	return (str[i]);
}
/*
int	get_element(t_data *data, char *line, int n)
{
	char	*temp;
	int		first_char;

	temp = NULL;
	if (ft_strnstr(line, "NO", n) && !data->north)
		temp = ft_strnstr(line, "NO", n);
	else if (ft_strnstr(line, "SO", n) && !data->south)
		temp = ft_strnstr(line, "SO", n);
	else if (ft_strnstr(line, "WE", n) && !data->west)
		temp = ft_strnstr(line, "WE", n);
	else if (ft_strnstr(line, "EA", n) && !data->east)
		temp = ft_strnstr(line, "EA", n);
	else if (ft_strnstr(line, "F", n) && !data->f_color)
		temp = ft_strnstr(line, "F", n);
	else if (ft_strnstr(line, "C", n) && !data->c_color)
		temp = ft_strnstr(line, "C", n);
	else if (temp == NULL)
		return (0);
	first_char = 0;
	pass_spaces(line, &first_char);
	if (temp[0] == 'F' || temp[0] == 'C')
	{
		if (line[first_char] != 'F' && line[first_char] != 'C')
			return (0);
		return (n = (n - ft_strlen(temp)) + 1);
	}
	return (n = (n - ft_strlen(temp)) + 2);
}
*/

int	get_element(t_data *data, char *line, int n)
{
	char	*temp;

	temp = NULL;
	if (ft_strnstr(line, "NO", n) && !data->north)
		temp = ft_strnstr(line, "NO", n);
	else if (ft_strnstr(line, "SO", n) && !data->south)
		temp = ft_strnstr(line, "SO", n);
	else if (ft_strnstr(line, "WE", n) && !data->west)
		temp = ft_strnstr(line, "WE", n);
	else if (ft_strnstr(line, "EA", n) && !data->east)
		temp = ft_strnstr(line, "EA", n);
	else if (ft_strnstr(line, "F", n) && !data->f_color)
		temp = ft_strnstr(line, "F", n);
	else if (ft_strnstr(line, "C", n) && !data->c_color)
		temp = ft_strnstr(line, "C", n);
	else if (temp == NULL)
		return (0);
	if (temp[0] == 'F' || temp[0] == 'C')
	{
		if (!search_c_set(go_first_c(line), "FC"))
			return (0);
		return (n = (n - ft_strlen(temp)) + 1);
	}
	return (n = (n - ft_strlen(temp)) + 2);
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
