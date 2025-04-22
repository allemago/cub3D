/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/04/22 14:50:51 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum s_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}				t_dir;

typedef struct s_pars
{
	char		*line;
	int			x;
	int			y;
	int			player_x;
	int			player_y;
	int			fd_map;
	char		*file;
	char		**rgb;
	char		**map_check;
}				t_pars;

typedef struct s_radar
{
	float		scale_x;
	float		scale_y;
	float		scale;
	float		tile_x;
	float		tile_y;
	float		tile;
}				t_radar;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_bresenham
{
	double		delta_x;
	double		delta_y;
	double		pixel_x;
	double		pixel_y;
	double		pixel_inc_x;
	double		pixel_inc_y;
}				t_bresenham;

typedef struct s_img
{
	void		*img;
	char		*pixels;
	char		*path;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;

}				t_img;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	bool		up;
	bool		down;
	bool		right;
	bool		left;
	bool		rotate_left;
	bool		rotate_right;
	bool		espace;
	bool		door;
}				t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		camera_x;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perpwalldist;
	double		step;
	double		tex_pos;
	double		wall_x;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			wall_side;
	int			tex_x;
	int			tex_y;
}				t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window;
	t_img		img[10];
	t_img		*texture;
	char		**map;
	int			height;
	int			width;
	char		facing;
	int			*f_color;
	int			*c_color;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_pars		*pars;
	t_radar		radar;
	t_player	player;
	t_ray		ray;
}				t_data;

#endif
