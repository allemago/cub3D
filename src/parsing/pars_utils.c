/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/16 16:08:58 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!search_c_set(line[i], ALL_SPACES))
			return (0);
		i++;
	}
	return (1);
}

int	search_str_set(char *str, char *set)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (search_c_set(str[i], set))
			return (1);
		i++;
	}
	return (0);
}

int	search_c_set(char c, char *set)
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

void	pass_spaces(char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i] && search_c_set(str[i], ALL_SPACES))
		i++;
	*index += i;
}
