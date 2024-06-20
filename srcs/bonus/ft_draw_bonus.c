# include "so_long_bonus.h"

static void	put_wall_img(t_bonus *data, int *j, int *i)
{
	mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
		data->info.img[WALL].frames[0][0]->img, (*j) * RES, (*i) * RES);
}

static void	put_empty_img(t_bonus *data, int *j, int *i)
{
	mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
		data->info.img[FIELD].frames[0][0]->img, (*j) * RES, (*i) * RES);
}

static void	put_player_img(t_bonus *data, int *j, int *i)
{
	if (data->info.player.direction == 'N')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[N][0]->img, (*j) * RES, (*i) * RES);
	else if (data->info.player.direction == 'S')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[S][0]->img, (*j) * RES, (*i) * RES);
	else if (data->info.player.direction == 'E')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[E][0]->img, (*j) * RES, (*i) * RES);
	else if (data->info.player.direction == 'W')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[W][0]->img, (*j) * RES, (*i) * RES);
	data->info.player.y = *i;
	data->info.player.x = *j;
}

void	ft_draw_map_bonus(t_bonus *data)
{
	char	tile;
	int		y;
	int		x;

	y = -1;
	while (data->info.grafics.map[++y])
	{
		x = -1;
		while (data->info.grafics.map[y][++x])
		{
			tile = data->info.grafics.map[y][x];
			if (tile == '1')
				put_wall_img(data, &x, &y);
			else if (tile == '0')
				put_empty_img(data, &x, &y);
			else if (tile == 'P')
				put_player_img(data, &x, &y);
			else if (tile == 'C')
				mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
					data->info.img[COLLECT].frames[0][0]->img, x * RES, y * RES);
			else if (tile == 'E')
				mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
					data->info.img[EXIT].frames[0][0]->img, x * RES, y * RES);
            else if (tile == 'X')
                mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
                    data->info.img[ENEMY].frames[0][0]->img, x * RES, y * RES);
		}
	}
}