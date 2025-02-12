/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:17:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 17:06:03 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

# define BUFFER_SIZE 1
# define ALL_SPACES " \t\n\v\f\r"
# define ARGC_MSG "Error: try ./cub3D map.cub\n"
# define ERR_EXT_MSG "Error: wrong file extension, use a .cub file.\n"
# define ERR_ELEM_MSG "Error: invalid information in identifier.\n"
# define ERR_WALL_MSG "Error: map must be surrounded by walls '1'.\n"
# define ERR_ITEM_MSG "Error: item conditions not met.\n"

/* STRUCT INIT */
void	init_data(t_data *data);
void	init_temp(t_data *data);
int		set_element(t_data *data, char *temp, int i);

/* CHECKS */
int		check_elements(t_data *data);
int		check_map(t_data *data);
char	*get_element(char *line, char *temp, int i);
char	*get_element_info(t_data *data, char *temp, int *index);

/* MAP INIT */
int		fill_map_check(t_data *data);
void	load_map(t_data *data, int i);

/* UTILS */
int		find_last_char(char *str);
int		is_file_valid(t_data *data, char *argv);
int		is_line_empty(char *line);
int		search_set(char c, char *set);
void	manage_file(t_data *data, int flag);
void	pass_spaces(char *str, int *index);

/* MANAGEMENT */
void	check_alloc(void *ptr, t_data *data);
void	err_free_exit(char *str, t_data *data);
void	free_all(t_data *data);
void	free_ptr(void **ptr);
void	free_tab(char ***tab);
void	free_temp(t_data *data);

#endif
