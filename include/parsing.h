/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:17:48 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/11 21:53:45 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

# define BUFFER_SIZE 1
# define ALL_SPACES " \t\n\v\f\r"
# define ARGC_MSG "Error: try ./cub3D map.cub\n"
# define ERR_EXT_MSG "Error: Wrong file extension, use a .cub file.\n"

/* INIT */
void	init_data(t_data *data);
void	init_temp(t_data *data);

/* CHECKS */
int		is_map_valid(t_data *data);
char	*get_next_line(int fd);
void	check_alloc(void *ptr, t_data *data);

/* UTILS */
size_t	find_last_char(char *str);
size_t	find_char(char *str, char c);
int		search_set(char c, char *set);
int		check_file(t_data *data, char *argv);
void	manage_file(t_data *data, int flag);
void	alloc_map(char ***map, t_data *data);
char	*ft_getnl(char *str);

/* MANAGEMENT */
void	err_free_exit(char *str, t_data *data);
void	free_all(t_data *data);
void	free_temp(t_data *data);
void	free_ptr(void **ptr);
void	free_tab(char ***tab);

#endif
