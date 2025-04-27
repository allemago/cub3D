/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/27 21:02:39 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pass_spaces(char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i] && is_c_inset(str[i], ALL_SPACES))
		i++;
	*index += i;
}

int	is_str_inset(char *str, char *set)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_c_inset(str[i], set))
			return (str[i]);
		i++;
	}
	return (0);
}

int	is_c_inset(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (set[i]);
		i++;
	}
	return (0);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_c_inset(line[i], ALL_SPACES))
			return (0);
		i++;
	}
	return (1);
}

int	go_edge_char(char *str, int edge)
{
	int	i;

	if (edge == FIRST_C)
	{
		i = 0;
		while (str[i] && is_c_inset(str[i], ALL_SPACES))
			i++;
		return (i);
	}
	else if (edge == LAST_C)
	{
		i = ft_strlen(str);
		while (i > 0 && (is_c_inset(str[i], ALL_SPACES) || str[i] == '\0'))
			i--;
		return (i);
	}
	return (0);
}
