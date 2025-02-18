/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:31:30 by magrabko          #+#    #+#             */
/*   Updated: 2025/02/18 15:14:50 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pass_spaces(char *str, int *index)
{
	int	i;

	i = 0;
	while (str[i] && search_c_set(str[i], ALL_SPACES))
		i++;
	*index += i;
}

int	search_str_set(char *str, char *set)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (search_c_set(str[i], set))
			return (str[i]);
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

int	get_first_c(char *str)
{
	int	i;

	i = 0;
	while (str[i] && search_c_set(str[i], ALL_SPACES))
		i++;
	return (str[i]);
}

int	go_last_char(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && (search_c_set(str[i], ALL_SPACES) || str[i] == '\0'))
		i--;
	return (i);
}
