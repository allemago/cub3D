/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 19:09:25 by magrabko         ###   ########.fr       */
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
	if (!check_file(data, map_file))
	{
		ft_printf_fd(2, ERR_EXT_MSG);
		exit(1);
	}
	if (!is_map_valid(data))
	{
		free_all(data);
		exit(1);
	}
	else
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
