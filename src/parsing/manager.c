/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:29:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 16:35:14 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	err_free_exit(char *str, t_data *data)
{
	if (str != NULL)
		ft_printf_fd(2, str);
	if (data != NULL)
	{
		if (data->temp->fd_map != -1)
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

void	manage_file(t_data *data, int flag)
{
	if (flag == 'O')
	{
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

int	is_file_valid(t_data *data, char *argv)
{
	int	start;
	int	end;

	start = find_last_char(argv);
	end = start + 1;
	if ((start - 3) < 0)
		return (0);
	if (ft_strnstr(&argv[start - 3], ".cub", ft_strlen(&argv[start - 3])) == NULL)
		return (0);
	data->temp = malloc(sizeof(t_temp));
	if (data->temp == NULL)
	{
		perror(NULL);
		exit(1);
	}
	while (start > 0 && !search_set(argv[start - 1], ALL_SPACES))
		start--;
	data->temp->file = ft_strndup(&argv[start], end - start);
	if (data->temp->file == NULL)
		err_free_exit(strerror(errno), data);
	init_temp(data);
	manage_file(data, 'O');
	return (1);
}
