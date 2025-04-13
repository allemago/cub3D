/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:17:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/12 11:23:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* STRUCT INIT */
void	init_data(t_data *data);

/* CHECKS */
void	check_input(t_data *data, int argc, char *map_file);
int		check_elements(t_data *data);
int		check_map(t_data *data, int last);
int		check_path(t_data *data);

/* MAP INIT */
int		fill_map_check(t_data *data);
int		fill_map_game(t_data *data, int i);

/* UTILS */
void	manage_file(t_data *data, int flag);
void	pass_spaces(char *str, int *index);
char	*get_element_info(t_data *data, char *temp, int *index);
int		is_open(char **map, char op, int i, int j);
int		get_element(t_data *data, char *line, int n);
int		go_edge_char(char *str, int edge);
int		go_end_map(t_data *data, int i);
int		is_directory(char *file);
int		is_file_valid(t_data *data, char *map_file);
int		is_line_empty(char *line);
int		is_rgb_valid(char **rgb);
int		is_c_inset(char c, char *set);
int		is_str_inset(char *str, char *set);
int		set_element(t_data *data, char *line, int start, int index);

/* MANAGEMENT */
void	check_alloc(void *ptr, t_data *data);
void	err_free_exit(char *str, t_data *data);
void	free_all(t_data *data);
void	free_ptr(void **ptr);
void	free_tab(char ***tab);
void	free_pars(t_data *data);
void	free_assets(t_data *data);
void	destroy_texture(t_data *data, t_img*texture, int i, int n);

#endif
