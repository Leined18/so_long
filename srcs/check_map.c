#include "so_long.h"

void	ft_check_outline(t_info_map *data)
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
	{
		write(2, "Error\nMap outline bad\n", 23);
		exit (EXIT_FAILURE);
	}
}