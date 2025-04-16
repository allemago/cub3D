/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:07:28 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/16 13:46:47 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* PARSING */
# define BUFFER_SIZE 1
# define ALL_SPACES " \t\n\v\f\r"
# define FIRST_C 0
# define LAST_C 1
# define ARGC_MSG "Error: try ./cub3D map.cub\n"
# define ERR_EXT_MSG "Error: wrong file extension, use a .cub file.\n"
# define ERR_EMPTY_MSG "Map: no empty lines allowed.\n"
# define ERR_COLOR_MSG "(F) and (C) colors must be in R,G,B format (0-255).\n"
# define ERR_ELEM_MSG "Error: invalid element in file.\n"
# define ERR_WALL_MSG "Error: map must be surrounded by walls (1).\n"
# define ERR_PLAYER_MSG "Map: only one player allowed.\n"
# define ERR_MISS_MSG "Missing elements in file.\n"
# define ERR_ITEM_MSG "Error: item conditions not met.\n"

/* EXEC */
# define WIDTH 680
# define HEIGHT 480
# define TEXTURE_SIZE 64

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define SPEED 0.02
# define ROTSPEED 0.02
# define MARGIN 0.1


#endif
