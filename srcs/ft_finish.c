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

static int winner(t_info *data)
{
	if (data->direction == 'N')
		ft_animate(data, WINNER, N, &data->px, &data->py);
	else if (data->direction == 'S')
		ft_animate(data, WINNER, S, &data->px, &data->py);
	else if (data->direction == 'E')
		ft_animate(data, WINNER, E, &data->px, &data->py);
	else if (data->direction == 'W')
		ft_animate(data, WINNER, W, &data->px, &data->py);
	return (0);
}

void	ft_game_result(t_info *data)
{
	int i;
	int j;

	i = (data->width) * RES / 2.2;
	j = (data->hight) * RES / 4;
	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win, i, j, 0x00FF00, "You won!");
	mlx_loop_hook(data->mlx, winner, data);
	
	data->running = 0;
}