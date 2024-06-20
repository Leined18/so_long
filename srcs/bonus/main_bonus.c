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

static void ft_reset_info(t_info *data, char *name)
{
	int i;
	data->grafics.txt = name;
	data->player.direction = 'S';
	data->has_changed = 1;
	data->running = 1;
	i = -1;
	while (++i < NUMBERS_SPRITE)
		data->img[i].spsh = ft_calloc(1, sizeof(t_img));
	ft_load_img(data);
	ft_successful("Reset Data");
}

int	ft_frame_bonus(t_bonus *data)
{
	if (data->info.player.alive == 0 || (data->info.player.coins == 0 && data->info.finish == 1))
		ft_game_result(&data->info);
	if (data->info.has_changed == 1)
	{
		mlx_clear_window(data->info.grafics.mlx, data->info.grafics.win);
		ft_draw_map_bonus(&data->info);
		data->info.has_changed = 0;
	}
	else if (data->info.player.alive == 1)
		ft_animation(data);
	return (0);
}

void	init_bonus(int argc, char **argv)
{
	t_bonus data;

	ft_printf("\x1b[32mStarting program...\x1b[0m\n");
	if (argc != 2)
		ft_error("Usage: ./program_name map_file");
	ft_bzero(&data, sizeof(t_bonus));
	data.info.grafics.mlx = mlx_init();
	if (!data.info.grafics.mlx)
		ft_error("Error: mlx_init() failed");
	ft_reset_info(&data.info, argv[1]);
	ft_map_size(&data.info);
	ft_malloc_map(&data.info);
	ft_general_check(&data.info);
	data.info.grafics.win = mlx_new_window(data.info.grafics.mlx, data.info.grafics.width
			* RES, data.info.grafics.height * RES, NAME_B);
	if (!data.info.grafics.win)
		ft_error("Error: mlx_new_window() failed");
	mlx_hook(data.info.grafics.win, 17, 0, ft_exit, &data.info);
	mlx_key_hook(data.info.grafics.win, ft_press_key, &data.info);
	mlx_loop_hook(data.info.grafics.mlx, ft_frame_bonus, &data);
	mlx_loop(data.info.grafics.mlx);
}