/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:13:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/14 20:00:24 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw(t_info *data, int x, int y, int sprite)
{
	mlx_put_image_to_window(data->grafics.mlx, data->grafics.win,
		data->img[sprite].frames[0][0]->img, x * RES, y * RES);
}

static void	put_player_img(t_info *data, int *j, int *i)
{
	if (data->player.direction == 'N')
		mlx_put_image_to_window(data->grafics.mlx, data->grafics.win,
			data->img[PLAYER].frames[N][0]->img, (*j) * RES, (*i) * RES);
	else if (data->player.direction == 'S')
		mlx_put_image_to_window(data->grafics.mlx, data->grafics.win,
			data->img[PLAYER].frames[S][0]->img, (*j) * RES, (*i) * RES);
	else if (data->player.direction == 'E')
		mlx_put_image_to_window(data->grafics.mlx, data->grafics.win,
			data->img[PLAYER].frames[E][0]->img, (*j) * RES, (*i) * RES);
	else if (data->player.direction == 'W')
		mlx_put_image_to_window(data->grafics.mlx, data->grafics.win,
			data->img[PLAYER].frames[W][0]->img, (*j) * RES, (*i) * RES);
	data->player.y = *i;
	data->player.x = *j;
}

void	ft_draw_map(t_info *data)
{
	char	tile;
	int		y;
	int		x;

	y = -1;
	while (data->grafics.map[++y])
	{
		x = -1;
		while (data->grafics.map[y][++x])
		{
			tile = data->grafics.map[y][x];
			if (tile == '1')
				ft_draw(data, x, y, WALL);
			else if (tile == '0')
				ft_draw(data, x, y, FIELD);
			else if (tile == 'P')
				put_player_img(data, &x, &y);
			else if (tile == 'C')
				ft_draw(data, x, y, COLLECT);
			else if (tile == 'E')
				mlx_put_image_to_window(data->grafics.mlx, data->grafics.win,
					data->img[EXIT].frames[data->player.open][0]->img, x * RES,
					y * RES);
		}
	}
}

void	ft_steps(t_info *data)
{
	char	*num_str;

	num_str = ft_itoa(data->player.step);
	mlx_string_put(data->grafics.mlx, data->grafics.win, 35, 35, 0x00FF0066,
		num_str);
	free(num_str);
}
