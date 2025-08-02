/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:03:31 by imatek            #+#    #+#             */
/*   Updated: 2025/04/27 17:50:43 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_add_hand(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->hand.frame[i].pixels = mlx_get_data_addr(data->hand.frame[i].img,
				&data->hand.frame[i].bpp, &data->hand.frame[i].line_len,
				&data->hand.frame[i].endian);
		if (!data->hand.frame[i].pixels)
		{
			free_all(data, DESTROY);
			err_exit(GDA_FAIL_MSG);
		}
		i++;
	}
}

static	void	ft_set_hand(t_data *data)
{
	data->hand.frame[HAND1].path = "./textures/HAND/HAND_1.xpm";
	data->hand.frame[HAND2].path = "./textures/HAND/HAND_2.xpm";
	data->hand.frame[HAND3].path = "./textures/HAND/HAND_3.xpm";
	data->hand.frame[HAND4].path = "./textures/HAND/HAND_4.xpm";
}

void	ft_init_hand(t_data *data)
{
	int	i;

	ft_set_hand(data);
	i = 0;
	while (i < 4)
	{
		data->hand.frame[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->hand.frame[i].path, &data->hand.frame[i
			].width, &data->hand.frame[i].height);
		if (!data->hand.frame[i].img)
		{
			free_all(data, DESTROY);
			err_exit(XTI_FAIL_MSG);
		}
		i++;
	}
	ft_add_hand(data);
}
