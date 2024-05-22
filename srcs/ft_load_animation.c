#include "so_long.h"

static void	copy_pixels(char *src_data, char *dest_data, int x, int y,
		int width, int height, int size_line)
{
	int	j;
	char	*src_ptr;
	char	*dest_ptr;

	src_data += y * size_line + x * 4;
	dest_data += y * width * 4;
	j = 0;
	while (j < height)
	{
		src_ptr = src_data;
		dest_ptr = dest_data;
		int i = 0;
		while (i < width)
		{
			*(int*)dest_ptr = *(int*)src_ptr;
			src_ptr += 4;
			dest_ptr += 4;
			i++;
		}
		src_data += size_line;
		dest_data += width * 4;
		j++;
	}
}


static void	*extract_frame(void *mlx, void *spritesheet, int x, int y,
		int width, int height)
{
	void	*sprite;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	char	*sprite_data;

	data = mlx_get_data_addr(spritesheet, &bpp, &size_line, &endian);
	if (!data)
		ft_error("Error obteniendo data address del spritesheet");
	sprite = mlx_new_image(mlx, width, height);
	if (!sprite)
		ft_error("Error creando nueva imagen para el sprite");
	sprite_data = mlx_get_data_addr(sprite, &bpp, &size_line, &endian);
	if (!sprite_data)
		ft_error("Error obteniendo data address del sprite");
	copy_pixels(data, sprite_data, x, y, width, height, size_line);
	return (sprite);
}

static void	put_frames(t_info *data, sprite_type sprite, int frame_width, int frame_height)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < data->spritesheetInfo.rows[sprite])
	{
		j = 0;
		while (j < data->spritesheetInfo.frames[sprite])
		{
			data->images.sprites[sprite][i][j] = extract_frame(data->mlx,
					data->images.spritesheet[sprite], j * frame_width, i
					* frame_height, frame_width, frame_height);
			if (!data->images.sprites[sprite][i][j])
				ft_error("Error extrayendo frame");
			j++;
		}
		i++;
	}
}

void	ft_load_spritesheet(t_info *data, sprite_type sprite,
		char *spritesheet_path)
{
	int	img_width;
	int	img_height;

	data->images.spritesheet[sprite] = mlx_xpm_file_to_image(data->mlx,
			spritesheet_path, &img_width, &img_height);
	if (!data->images.spritesheet[sprite])
		ft_error("Error cargando el spritesheet");
	if (sprite == PLAYER_SPRITE || sprite == COLLECT_SPRITE || sprite == FIELD_SPRITE ||
    sprite == EXIT_SPRITE || sprite == WALL_SPRITE || sprite == WINNER_SPRITE)
	{
    	if (data->spritesheetInfo.frames[sprite] > 0 && data->spritesheetInfo.rows[sprite] > 0)
        	put_frames(data, sprite, img_width / data->spritesheetInfo.frames[sprite], img_height / data->spritesheetInfo.rows[sprite]);
    }
	else
        ft_error("Error en put_frames");
}
