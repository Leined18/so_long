#include "so_long.h"

void	load1(t_info *data)
{
	int	img_height;
	int	img_width;

	data->images = malloc(sizeof(t_images));
	if (!data->images)
		ft_error("Failed to allocate memory for images");
	data->images->wall = mlx_xpm_file_to_image(data->mlx, WALL, &img_width,
			&img_height);
	if (!data->images->wall)
		ft_error("Failed to load wall image");
	data->images->empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &img_width,
			&img_height);
	if (!data->images->empty)
		ft_error("Failed to load empty image");
	data->images->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &img_width,
			&img_height);
	if (!data->images->exit)
		ft_error("Failed to load exit image");
	data->images->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&img_width, &img_height);
	if (!data->images->collect)
		ft_error("Failed to load collect image");
}

void	load2(t_info *data)
{
	int	img_height;
	int	img_width;

	data->images->p_up = mlx_xpm_file_to_image(data->mlx, PLAYER_UP, &img_width,
			&img_height);
	if (!data->images->p_up)
		ft_error("Failed to load player up image");
	data->images->p_down = mlx_xpm_file_to_image(data->mlx, PLAYER_DOWN,
			&img_width, &img_height);
	if (!data->images->p_down)
		ft_error("Failed to load player down image");
	data->images->p_left = mlx_xpm_file_to_image(data->mlx, PLAYER_LEFT,
			&img_width, &img_height);
	if (!data->images->p_left)
		ft_error("Failed to load player left image");
	data->images->p_right = mlx_xpm_file_to_image(data->mlx, PLAYER_RIGHT,
			&img_width, &img_height);
	if (!data->images->p_right)
		ft_error("Failed to load player right image");
	data->images->winner = mlx_xpm_file_to_image(data->mlx, WINNER, &img_width,
			&img_height);
	if (!data->images->winner)
		ft_error("Failed to load winner image");
}
void	load3(t_info *data)
{
	ft_load_spritesheet(data, PLAYER_SPRITE, PLAYER_SPRITESHEET);
}


void	ft_load_img(t_info *data)
{
	load1(data);
	ft_successful("Images 1 loaded successfully");
	load2(data);
	ft_successful("Images 2 loaded successfully");
	load3(data);
	ft_successful("Images 3 loaded successfully");
}