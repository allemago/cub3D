/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/17 18:29:44 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_input(t_data *data, int argc, char *map_file)
{
	if (argc != 2 || !map_file[0] || search_str_set(map_file, ALL_SPACES))
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

void	print_all(t_data *data)
{
	int i = 0;

	printf("player x = [%d]\n", data->player_x);
	printf("player y = [%d]\n", data->player_y);
	printf("width = [%d]\n", data->width);
	printf("height = [%d]\n", data->height);
	printf("floor color = [%d][%d][%d]\n", data->f_color[0], data->f_color[1], data->f_color[2]);
	printf("ceiling color = [%d][%d][%d]\n", data->c_color[0], data->c_color[1], data->c_color[2]);
	printf("facing = [%c]\n", data->facing);
	printf("north = [%s]\n", data->north);
	printf("south = [%s]\n", data->south);
	printf("west = [%s]\n", data->west);
	printf("east = [%s]\n\n", data->east);
	while (data->map[i])
		printf("[%s]\n", data->map[i++]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_input(&data, argc, argv[1]);
 /* print_all(&data); */
	free_all(&data);
	return (0);
}
