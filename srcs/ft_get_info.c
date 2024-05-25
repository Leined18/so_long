#include "so_long.h"

void	ft_calculate_spritesheet_info(t_info *data, int frame_width,
		int frame_height, sprite_type sprite)
{
	int	columns;

	if (frame_width == 0 || frame_height == 0)
	{
		data->s_info.total_frames[sprite] = 0;
		data->s_info.rows[sprite] = 0;
	}
	else
	{
		data->s_info.rows[sprite] = data->s_info.height[sprite] / frame_height;
		columns = data->s_info.width[sprite] / frame_width;
		data->s_info.total_frames[sprite] = data->s_info.rows[sprite] * columns;
		data->s_info.frames[sprite] = columns;
	}
}

int	ft_get_s_sheet_img(t_info *data, char *path, sprite_type sprite)
{
	data->images[sprite].spritesheet->img = mlx_xpm_file_to_image(data->mlx,
			path, &data->s_info.width[sprite], &data->s_info.height[sprite]);
	if (!data->images[sprite].spritesheet->img)
		return (1);
	data->images[sprite].spritesheet->addr = mlx_get_data_addr(data->images[sprite].spritesheet->img,
			&data->images[sprite].spritesheet->bits_per_pixel,
			&data->images[sprite].spritesheet->line_length,
			&data->images[sprite].spritesheet->endian);
	return (0);
}
