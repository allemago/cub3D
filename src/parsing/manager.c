/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/17 18:29:58 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	err_free_exit(char *str, t_data *data)
{
	if (str != NULL)
		ft_printf_fd(2, str);
	if (data != NULL)
	{
		if (data->temp && data->temp->fd_map != -1)
			manage_file(data, 'C');
		free_all(data);
	}
	exit(1);
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
		if (is_directory(data->temp->file))
		{
			ft_printf_fd(2, "%s: ", data->temp->file);
			err_free_exit(strerror(errno), data);
		}
		data->temp->fd_map = open(data->temp->file, O_RDONLY);
		if (data->temp->fd_map == -1)
		{
			ft_printf_fd(2, "%s: ", data->temp->file);
			err_free_exit(strerror(errno), data);
		}
	}
	else if (flag == 'C')
	{
		if (data->temp->fd_map != -1)
		{
			close(data->temp->fd_map);
			data->temp->fd_map = -1;
		}
	}
}

int	is_file_valid(t_data *data, char *map_file)
{
	int	ext;

	ext = ft_strlen(map_file) - 4;
	if (ext < 0 || ft_strnstr(&map_file[ext], ".cub", 4) == NULL)
		return (0);
	data->temp = malloc(sizeof(t_temp));
	if (data->temp == NULL)
	{
		perror("is_file_valid");
		exit(1);
	}
	data->temp->file = ft_strdup(map_file);
	if (data->temp->file == NULL)
		err_free_exit(strerror(errno), data);
	init_temp(data);
	manage_file(data, 'O');
	return (1);
}
