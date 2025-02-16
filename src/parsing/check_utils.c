/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/16 18:14:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_map(t_data *data, int i)
{
	int	j;

	data->height = data->temp->y - i;
	data->map = malloc(sizeof(char *) * (data->height + 1));
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

char	*get_element_info(t_data *data, char *temp, int *index)
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
/*
char	*get_element(char *line, char *temp, int i)
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
	if (temp == NULL || !search_c_set(temp[n], ALL_SPACES))
		return (NULL);
	return (&temp[n]);
}
 */

int	get_element(char *line)
{
	char	*temp;
	int		n;

	temp = NULL;
	n = ft_strlen(line);
	if (ft_strnstr(line, "NO", n))
		temp = ft_strnstr(line, "NO", n);
	else if (ft_strnstr(line, "SO", n))
		temp = ft_strnstr(line, "SO", n);
	else if (ft_strnstr(line, "WE", n))
		temp = ft_strnstr(line, "WE", n);
	else if (ft_strnstr(line, "EA", n))
		temp = ft_strnstr(line, "EA", n);
	else if (ft_strnstr(line, "F", n))
		temp = ft_strnstr(line, "F", n);
	else if (ft_strnstr(line, "C", n))
		temp = ft_strnstr(line, "C", n);
	else
		return (0);
	if (temp[0] == 'F' || temp[0] == 'C')
		n = 1;
	else
		n = 2;
	return (n);
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
