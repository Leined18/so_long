#include "so_long_bonus.h"


/*
#include <stdio.h>

void	print(t_info *data)
{
	int	i;

	i = 0;
	while(data->map[i] != NULL)
		printf("%s\n", data->map[i++]);
}
*/



void	init_bonus(int argc, char **argv)
{
	t_bonus data;

	ft_printf("\x1b[32mStarting program...\x1b[0m\n");
	if (argc != 2)
		ft_error("Usage: ./program_name map_file");
	ft_bzero(&data, sizeof(t_bonus));
	data.grafics.mlx = mlx_init(data);
	if (!data.grafics.mlx)
		ft_error("Error: mlx_init() failed");
	data.arg = argv[1];
	data.grafics.win = mlx_new_window(data.grafics.mlx, data.grafics.width
			* RES, data.grafics.height * RES, NAME);
	if (!data.grafics.win)
		ft_error("Error: mlx_new_window() failed");
	mlx_hook(data.grafics.win, 17, 0, ft_exit, &data);
	mlx_loop(data.grafics.mlx);
}