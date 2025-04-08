#include "../../include/cub3D.h"

int	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	if (data->img[i].img)
	{
		destroy_texture(data, data->img, 0, 1);
		destroy_texture(data, data->img, 0, 1);
		free_ptr((void **)&data->img);
		i++;
	}
	if (data->assets)
		free_assets(data);
	if (data->window)
		mlx_destroy_window(data->mlx_ptr, data->window);
	// mlx_loop_end(data->mlx_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	// ne pas liberer manuellement mlx_ptr, destroy_display s'en occupe
	free_all(data);
	exit(EXIT_SUCCESS);
}

int	ft_loop(t_data *data)
{
	ft_draw_background(data);
	ft_raycasting(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[4].img, 0,
		0);
	return (0);
}

void	ft_events_mlx(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
	mlx_loop(data->mlx_ptr);
}
