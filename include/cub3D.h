/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/28 17:04:26 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include "defines.h"
# include "structures.h"
# include "parsing.h"

/********************************************
 *                  EXEC                    *
 ********************************************/
void	ft_raycasting(t_data *data);
void	ft_calculate_texture(t_data *data, int x);
void	destroy_all(t_data *data);
/*********************************************
 *                   INIT                    *
 *********************************************/
void	ft_init_player(t_data *data);
void	ft_init_ray(t_data *data);
void	ft_init_img(t_data *data);
void	ft_change_face(t_data *data);
int		ft_loop(t_data *data);
void	ft_add_img(t_data *data);
void	ft_set_path(t_data *data);

/*********************************************
 *                  EVENTS                   *
 *********************************************/
void	ft_calculate_rotate(t_data *data, double angle);
void	ft_events(t_data *data);
void	ft_moves(t_data *data);
void	ft_rotate(t_data *data);
int		ft_destroy(t_data *data);
int		ft_keypress(int keycode, t_data *data);
int		ft_keyrelease(int keycode, t_data *data);
void	ft_move_direction(t_data *data, double x, double y, double sign);

/********************************************
 *                  DRAW                    *
 ********************************************/
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_draw_background(t_data *data);

/********************************************
 *                 BONUS                    *
 ********************************************/
void	ft_events_bonus(t_data *data);
void	ft_draw_minimap(t_data *data);
void	ft_init_img_bonus(t_data *data);

/********************************************
 *               ANIMATION                    *
 ********************************************/
int		ft_anim_hand(t_data *data);
void	ft_draw_anim(t_data *data, t_img img, int i, int j);
void	ft_init_hand(t_data *data);
void	ft_init_door(t_data *data);

#endif
