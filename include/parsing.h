/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:17:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/18 16:18:04 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

# define RED "\001\e[1;91m\002"
# define YELLOW "\001\e[1;93m\002"
# define CYAN "\001\e[1;96m\002"
# define GREEN "\001\e[1;92m\002"
# define MAGENTA "\001\e[1;95m\002"
# define RESET "\001\e[0m\002\n"
# define BUFFER_SIZE 1
# define ALL_SPACES " \t\n\v\f\r"
# define ARGC_MSG "Error: try ./cub3D map.cub\n"
# define ERR_EXT_MSG "Error: wrong file extension, use a .cub file.\n"
# define ERR_ELEM_MSG \
	"Error: invalid element in file.\nEnsure the format is correct:\n\
- NO, SO, WE, EA followed by a valid path.\n\
- Floor (F) and Ceiling (C) colors must be in R,G,B format (0-255).\n"
# define ERR_WALL_MSG "Error: map must be surrounded by walls (1).\n"
# define ERR_ITEM_MSG "Error: item conditions not met.\n"

/* STRUCT INIT */
void	init_data(t_data *data);
void	init_temp(t_data *data);
int		set_element(t_data *data, char *line, int start, int index);

/* CHECKS */
void	check_input(t_data *data, int argc, char *map_file);
int		check_elements(t_data *data);
int		check_map(t_data *data);

/* MAP INIT */
int		fill_map_check(t_data *data);
int		fill_map_game(t_data *data, int i);

/* UTILS */
void	manage_file(t_data *data, int flag);
void	pass_spaces(char *str, int *index);
int		check_around(char **map, char op, int i, int j);
int		check_end(t_data *data, int i);
int		get_element(t_data *data, char *line, int n);
int		get_first_c(char *str);
int		go_last_char(char *str);
int		is_directory(char *file);
int		is_file_valid(t_data *data, char *map_file);
int		is_line_empty(char *line);
int		is_rgb_valid(char **rgb);
int		search_c_set(char c, char *set);
int		search_str_set(char *str, char *set);

/* MANAGEMENT */
void	check_alloc(void *ptr, t_data *data);
void	err_free_exit(char *str, t_data *data);
void	free_all(t_data *data);
void	free_ptr(void **ptr);
void	free_tab(char ***tab);
void	free_temp(t_data *data);

#endif
