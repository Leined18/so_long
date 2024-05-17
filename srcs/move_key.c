#include "so_long.h"

void	move_w(t_info_map *data)
{
	if (data->map[data->y - 1][data->x] != '1'
		&& data->map[data->y - 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == 'C'
				|| data->map[data->y - 1][data->x] == '0')
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		data->y--;
		data->step++;
		ft_steps(data->step);
	}
	else if (data->map[data->y - 1][data->x] == 'E'
		&& data->count == 0)
		data->finish = 1;
}

void	move_s(t_info_map *data)
{
	if (data->map[data->y + 1][data->x] != '1'
		&& data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == 'C'
				|| data->map[data->y + 1][data->x] == '0')
		{
			if (data->map[data->y + 1][data->x] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		data->y++;
		data->step++;
		ft_steps(data->step);
	}
	else if (data->map[data->y + 1][data->x] == 'E'
		&& data->count == 0)
		data->finish = 1;
}

void	move_a(t_info_map *data)
{
	if (data->map[data->y][data->x - 1] != '1'
		&& data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == 'C'
				|| data->map[data->y][data->x - 1] == '0')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		data->x--;
		data->step++;
		ft_steps(data->step);
	}
	else if (data->map[data->y][data->x - 1] == 'E'
		&& data->count == 0)
		data->finish = 1;
}

void	move_d(t_info_map *data)
{
	if (data->map[data->y][data->x + 1] != '1'
		&& data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == 'C'
				|| data->map[data->y][data->x + 1] == '0')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->count--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		data->x++;
		data->step++;
		ft_steps(data->step);
	}
	else if (data->map[data->y][data->x + 1] == 'E'
		&& data->count == 0)
		data->finish = 1;
}

int	ft_press_key(int keycode, t_info_map *data)
{
	if (keycode == K_ESC)
		ft_exit(data);
	else if ((keycode == K_W || keycode == K_AR_U) && data->finish == 0)
		move_w(data);
	else if ((keycode == K_S || keycode == K_AR_D) && data->finish == 0)
		move_s(data);
	else if ((keycode == K_A || keycode == K_AR_L) && data->finish == 0)
		move_a(data);
	else if ((keycode == K_D || keycode == K_AR_R) && data->finish == 0)
		move_d(data);
	return (0);
}