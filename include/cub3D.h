/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/20 17:47:18 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "parsing.h"
# include "structures.h"

# define RED_INT 0xFF0000
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

/*******************************************
 *                   MLX                    *
 ********************************************/
void	ft_init_mlx(t_data *data);
void	ft_init_player(t_data *data);
void	ft_events_mlx(t_data *data);
/*******************************************
 *                  DRAW                    *
 ********************************************/
void	ft_put_pixel(t_text *img, int x, int y, int color);
void	ft_draw_player(t_text *img, int x, int y, int size, int color);
void	ft_clear_player(t_data *data);
/*******************************************
 *                  EXEC                    *
 ********************************************/
void	ft_ray_direction(t_player *player, t_ray *ray);

// /* TEMPORAIRE -> TESTS */
void	print_all(t_data *data);
#endif
