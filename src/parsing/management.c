/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 17:07:32 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_ptr(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_tab(char ***tab)
{
	size_t	i;

	if (tab == NULL || *tab == NULL)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free_ptr((void **)&(*tab)[i]);
		i++;
	}
	free_ptr((void **)tab);
}

void	free_all(t_data *data)
{
	if (data->temp != NULL)
		free_temp(data);
}

void	free_temp(t_data *data)
{
	if (data->temp != NULL)
	{
		free_ptr((void **)&data->temp->item);
		free_ptr((void **)&data->temp->file);
		free_ptr((void **)&data->temp->line);
		free_tab(&data->temp->map_check);
		free_ptr((void **)&data->temp);
	}
}

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

void	err_msg_exit(void)
{
	perror(NULL);
	exit(1);
}
