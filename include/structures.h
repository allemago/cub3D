/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:27:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 16:15:09 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "cub3D.h"

typedef struct s_temp
{
	int			x;
	int			y;
	int			fd_map;
	int			*item;
	char		*file;
	char		*line;
	char		**map_check;
}				t_temp;

typedef struct s_sprite
{
	void		*b_wall;
	void		*i_wall;
	void		*ground;
	void		*fairy_p1;
	void		*toad_1;
	void		*toad_2;
	void		*exit_ok;
	void		*exit_ko;
}				t_sprite;

typedef struct s_data
{
	int			move_counter;
	int			item_count;
	int			item_found;
	int			player_x;
	int			player_y;
	int			on_exit;
	int			exit_x;
	int			exit_y;
	int			max_x;
	int			max_y;
	int			size_x;
	int			size_y;
	int			img_x;
	int			img_y;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_temp		*temp;
	t_sprite	*sprite;
}				t_data;

#endif
