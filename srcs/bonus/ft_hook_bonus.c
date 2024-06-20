# include "so_long_bonus.h"

int	move_enemy(t_bonus *data, int dx, int dy)
{
	if (data->info.grafics.map[data->enemy.y + dy][data->enemy.x + dx] != '1' && data->info.grafics.map[data->enemy.y
		+ dy][data->enemy.x + dx] != 'E' && data->info.grafics.map[data->enemy.y + dy][data->enemy.x + dx] != 'X')
	{
		if (data->info.grafics.map[data->enemy.y + dy][data->enemy.x + dx] == 'C' || data->info.grafics.map[data->enemy.y
			+ dy][data->enemy.x + dx] == '0')
		{
			data->info.grafics.map[data->enemy.y][data->enemy.x] = '0';
			data->info.grafics.map[data->enemy.y + dy][data->enemy.x + dx] = 'X';
		}
		data->enemy.x += dx;
		data->enemy.y += dy;
		data->info.has_changed = 1;
		return 1;
	}
	return 0;
}

int	move_enemy_loop(t_bonus *data)
{
	if (move_enemy(data, 0, -1) == 0) // Intentar mover al enemigo al norte
		return 0;
	else if (move_enemy(data, 0, 1) == 0) // Intentar mover al enemigo al sur
		return 0;
	else if (move_enemy(data, -1, 0) == 0) // Intentar mover al enemigo al oeste
		return 0;
	else if (move_enemy(data, 1, 0) == 0) // Intentar mover al enemigo al este
		return 0;
	else
		return 1; // No se pudo mover en ninguna dirección
}

void	move_bonus(t_info *data, int dx, int dy)
{
	if (data->grafics.map[data->player.y + dy][data->player.x + dx] != '1' && data->grafics.map[data->player.y
		+ dy][data->player.x + dx] != 'E' && data->grafics.map[data->player.y + dy][data->player.x + dx] != 'X')
	{
		if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'C' || data->grafics.map[data->player.y
			+ dy][data->player.x + dx] == '0')
		{
			if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'C')
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
	else if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'E' && data->player.coins == 0)
		data->finish = 1;
    else if (data->grafics.map[data->player.y + dy][data->player.x + dx] == 'X' && data->player.alive == 1)
		data->player.alive = 0;
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