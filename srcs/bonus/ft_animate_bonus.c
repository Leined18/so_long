/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:05:26 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/14 20:12:02 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animate(t_bonus *data, int d, int *j, int *i)
{
	static int	f = 0;
	static int	count = 0;
	int			delay;

	delay = DELAY + DELAY / 2;
	count++;
	if (count == delay)
	{
		count = 0;
		f++;
		if (data->info.img[data->info2.sprite].frames[d][f] == NULL)
			f = 0;
	}
	data->info.img_ptr = NULL;
	data->info.img_ptr = data->info.img[data->info2.sprite].frames[d][f]->img;
	mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
		data->info.img_ptr, (*j) * RES, (*i) * RES);
}

static void	animate_player_tile(t_bonus *data, int *x, int *y)
{
	data->info2.sprite = PLAYER;
	if (data->info.player.direction == 'N')
		ft_animate(data, N, x, y);
	else if (data->info.player.direction == 'S')
		ft_animate(data, S, x, y);
	else if (data->info.player.direction == 'E')
		ft_animate(data, E, x, y);
	else if (data->info.player.direction == 'W')
		ft_animate(data, W, x, y);
	data->info.player.y = *y;
	data->info.player.x = *x;
}

static void	animate_other_tiles(t_bonus *data, char tile, int *x, int *y)
{
	if (tile == 'C')
	{
		data->info2.sprite = COLLECT;
		ft_animate(data, 0, x, y);
	}
	else if (tile == '1')
	{
		data->info2.sprite = WALL;
		ft_animate(data, 0, x, y);
	}
	else if (tile == 'E')
	{
		data->info2.sprite = EXIT;
		ft_animate(data, data->info2.open, x, y);
	}
	else if (tile == 'X')
	{
		data->info2.sprite = ENEMY;
		ft_animate(data, 0, x, y);
	}
}

void	ft_animation(t_bonus *data)
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
			if (tile == 'P')
				animate_player_tile(data, &x, &y);
			else
				animate_other_tiles(data, tile, &x, &y);
		}
	}
	ft_steps(&data->info);
}
