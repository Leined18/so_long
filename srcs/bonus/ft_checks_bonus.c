/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:15:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/08 05:25:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_inputs_bonus(t_bonus *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->info.grafics.map[y])
	{
		x = 0;
		while (data->info.grafics.map[y][x])
		{
			if (data->info.grafics.map[y][x] != '1'
				&& data->info.grafics.map[y][x] != '0'
				&& data->info.grafics.map[y][x] != 'C'
				&& data->info.grafics.map[y][x] != 'P'
				&& data->info.grafics.map[y][x] != 'E'
				&& data->info.grafics.map[y][x] != 'X')
				ft_error("Bad map input");
			else
				x++;
		}
		y++;
	}
}

void	ft_check_map_objects_bonus(t_bonus *data)
{
	int	y;
	int	x;
	int	end;

	end = 0;
	y = -1;
	while (data->info.grafics.map[++y])
	{
		x = -1;
		while (data->info.grafics.map[y][++x])
		{
			if (data->info.grafics.map[y][x] == 'P')
				data->info.player.alive++;
			if (data->info.grafics.map[y][x] == 'C')
				data->info.player.coins++;
			if (data->info.grafics.map[y][x] == 'E')
				end++;
			if (data->info.grafics.map[y][x] == 'X')
				data->info2.enemy.alive++;
		}
	}
	if (data->info.player.alive != 1 || data->info.player.coins < 1 || end != 1
		|| data->info2.enemy.alive < 1)
		ft_error("Bad map inputs");
}
