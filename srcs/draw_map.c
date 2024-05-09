#include "so_long.h"

static void put_wall_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->wall, (*j) * 40, (*i) * 40);
}

static void	put_empty_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->empty, (*j) * 40, (*i) * 40);
}

static void	put_player_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->player, (*j) * 40, (*i) * 40);
	data->y = *i;
	data->x = *j;
}

void	ft_draw_map(t_info_map *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_wall_img(data, &x, &y);
			else if (data->map[y][x] == '0')
				put_empty_img(data, &x, &y);
			else if (data->map[y][x] == 'P')
				put_player_img(data, &x, &y);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->collect, x * 40, y * 40);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, x * 40, y * 40);
			x++;
		}
	y++;
	}
}

void	ft_steps(unsigned int n)
{
	write(1, "Number of steps: ", 17);
	ft_itoa(n);
	write(1, "\n", 1);
}