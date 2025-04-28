/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/04/28 19:30:07 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum s_hand
{
	HAND1 = 0,
	HAND2 = 1,
	HAND3 = 2,
	HAND4 = 3,
}				t_hand;

typedef enum s_dir
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
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
	float		tile_x;
	float		tile_y;
	float		tile;
}				t_radar;

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

typedef struct s_sprite
{
	t_img		frame[4];
	int			time_frame;
}				t_sprite;

typedef struct s_door
{
	t_img		frame[1];
	char		current_pos;
	bool		is_open;
}				t_door;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window;
	t_img		img[5];
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
	t_sprite	hand;
	t_door		door;
}				t_data;

#endif
