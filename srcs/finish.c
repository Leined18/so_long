#include "so_long.h"

int	ft_exit(t_info_map *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

void	ft_game_result(t_info_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->images->winner,
		data->width * RES / 2.4, data->hight * RES / 4);
}