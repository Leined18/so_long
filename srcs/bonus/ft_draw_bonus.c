/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:13:45 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/08 05:29:08 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw(t_bonus *data, int x, int y, int sprite)
{
	mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
		data->info.img[sprite].frames[0][0]->img, x * RES, y * RES);
}

static void	put_player_img(t_bonus *data, int *j, int *i)
{
	if (data->info.player.direction == 'N')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[UP][0]->img, (*j) * RES, (*i) * RES);
	else if (data->info.player.direction == 'S')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[DOWN][0]->img, (*j) * RES, (*i)
			* RES);
	else if (data->info.player.direction == 'E')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[RIGHT][0]->img, (*j) * RES, (*i)
			* RES);
	else if (data->info.player.direction == 'W')
		mlx_put_image_to_window(data->info.grafics.mlx, data->info.grafics.win,
			data->info.img[PLAYER].frames[LEFT][0]->img, (*j) * RES, (*i)
			* RES);
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
				ft_draw(data, x, y, WALL);
			else if (tile == '0')
				ft_draw(data, x, y, FIELD);
			else if (tile == 'P')
				put_player_img(data, &x, &y);
			else if (tile == 'C')
				ft_draw(data, x, y, COLLECT);
			else if (tile == 'E')
				ft_draw(data, x, y, EXIT);
			else if (tile == 'X')
				ft_draw(data, x, y, ENEMY);
		}
	}
}
