#include "so_long.h"

int get_pixel_color(t_img *img, int x, int y) {
    char    *pixel;
    int     color;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

t_img *ft_extract_frame(t_info *data, sprite_type sprite, int frame_x, int frame_y, int frame_width, int frame_height) {
    t_img *frame;
    int x, y;
    int color;

    // Crear una nueva imagen para el frame
    frame = mlx_new_image(data->mlx, frame_width, frame_height);
    frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel, &frame->line_length, &frame->endian);
    frame->width = frame_width;
    frame->height = frame_height;

    // Copiar los píxeles del spritesheet al frame
    y = 0;
    while (y < frame_height)
    {
        x = 0;
        while (x < frame_width)
        {
            color = get_pixel_color(data->images.spritesheet[sprite], frame_x + x, frame_y + y);
            // Actualizar la imagen del frame directamente
            char *dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
            *(unsigned int *)dst = color;
            x++;
        }
        y++;
    }
    return (frame);
}

int	ft_load_spritesheet(t_info *data, sprite_type sprite, char *spritesheet_path)
{
	int		i;
	int		rows;
	int		frames;

	i = 0;
	data->images.spritesheet[sprite]->img = mlx_xpm_file_to_image(data->mlx, spritesheet_path,
            &data->images.spritesheet[sprite]->width, &data->images.spritesheet[sprite]->height);
	if (!data->images.spritesheet[sprite]->img)
		ft_error("Error loading spritesheet");
	data->images.spritesheet[sprite]->addr = mlx_get_data_addr(data->images.spritesheet[sprite]->img,
			&data->images.spritesheet[sprite]->bits_per_pixel, &data->images.spritesheet[sprite]->line_length,
			&data->images.spritesheet[sprite]->endian);
	while (i < data->spritesheetInfo.total_frames[sprite])
	{
		rows = i / data->spritesheetInfo.frames[sprite];
		frames = i % data->spritesheetInfo.frames[sprite];
		data->images.sprites[sprite][rows][frames] = ft_extract_frame(data, sprite, frames * RES, rows * RES, RES, RES);
		if (!data->images.sprites[sprite][rows][frames])
			ft_error("Error loading frame");
		i++;
	}
	return (i);
}