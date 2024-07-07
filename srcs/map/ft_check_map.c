/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:15:37 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/07 22:58:48 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_outline(t_info *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < data->grafics.width)
	{
		if (data->grafics.map[0][i] != '1'
			|| data->grafics.map[data->grafics.height - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < data->grafics.height)
	{
		if (data->grafics.map[i][0] != '1'
			|| data->grafics.map[i][data->grafics.width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
		ft_error("Map outline bad");
}

void	ft_check_format_dotber(t_info *data)
{
	if (ft_strrncmp(data->grafics.txt, ".ber", 4))
		ft_error("Bad extension");
}

void	ft_check_map_inputs(t_info *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->grafics.map[y])
	{
		x = 0;
		while (data->grafics.map[y][x])
		{
			if (data->grafics.map[y][x] != '1' && data->grafics.map[y][x] != '0'
				&& data->grafics.map[y][x] != 'C'
				&& data->grafics.map[y][x] != 'P'
				&& data->grafics.map[y][x] != 'E')
				ft_error("Bad map input");
			else
				x++;
		}
		y++;
	}
}

void	ft_check_map_objects(t_info *data)
{
	int	y;
	int	x;
	int	end;

	end = 0;
	y = -1;
	while (data->grafics.map[++y])
	{
		x = -1;
		while (data->grafics.map[y][++x])
		{
			if (data->grafics.map[y][x] == 'P')
				data->player.alive++;
			if (data->grafics.map[y][x] == 'C')
				data->player.coins++;
			if (data->grafics.map[y][x] == 'E')
				end++;
		}
	}
	if (data->player.alive != 1 || data->player.coins < 1 || end != 1)
		ft_error("Bad map inputs");
}

void	ft_check_is_posible(t_info *data)
{
	int	i[2];
	int	j[2];
	int	left;

	left = 0;
	i[0] = -1;
	while (data->grafics.map[++i[0]])
	{
		i[1] = -1;
		while (data->grafics.map[i[0]][++i[1]])
		{
			if (data->grafics.map[i[0]][i[1]] == 'P')
			{
				j[0] = i[0];
				j[1] = i[1];
			}
			if (data->grafics.map[i[0]][i[1]] == 'E'
				|| data->grafics.map[i[0]][i[1]] == 'C')
				left++;
		}
	}
	ft_is_posible(data, j[0], j[1], left);
}
