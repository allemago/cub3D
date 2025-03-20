/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/03/20 17:42:16 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"

# define WIDTH 1250
# define HEIGHT 720

typedef struct s_pars
{
	int			x;
	int			y;
	int			player_x;
	int			player_y;
	int			fd_map;
	char		*file;
	char		*line;
	char		**rgb;
	char		**map_check;
}				t_pars;

typedef struct s_text
{
	void		*img;
	char		*pixels;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;

}				t_text;

typedef struct s_hand
{
	t_text		frames[4];
	double		delay;
	int			current_frame;
}				t_hand;

typedef struct s_effect
{
	t_text		frames[11];
	double		delay;
	int			current_frame;
}				t_effect;

typedef struct s_assets
{
	t_text		*w_north;
	t_text		*w_south;
	t_text		*w_west;
	t_text		*w_east;
	t_text		*sky;
	t_text		*floor;
	t_text		*door;
	t_text		*donut;
	t_effect	*effect;
	t_hand		*hand;
}				t_assets;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
}				t_ray;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	double		angle;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	bool		up;
	bool		down;
	bool		right;
	bool		left;
	bool		rotate_right;
	bool		rotate_left;
	t_ray		ray;
}				t_player;

typedef struct s_data
{
	int			*f_color;
	int			*c_color;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		facing;
	int			height;
	int			width;
	char		**map;
	void		*mlx_ptr;
	void		*window;
	t_pars		*pars;
	t_text		*img;
	t_assets	*assets;
	t_player	player;
}				t_data;

#endif
