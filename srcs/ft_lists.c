#include "so_long.h"

void	ft_calculate_spritesheet_info(t_info *data, int frame_width, int frame_height, sprite_type sprite)
{
	int columns;

	if (frame_width == 0 || frame_height == 0)
	{
		data->spritesheetInfo.total_frames[sprite] = 0;
		data->spritesheetInfo.rows[sprite] = 0;
	}
	else
	{
		data->spritesheetInfo.rows[sprite] = data->spritesheetInfo.height[sprite] / frame_height;
		columns = data->spritesheetInfo.width[sprite] / frame_width;
		data->spritesheetInfo.total_frames[sprite] = data->spritesheetInfo.rows[sprite] * columns;
		data->spritesheetInfo.frames[sprite] = columns;
	}
}

int	ft_get_image_dimensions(t_info *data, char *file_path, sprite_type sprite)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	if (data == NULL)
		ft_error("Error: 'data' es NULL.");
	if (data->mlx == NULL)
		ft_error("Error: 'data->mlx' es NULL.");
	if (file_path == NULL)
		ft_error("Error: 'file_path' es NULL.");
	if (w || h)
		ft_error("Error: 'width' o 'height' no han sido inicializados.");
	data->img = mlx_xpm_file_to_image(data->mlx, file_path, &w, &h);
	if (!data->img)
		return (1);
	data->spritesheetInfo.width[sprite] = w;
	data->spritesheetInfo.height[sprite] = h;
	mlx_destroy_image(data->mlx, data->img);
	if (!data->mlx)
		ft_error("Error: mlx_xpm_file_to_image() failed");
	return (0);
}