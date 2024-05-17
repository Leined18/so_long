#include "so_long.h"

static void put_wall_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->wall, (*j) * RES, (*i) * RES);
}

static void	put_empty_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->empty, (*j) * RES, (*i) * RES);
}

static void	put_player_img(t_info_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->player, (*j) * RES, (*i) * RES);
	data->y = *i;
	data->x = *j;
}
void ft_draw_map(t_info_map *data)
{
	char    tile;
    int     y;
    int     x;   
    
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
				mlx_put_image_to_window(data->mlx, data->win, data->images->collect, x * RES, y * RES);
			else if (tile == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->images->exit, x * RES, y * RES);
			x++;
		}
		y++;
	}
}

void	ft_steps(unsigned int n)
{
	write(1, "Number of steps: ", 17);
	ft_itoa(n);
	write(1, "\n", 1);
}