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
				data->count--;
			data->map[data->py][data->px] = '0';
			data->map[data->py + dy][data->px + dx] = 'P';
		}
		data->px += dx;
		data->py += dy;
		data->step++;
		data->has_changed = 1;
		ft_steps(data->step);
	}
	else if (data->map[data->py + dy][data->px + dx] == 'E' && data->count == 0)
		data->finish = 1;
}

int	ft_press_key(int keycode, t_info *data)
{
	if (data->finish == 1)
		return (0);
	if (keycode == K_ESC)
		ft_exit(data);
	else if (keycode == K_W || keycode == K_AR_U)
	{
		data->direction = 'N'; // Set direction to 'W'
		move(data, 0, -1);     // W or Up arrow key
	}
	else if (keycode == K_S || keycode == K_AR_D)
	{
		data->direction = 'S'; // Set direction to 'S'
		move(data, 0, 1);      // S or Down arrow key
	}
	else if (keycode == K_A || keycode == K_AR_L)
	{
		data->direction = 'W';
		move(data, -1, 0);
	}
	else if (keycode == K_D || keycode == K_AR_R)
	{
		data->direction = 'E'; // Set direction to 'D'
		move(data, 1, 0);      // D or Right arrow key
	}
	return (0);
}
