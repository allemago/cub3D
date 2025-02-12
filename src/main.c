/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 17:05:19 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_input(t_data *data, int argc, char *map_file)
{
	if (argc != 2)
	{
		ft_printf_fd(2, ARGC_MSG);
		exit(1);
	}
	if (!is_file_valid(data, map_file))
	{
		ft_printf_fd(2, ERR_EXT_MSG);
		exit(1);
	}
	if (!check_elements(data))
	{
		err_free_exit(ERR_ELEM_MSG, data);
	}
	if (!check_map(data))
	{
		err_free_exit(NULL, data);
	}
	free_temp(data);
}

int main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_input(&data, argc, argv[1]);
	free_all(&data);
	return (0);
}
