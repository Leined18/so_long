/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:06:39 by danpalac          #+#    #+#             */
/*   Updated: 2024/07/08 05:28:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_checkmove(t_info *data, int dx, int dy)
{
	if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'E'
		&& data->player.coins == 0)
		data->finish = 1;
	else if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'X'
		&& data->player.alive == 1)
	{
		data->player.alive = 0;
		data->finish = 1;
	}
}

static void	move_bonus(t_info *data, int dx, int dy)
{
	if (data->grafics.map[data->player.y + dy][data->player.x + dx] != '1'
		&& data->grafics.map[data->player.y + dy][data->player.x + dx] != 'E'
		&& data->grafics.map[data->player.y + dy][data->player.x + dx] != 'X')
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
		ft_steps(data);
	}
	else
		ft_checkmove(data, dx, dy);
}

int	ft_press_key_bonus(int keycode, t_bonus *data)
{
	if (keycode == K_ESC)
		ft_exit(&data->info);
	if (data->info.finish == 1)
		return (0);
	else if (keycode == K_W || keycode == K_AR_U)
	{
		data->info.player.direction = 'N';
		move_bonus(&data->info, 0, -1);
	}
	else if (keycode == K_S || keycode == K_AR_D)
	{
		data->info.player.direction = 'S';
		move_bonus(&data->info, 0, 1);
	}
	else if (keycode == K_A || keycode == K_AR_L)
	{
		data->info.player.direction = 'W';
		move_bonus(&data->info, -1, 0);
	}
	else if (keycode == K_D || keycode == K_AR_R)
	{
		data->info.player.direction = 'E';
		move_bonus(&data->info, 1, 0);
	}
	return (0);
}
