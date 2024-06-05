/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:56:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/06/05 10:58:38 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_info *data, int dx, int dy)
{
	if (data->map[data->py + dy][data->px + dx] != '1' && data->map[data->py
		+ dy][data->px + dx] != 'E')
	{
		if (data->map[data->py + dy][data->px + dx] == 'C' || data->map[data->py
			+ dy][data->px + dx] == '0')
		{
			if (data->map[data->py + dy][data->px + dx] == 'C')
				data->coins--;
			data->map[data->py][data->px] = '0';
			data->map[data->py + dy][data->px + dx] = 'P';
		}
		data->px += dx;
		data->py += dy;
		data->step++;
		data->has_changed = 1;
		ft_steps(data->step);
	}
	else if (data->map[data->py + dy][data->px + dx] == 'E' && data->coins == 0)
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
		data->direction = 'N';
		move(data, 0, -1);
	}
	else if (keycode == K_S || keycode == K_AR_D)
	{
		data->direction = 'S';
		move(data, 0, 1);
	}
	else if (keycode == K_A || keycode == K_AR_L)
	{
		data->direction = 'W';
		move(data, -1, 0);
	}
	else if (keycode == K_D || keycode == K_AR_R)
	{
		data->direction = 'E';
		move(data, 1, 0);
	}
	return (0);
}
