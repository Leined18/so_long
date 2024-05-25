#include "so_long.h"

void	ft_free_info(t_info *data)
{
	data->running = 0;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img);
	free(data->win);
	free(data->images[0].frames[0]);
	free(data->map);
}
