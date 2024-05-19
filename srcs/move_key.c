#include "so_long.h"

void	move(t_info *data, int dx, int dy)
{
	if (data->map[data->y + dy][data->x + dx] != '1'
		&& data->map[data->y + dy][data->x + dx] != 'E')
	{
		if (data->map[data->y + dy][data->x + dx] == 'C'
			|| data->map[data->y + dy][data->x + dx] == '0')
		{
			if (data->map[data->y + dy][data->x + dx] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y + dy][data->x + dx] = 'P';
		}
		data->x += dx;
		data->y += dy;
		data->step++;
		data->has_changed = 1;
		ft_steps(data->step);
	}
	else if (data->map[data->y + dy][data->x + dx] == 'E'
		&& data->count == 0)
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
		move(data, 0, -1); // W or Up arrow key
	}
	else if (keycode == K_S || keycode == K_AR_D)
	{
		data->direction = 'S'; // Set direction to 'S'
		move(data, 0, 1); // S or Down arrow key
	}
	else if (keycode == K_A || keycode == K_AR_L)
	{
		data->direction = 'W';
		move(data, -1, 0);
	}
	else if (keycode == K_E || keycode == K_AR_R)
	{
		data->direction = 'E'; // Set direction to 'D'
		move(data, 1, 0); // D or Right arrow key
	}
	return (0);
}
