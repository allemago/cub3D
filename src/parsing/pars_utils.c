/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 17:18:10 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	err_free_exit(char *str, t_data *data)
{
	if (str != NULL)
		ft_printf_fd(2, str);
	if (data != NULL)
	{
		if (data->pars && data->pars->fd_map != -1)
			manage_file(data, 'C');
		free_all(data, NO_DESTROY);
	}
	exit(EXIT_FAILURE);
}

void	check_alloc(void *ptr, t_data *data)
{
	if (ptr == NULL)
		err_free_exit(strerror(errno), data);
}

int	is_directory(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = -1;
	return (0);
}

void	manage_file(t_data *data, int flag)
{
	if (flag == 'O')
	{
		if (is_directory(data->pars->file))
		{
			ft_printf_fd(2, "%s: ", data->pars->file);
			err_free_exit(strerror(errno), data);
		}
		data->pars->fd_map = open(data->pars->file, O_RDONLY);
		if (data->pars->fd_map == -1)
		{
			ft_printf_fd(2, "%s: ", data->pars->file);
			err_free_exit(strerror(errno), data);
		}
	}
	else if (flag == 'C')
	{
		if (data->pars->fd_map != -1)
		{
			close(data->pars->fd_map);
			data->pars->fd_map = -1;
		}
	}
}

int	is_file_valid(t_data *data, char *map_file)
{
	int	ext;

	ext = ft_strlen(map_file) - 4;
	if (ext < 0 || ft_strnstr(&map_file[ext], ".cub", 4) == NULL)
		return (0);
	data->pars = ft_calloc(1, sizeof(t_pars));
	check_alloc(data->pars, data);
	data->pars->file = ft_strdup(map_file);
	if (data->pars->file == NULL)
	{
		free_ptr((void **)&data->pars);
		ft_printf_fd(2, strerror(errno));
		exit(1);
	}
	init_data(data);
	manage_file(data, 'O');
	return (1);
}
