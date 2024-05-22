#include "so_long.h"

int	ft_exit(t_info *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	ft_free_info(data);
}

void	ft_game_result(t_info *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->images.sprites[WINNER_SPRITE][0][0],
		data->width * RES / 2.2, data->hight * RES / 4);
}