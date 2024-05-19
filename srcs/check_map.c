#include "so_long.h"

void	ft_check_outline(t_info *data)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->hight - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
		ft_error("Map outline bad");
}

void	ft_check_format_dotber(t_info *data)
{
	if (ft_strrncmp(data->txt, ".ber", 4))
		ft_error("Bad extension");
}

void	ft_check_map_inputs(t_info *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0'
				&& data->map[y][x] != 'C' && data->map[y][x] != 'P'
				&& data->map[y][x] != 'E')
				ft_error("Bad map input");
			else
			x++;
		}
		y++;
	}
}

void	ft_check_map_objects(t_info *data)
{
	int	y;
	int	x;
	int	end;

	end = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'P')
				data->player++;
			if (data->map[y][x] == 'C')
				data->count++;
			if (data->map[y][x] == 'E')
				end++;
		}
	}
	if (data->player != 1 || data->count < 1 || end != 1)
		ft_error("Bad map inputs");
}
void	ft_check_is_posible(t_info *data)
{
	int	i[2];
	int	j[2];
	int	left;

	left = 0;
	i[0] = -1;
	while (data->map[++i[0]]) // { 0, 0, 0}
	{
		i[1] = -1; // { 0, -1}
		while (data->map[i[0]][++i[1]]) // { "111111", "100000001", 111111 }
		{
			if (data->map[i[0]][i[1]] == 'P') //  [i[0] == 0][i[1] == 0] 
			{
				j[0] = i[0]; //j[0] == 0 
				j[1] = i[1]; //j[1] == 0
			}
			if (data->map[i[0]][i[1]] == 'E' || data->map[i[0]][i[1]] == 'C')
				left++;
		}
	}
	ft_is_posible(data, j[0], j[1], left);
}