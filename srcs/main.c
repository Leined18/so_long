#include "so_long.h"

void	ft_load_img(t_info_map *data)
{
	int	img_hight;
	int	img_width;

	data->images = malloc(sizeof(t_images));
	data->images->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &img_width, &img_hight);
	data->images->wall = mlx_xpm_file_to_image(data->mlx, WALL, &img_width, &img_hight);
	data->images->empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &img_width, &img_hight);
	data->images->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &img_width, &img_hight);
	data->images->collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &img_width, &img_hight);
	data->images->winner = mlx_xpm_file_to_image(data->mlx, WINNER, &img_width, &img_hight);
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
}

int main(int words, char **args)
{
    t_info_map	data;
    
    if (words == 2)
    {
        data.mlx = mlx_init();
        ft_reset_data(&data, args[1]);
        ft_map_size(&data);
        ft_malloc_map(&data);
		data.win = mlx_new_window(data.mlx, data.width * 40, data.hight * 40, NAME);
		mlx_loop(data.mlx);
    }
    return (0);
}