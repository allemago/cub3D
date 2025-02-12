/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/12 16:32:25 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!search_set(line[i], ALL_SPACES))
			return (0);
		i++;
	}
	return (1);
}

int	search_set(char c, char *set)
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

int	find_last_char(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && (search_set(str[i], ALL_SPACES) || str[i] == '\0'))
		i--;
	return (i);
}

void	pass_spaces(char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i] && search_set(str[i], ALL_SPACES))
		i++;
	*index += i;
}
