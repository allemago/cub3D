static void	ft_face(t_data *data, double d_y, double p_x, double p_y)
{
	data->player.dir_y = d_y;
	data->player.plane_x = p_x;
	data->player.plane_y = p_y;
}

static void	ft_set_face(t_data *data)
{
	if (is_c_inset(data->facing, "NSEW"))
	{
		if (data->facing == 'S')
		{
			data->player.dir_x = 0;
			ft_face(data, -1, 0.66, 0);
		}
		else if (data->facing == 'N')
		{
			data->player.dir_x = 0;
			ft_face(data, 1, -0.66, 0);
		}
		else if (data->facing == 'W')
		{
			data->player.dir_x = -1;
			ft_face(data, 0, 0, 0.66);
		}
		else if (data->facing == 'E')
		{
			data->player.dir_x = 1;
			ft_face(data, 0, 0, -0.66);
		}
	}
}
