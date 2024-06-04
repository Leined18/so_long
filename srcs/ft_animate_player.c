#include "so_long.h"

void	ft_animate(t_info *data, sprite_type sprite, int direction, int *j, int *i)
{
	static int	frame = 0;
	static int	count = 0;
	int delay;
	
	delay = DELAY + DELAY / 2;
	count++;
	if (count == delay)
	{
		count = 0;
		frame++;
		if (data->images[sprite].frames[direction][frame] == NULL)
			frame = 0;
	}
	data->img = NULL;
	data->img = data->images[sprite].frames[direction][frame]->img;
	mlx_put_image_to_window(data->mlx, data->win, data->img, (*j) * RES, (*i) * RES);
}


static void	put_stand_player_img(t_info *data, int *j, int *i)
{
	// Llama a ft_animate_player con la dirección adecuada
	if (data->direction == 'N')
		ft_animate(data,PLAYER, N, j, i);
	else if (data->direction == 'S')
		ft_animate(data,PLAYER, S, j, i);
	else if (data->direction == 'E')
		ft_animate(data,PLAYER, E, j, i);
	else if (data->direction == 'W')
		ft_animate(data,PLAYER, W, j, i);
	data->py = *i;
	data->px = *j;
}

void	ft_animation(t_info *data)
{
	char	tile;
	int		y;
	int		x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			tile = data->map[y][x];
			if (tile == 'P')
				put_stand_player_img(data, &x, &y);
			if (tile == 'C')
				ft_animate(data, COLLECT, 0, &x, &y);
			if (tile == '1')
				ft_animate(data, WALL, 0, &x, &y);
		}
	}
}
