/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:58:44 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/16 16:39:26 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_occ(const char *s, char c)
{
	size_t	i;
	int		occ;

	i = 0;
	occ = 0;
	while (s[i])
	{
		if (s[i] == c)
			occ++;
		i++;
	}
	return (occ);
}
