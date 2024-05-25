#include "so_long.h"

static int get_pixel_color(t_img *img, int x, int y)
{
    char    *pixel;
    unsigned int    color;

    color = 0;
    pixel = NULL;
    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    color = *(unsigned int *)pixel;
    return (color);
}

static t_img *ft_extract_frame(t_info *data, sprite_type sprite, int frame_x, int frame_y, int frame_width, int frame_height)
{
    t_img *frame;
    int x, y;
    unsigned int color;
    char *dst;

    color = 0;
    dst = NULL;
    frame = malloc(sizeof(t_img));
    frame->img = mlx_new_image(data->mlx, frame_width, frame_height);
    frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel, &frame->line_length, &frame->endian);
    data->images.img[sprite]->addr = mlx_get_data_addr(data->images.spritesheet[sprite], &data->images.img[sprite]->bits_per_pixel, &data->images.img[sprite]->line_length, &data->images.img[sprite]->endian);
    y = -1;
    while (++y < frame_height)
    {
        x = -1;
        while (++x < frame_width)
        {
            color = get_pixel_color(data->images.img[sprite], frame_x + x, frame_y + y);
            dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
            *(unsigned int *)dst = color;
        }
    }
    return (frame);
}

int	ft_load_spritesheet(t_info *data, sprite_type sprite, char *spritesheet_path)
{
	int		i;
    int    rows;
    int    frames;

	i = 0;
	data->images.spritesheet[sprite] = mlx_xpm_file_to_image(data->mlx, spritesheet_path, &data->spritesheetInfo.width[sprite], &data->spritesheetInfo.height[sprite]);
    if (data->images.spritesheet[sprite] == NULL)
        i = 1;
    rows = -1;
    while (++rows < N_D)
    {
        frames = -1;
        while (++frames < N_FPD)
        {
            if ((frames + 1) * data->spritesheetInfo.width[sprite] > data->spritesheetInfo.width[sprite] || (rows + 1) * data->spritesheetInfo.height[sprite] > data->spritesheetInfo.height[sprite])
                break;
            data->images.sprites[sprite][rows][frames] = ft_extract_frame(data, sprite, frames * data->spritesheetInfo.width[sprite], rows * data->spritesheetInfo.height[sprite], data->spritesheetInfo.width[sprite], data->spritesheetInfo.height[sprite]);   
            if (data->images.sprites[sprite][rows][frames] == NULL)
                return (1);
        }
    }
	return (i);
}
