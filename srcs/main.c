#include "so_long.h"


void ft_load_img(t_info_map *data)
{
	int img_hight;
	int img_width;

	data->images = malloc(sizeof(t_images));
	if (!data->images)
		ft_error("not Malloc");
	data->images->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &img_width, &img_hight);
	if (!data->images->player)
		ft_error("failed to load player image");
	data->images->wall = mlx_xpm_file_to_image(data->mlx, WALL, &img_width, &img_hight);
	if (!data->images->wall)
		ft_error("failed to load wall image");
	data->images->empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &img_width, &img_hight);
	if (!data->images->empty)
		ft_error("failed to load empty image");
	data->images->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &img_width, &img_hight);
	if (!data->images->exit)
		ft_error("failed to load exit image");
	data->images->collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &img_width, &img_hight);
	if (!data->images->collect)
		ft_error("failed to load collect image");
	data->images->winner = mlx_xpm_file_to_image(data->mlx, WINNER, &img_width, &img_hight);
	if (!data->images->winner)
		ft_error("failed to load winner image");
}

void	ft_reset_data(t_info_map *data, char *name)
{
	data->hight = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->count = 0;
	data->step = 0;
	data->finish = 0;
	data->txt = name;
	ft_load_img(data);
	ft_successful(" Reset Data");
}

void	ft_general_check(t_info_map *data)
{
	ft_check_outline(data);
	ft_check_format_dotber(data);
	ft_check_map_inputs(data);
	ft_check_map_objects(data);
	ft_check_is_posible(data);
	ft_successful(" General Check");
}

int	ft_frame(t_info_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_draw_map(data);
	if (data->count == 0 && data->player == 1 && data->finish == 1)
		ft_game_result(data);
	return (0);
}


/*
#include <stdio.h>

void	print(t_info_map *data)
{
	int	i;
	
	i = 0;
	while(data->map[i] != NULL)
		printf("%s\n", data->map[i++]);
}
*/

int main(int words, char **args)
{
	t_info_map	data;
	
	if (words == 2)
	{
		data.mlx = mlx_init();
		ft_reset_data(&data, args[1]);
		ft_map_size(&data);
		ft_malloc_map(&data);
		ft_general_check(&data);
		data.win = mlx_new_window(data.mlx, data.width * RES, data.hight * RES, NAME);
		mlx_hook(data.win, 17, 0, ft_exit, &data);
		mlx_key_hook(data.win, ft_press_key, &data);
		mlx_loop_hook(data.mlx, ft_frame, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}