#include "so_long_bonus.h"

void	ft_animate(t_bonus *data, int direction, int *j, int *i)
{
	static int	frame = 0;
	static int	count = 0;
	int			delay;

	delay = DELAY + DELAY / 2;
	count++;
	if (count == delay)
	{
		count = 0;
		frame++;
		if (data->info.img[data->info_bonus.sprite].frames[direction][frame] == NULL)
			frame = 0;
	}
	data->info.img_ptr = NULL;
	data->info.img_ptr = data->info.img[data->info_bonus.sprite].frames[direction][frame]->img;
	mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
	 data->info.img_ptr, (*j) * RES, (*i) * RES);
}

static void	put_stand_player_img(t_bonus *data, int *j, int *i)
{
	data->info_bonus.sprite = PLAYER;
	if (data->info.player.direction == 'N')
		ft_animate(data, N, j, i);
	else if (data->info.player.direction == 'S')
		ft_animate(data, S, j, i);
	else if (data->info.player.direction == 'E')
		ft_animate(data, E, j, i);
	else if (data->info.player.direction == 'W')
		ft_animate(data, W, j, i);
	data->info.player.y = *i;
	data->info.player.x = *j;
}

void	ft_animation(t_bonus *data)
{
	char tile;
	int y;
	int x;

	y = -1;
	while (data->info.grafics.map[++y])
	{
		x = -1;
		while (data->info.grafics.map[y][++x])
		{
			tile = data->info.grafics.map[y][x];
			if (tile == 'P')
				put_stand_player_img(data, &x, &y);
			if (tile == 'C')
			{
				data->info_bonus.sprite = COLLECT;
				ft_animate(data, 0, &x, &y);
			}
			if (tile == '1')
			{
				data->info_bonus.sprite = WALL;
				ft_animate(data, 0, &x, &y);
			}
			if (tile == 'E')
			{
				data->info_bonus.sprite = EXIT;
				ft_animate(data, 0, &x, &y);
			}
			if (tile == 'X')
			{
				data->info_bonus.sprite = ENEMY;
				ft_animate(data, 0, &x, &y);
			}
		}
	}
}