/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/18 16:21:40 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_rgb_valid(char **rgb)
{
	long	r;
	long	g;
	long	b;

	r = ft_atol(rgb[0]);
	g = ft_atol(rgb[1]);
	b = ft_atol(rgb[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (0);
	return (1);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!search_c_set(line[i], ALL_SPACES))
			return (0);
		i++;
	}
	return (1);
}

int	check_end(t_data *data, int i)
{
	int	map_end;

	map_end = i;
	while (data->temp->map_check[i] && is_line_empty(data->temp->map_check[i]))
		i++;
	if (data->temp->map_check[i])
		return (0);
	data->height -= (i - map_end);
	return (1);
}

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
		if (!search_c_set(get_first_c(line), "FC"))
			return (0);
		return (n = (n - ft_strlen(temp)) + 1);
	}
	return (n = (n - ft_strlen(temp)) + 2);
}

int	check_around(char **map, char op, int i, int j)
{
	if (op == '&')
	{
		if ((!map[i][j + 1] || search_c_set(map[i][j + 1], ALL_SPACES)) && (j
				- 1 < 0 || search_c_set(map[i][j - 1], ALL_SPACES)) && (!map[i
				+ 1] || search_c_set(map[i + 1][j], ALL_SPACES)) && (i - 1 < 0
				|| search_c_set(map[i - 1][j], ALL_SPACES)))
			return (0);
	}
	else if (op == '|')
	{
		if ((!map[i][j + 1] || search_c_set(map[i][j + 1], ALL_SPACES)) || (j
				- 1 < 0 || search_c_set(map[i][j - 1], ALL_SPACES)) || (!map[i
				+ 1] || search_c_set(map[i + 1][j], ALL_SPACES)) || (i - 1 < 0
				|| search_c_set(map[i - 1][j], ALL_SPACES)))
			return (0);
	}
	return (1);
}
