/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:14:42 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 11:26:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_animate(t_info *data, sprite_type sprite, int direction, int *j,
		int *i)
{
	static int	frame;
	static int	count;
	int			delay;

	frame = 0;
	count = 0;
	delay = DELAY * 3;
	count++;
	if (count == delay)
	{
		count = 0;
		frame++;
		if (data->img[sprite].frames[direction][frame] == NULL)
			frame = 0;
	}
	data->img_ptr = NULL;
	data->img_ptr = data->img[sprite].frames[direction][frame]->img;
	mlx_put_image_to_window(data->mlx, data->win, data->img, (*j) * RES, (*i)
		* RES);
}

static void	put_stand_player_img(t_info *data, int *j, int *i)
{
	if (data->direction == 'N')
		ft_animate(data, PLAYER, N, j, i);
	else if (data->direction == 'S')
		ft_animate(data, PLAYER, S, j, i);
	else if (data->direction == 'E')
		ft_animate(data, PLAYER, E, j, i);
	else if (data->direction == 'W')
		ft_animate(data, PLAYER, W, j, i);
	data->py = *i;
	data->px = *j;
}

static int	winner(t_info *data)
{
	if (data->direction == 'N')
		ft_animate(data, WINNER, UP, &data->px, &data->py);
	else if (data->direction == 'S')
		ft_animate(data, WINNER, DOWN, &data->px, &data->py);
	else if (data->direction == 'E')
		ft_animate(data, WINNER, RIGHT, &data->px, &data->py);
	else if (data->direction == 'W')
		ft_animate(data, WINNER, LEFT, &data->px, &data->py);
	return (0);
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
			if (tile == 'E')
				ft_animate(data, EXIT, 0, &x, &y);
		}
	}
}
