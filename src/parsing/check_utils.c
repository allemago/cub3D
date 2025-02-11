/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 17:51:49 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_alloc(void *ptr, t_data *data)
{
	if (ptr == NULL)
		err_free_exit(strerror(errno), data);
}

void	alloc_map(char ***map, t_data *data)
{
	*map = ft_calloc(data->temp->y, sizeof(char *));
	check_alloc(*map, data);
}

int	check_file(t_data *data, char *argv)
{
	int	start;
	int	end;

	start = find_last_char(argv);
	end = start + 1;
	if ((start - 3) < 0)
		return (0);
	if (ft_strnstr(&argv[start - 3], ".cub", 4) == NULL)
		return (0);
	data->temp = malloc(sizeof(t_temp));
	if (data->temp == NULL)
		err_msg_exit();
	while (start > 0 && !search_set(argv[start - 1], ALL_SPACES))
		start--;
	data->temp->file = ft_strndup(&argv[start], end - start);
	if (data->temp->file == NULL)
		err_free_exit(strerror(errno), data);
	init_temp(data);
	manage_file(data, 'O');
	return (1);
}
