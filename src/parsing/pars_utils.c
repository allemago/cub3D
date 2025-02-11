/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 22:33:26 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	search_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (set[i]);
		i++;
	}
	return (0);
}

size_t	find_last_char(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0 && (search_set(str[i], ALL_SPACES) || str[i] == '\0'))
		i--;
	return (i);
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
