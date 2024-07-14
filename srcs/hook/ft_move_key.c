/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/14 19:59:36 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_info *data, int dx, int dy)
{
	if (data->grafics.map[data->player.y + dy][data->player.x + dx] != '1'
		&& data->grafics.map[data->player.y + dy][data->player.x + dx] != 'E')
	{
		if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'C'
			|| data->grafics.map[data->player.y + dy][data->player.x
			+ dx] == '0')
		{
			if (data->grafics.map[data->player.y + dy][data->player.x
				+ dx] == 'C')
				data->player.coins--;
			data->grafics.map[data->player.y][data->player.x] = '0';
			data->grafics.map[data->player.y + dy][data->player.x + dx] = 'P';
		}
		data->player.x += dx;
		data->player.y += dy;
		data->player.step++;
		data->has_changed = 1;
		ft_printf("step : %d\n", data->player.step);
	}
	else if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'E'
		&& data->player.coins == 0)
		data->finish = 1;
}

int	ft_press_key(int keycode, t_info *data)
{
	if (keycode == K_ESC)
		ft_exit(data);
	if (data->finish == 1)
		return (0);
	else if (keycode == K_W || keycode == K_AR_U)
	{
		data->player.direction = 'N';
		move(data, 0, -1);
	}
	else if (keycode == K_S || keycode == K_AR_D)
	{
		data->player.direction = 'S';
		move(data, 0, 1);
	}
	else if (keycode == K_A || keycode == K_AR_L)
	{
		data->player.direction = 'W';
		move(data, -1, 0);
	}
	else if (keycode == K_D || keycode == K_AR_R)
	{
		data->player.direction = 'E';
		move(data, 1, 0);
	}
	return (0);
}
