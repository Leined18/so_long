#include "so_long.h"

int	ft_exit(t_info *data)
{
	ft_free_info(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

void	ft_exit_error(t_info *data, char *err)
{
	ft_putstr_fd("\x1b[31mError\x1b[0m\n", 2);
	if (err && *err)
	{
		ft_putstr_fd(err, 2);
		write(2, "\n", 1);
	}
	ft_free_info(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_FAILURE);
}

void	ft_game_result(t_info *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->running = 0;
	mlx_put_image_to_window(data->mlx, data->win,
		data->images[WINNER].frames[0][0]->img, data->width * RES / 2.2,
		data->hight * RES / 4);
}