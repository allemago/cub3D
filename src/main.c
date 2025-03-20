/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/20 18:03:54 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_all(t_data *data)
{
	int	i;

	i = 0;
	printf("width = [%d]\n", WIDTH);
	printf("height = [%d]\n", HEIGHT);
	printf("player x = [%d]\n", data->pars->player_x);
	printf("player y = [%d]\n", data->pars->player_y);
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

/* 

	!!	Segfault dans destroy_textures (depuis ft_destroy)
	!!	parce qu'il faut adapter l'exec aux nouvelles structures

*/
int	main(int argc, char **argv)
{
	t_data	data;
	
	check_input(&data, argc, argv[1]);
	print_all(&data);
	ft_init_mlx(&data);
	free_all(&data);
	return (0);
}
