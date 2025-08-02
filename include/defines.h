/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:07:28 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 13:54:43 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/********************************************
 *              PARSING & MSG               *
 ********************************************/
# define FIRST_C 0
# define LAST_C 1
# define NO_DESTROY 0
# define DESTROY 1
# define ALL_SPACES " \t\n\v\f\r"
# define W_SPACES "\t\n\v\f\r"

# define ARGC_MSG "Error: try ./cub3D map.cub\n"
# define ERR_EXT_MSG "Error: wrong file extension, use a .cub file.\n"
# define ERR_EMPTY_MSG "Map: no empty lines allowed.\n"
# define ERR_COLOR_MSG "(F) and (C) colors must be in R,G,B format (0-255).\n"
# define ERR_ELEM_MSG "Error: invalid element in file.\n"
# define ERR_WALL_MSG "Error: map must be surrounded by walls (1).\n"
# define ERR_PLAYER_MSG "Map: only one player allowed.\n"
# define ERR_MISS_MSG "Missing elements in file.\n"
# define ERR_ITEM_MSG "Error: item conditions not met.\n"
# define ERR_DOOR_MSG "Error: door must be walled on both sides.\n"
# define XTI_FAIL_MSG "create img failed\n"
# define GDA_FAIL_MSG "add img failed\n"
# define MLX_INIT_MSG "mlx_init failed\n"
# define MLX_WIN_MSG "mlx_new_window failed\n"
# define RADAR_MEM_MSG "minimap: malloc failed\n"

/********************************************
 *                  EXEC                    *
 ********************************************/
# define WIDTH 1024
# define HEIGHT 680
# define TEXTURE_SIZE 64
# define DOOR 0

# define KEY_ESC 65307
# define KEY_ESPACE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define SPEED 0.04
# define ROTSPEED 0.02

/* MINIMAP */
# define MINI_MARGE_X 1014
# define MINI_MARGE_Y 10
# define MINI_MAX 200

# define COLOR_WALL 0x634100
# define COLOR_FLOOR 0xDCDCDC
# define COLOR_DOOR 0xFFCC00
# define COLOR_PLAYER 0xFF0000
# define COLOR_VOID 0x696969

#endif
