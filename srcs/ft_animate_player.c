#include "so_long.h"

static void	ft_animate(t_info *data, int direction, int *j, int *i)
{
	static int	frame = 0;
	static int	count = 0;

	count++;
	if (count == DELAY)
	{
		count = 0;
		frame++;
		// Reinicia el frame a 0 si encuentra un frame nulo
		if (data->images[PLAYER].frames[direction][frame] == NULL)
		{
			frame = 0;
		}
	}
	data->img = NULL;
	data->img = data->images[PLAYER].frames[direction][frame]->img;
	mlx_put_image_to_window(data->mlx, data->win, data->img, (*j) * RES, (*i) * RES);
}


void	put_stand_player_img(t_info *data, int *j, int *i)
{
	// Llama a ft_animate_player con la dirección adecuada
	if (data->direction == 'N')
		ft_animate(data, N, j, i);
	else if (data->direction == 'S')
		ft_animate(data, S, j, i);
	else if (data->direction == 'E')
		ft_animate(data, E, j, i);
	else if (data->direction == 'W')
		ft_animate(data, W, j, i);
	data->py = *i;
	data->px = *j;
}


void	ft_animate_player(t_info *data)
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
		}
	}
}
