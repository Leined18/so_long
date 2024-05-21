#include "so_long.h"

static void	put_wall_img(t_info *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->wall, (*j)
		* RES, (*i) * RES);
}

static void	put_empty_img(t_info *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->images->empty, (*j)
		* RES, (*i) * RES);
}

static void	put_player_img(t_info *data, int *j, int *i)
{
	if (data->direction == 'N')
		mlx_put_image_to_window(data->mlx, data->win, data->images->p_up, (*j)
			* RES, (*i) * RES);
	else if (data->direction == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->images->p_down, (*j)
			* RES, (*i) * RES);
	else if (data->direction == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->images->p_right,
			(*j) * RES, (*i) * RES);
	else if (data->direction == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->images->p_left, (*j)
			* RES, (*i) * RES);
	data->y = *i;
	data->x = *j;
}
void	ft_draw_map(t_info *data)
{
	char	tile;
	int		y;
	int		x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			tile = data->map[y][x];
			if (tile == '1')
				put_wall_img(data, &x, &y);
			else if (tile == '0')
				put_empty_img(data, &x, &y);
			else if (tile == 'P')
				put_player_img(data, &x, &y);
			else if (tile == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->collect, x * RES, y * RES);
			else if (tile == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, x * RES, y * RES);
			x++;
		}
		y++;
	}
}

void	ft_steps(unsigned int n)
{
	char	*num_str;

	write(1, "Number of steps: ", 17);
	num_str = ft_itoa(n);
	if (num_str)
	{
		write(1, num_str, ft_strlen(num_str));
		free(num_str);
	}
	write(1, "\n", 1);
}
