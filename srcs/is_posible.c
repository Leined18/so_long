# include "so_long.h"

void	malloc_and_fill(t_checker *c, t_info *data)
{
	int	y;
	int	x;

	c->map = malloc(sizeof(int *) * data->hight);
	y = -1;
	while (++y < data->hight)
		c->map[y] = malloc(sizeof(int *) * data->width);
	y = -1;
	while (++y < data->hight)
	{
		x = -1;
		while (++x < data->width)
			c->map[y][x] = 0;
	}
}

void	iter_checker(t_checker *c, t_info *data, int i, int j)
{
	if (c->coins_left == 0)
		return ;
	if (c->map[i][j] == 0 && data->map[i][j] != '1')
	{
		c->map[i][j] = 1;
		if (data->map[i][j] == 'C' || data->map[i][j] == 'E')
			c->coins_left--;
		if (data->map[i][j] == 'E')
			return ;
		iter_checker(c, data, i + 1, j);
		iter_checker(c, data, i - 1, j);
		iter_checker(c, data, i, j + 1);
		iter_checker(c, data, i, j - 1);
	}
}

void	free_checker(t_checker *c, int hight)
{
	int	i;

	i = -1;
	while (++i < hight)
		free(c->map[i]);
	free(c->map);
	c->map = NULL;
}

void	ft_is_posible(t_info *data, int j, int i, int left)
{
	t_checker	c;

	c.coins_left = left;
	malloc_and_fill(&c, data);
	iter_checker(&c, data, j, i);
	if (c.coins_left != 0)
        ft_error("Map is imposible");
	free_checker(&c, data->hight);
}