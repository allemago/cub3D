/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:27:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 09:52:23 by magrabko         ###   ########.fr       */
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
}				t_sprite;

typedef struct s_data
{
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	int			max_x;
	int			max_y;
	int			img_x;
	int			img_y;
	int			f_color[3];
	int			c_color[3];
	char		facing;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_temp		*temp;
	t_sprite	*sprite;
}				t_data;

#endif
