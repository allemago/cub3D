/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:36:36 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/01 17:08:30 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	set_rgb(t_data *data, char *info, char c)
{
	data->pars->rgb = ft_split(info, ',');
	free_ptr((void **)&info);
	check_alloc(data->pars->rgb, data);
	if (data->pars->rgb[1] == NULL || data->pars->rgb[2] == NULL
		|| data->pars->rgb[3] != NULL || !is_rgb_valid(data->pars->rgb))
		return (ft_printf_fd(2, ERR_COLOR_MSG), 0);
	if (c == 'F')
	{
		data->f_color = malloc(sizeof(int) * 3);
		check_alloc(data->f_color, data);
		data->f_color[0] = ft_atoi(data->pars->rgb[0]);
		data->f_color[1] = ft_atoi(data->pars->rgb[1]);
		data->f_color[2] = ft_atoi(data->pars->rgb[2]);
	}
	else if (c == 'C')
	{
		data->c_color = malloc(sizeof(int) * 3);
		check_alloc(data->c_color, data);
		data->c_color[0] = ft_atoi(data->pars->rgb[0]);
		data->c_color[1] = ft_atoi(data->pars->rgb[1]);
		data->c_color[2] = ft_atoi(data->pars->rgb[2]);
	}
	free_tab(&data->pars->rgb);
	return (1);
}

static void	set_orientation(t_data *data, char *line, char *info)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		data->north = info;
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		data->south = info;
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		data->west = info;
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		data->east = info;
}

int	set_element(t_data *data, char *line, int start, int index)
{
	char	*info;

	info = get_element_info(data, &line[start], &index);
	pass_spaces(&line[start + index], &index);
	if (line[start + index])
		return (free_ptr((void **)&info), 0);
	if (is_str_inset(line, "FC"))
	{
		if (!ft_isdigit(info[0]) || (ft_count_occ(info, ',') != 2))
			return (free_ptr((void **)&info), 0);
		if (!set_rgb(data, info, is_str_inset(line, "FC")))
			return (0);
	}
	else
	{
		if (is_directory(info) || access(info, O_RDONLY))
		{
			perror(info);
			return (free_ptr((void **)&info), 0);
		}
		set_orientation(data, line, info);
	}
	return (1);
}
