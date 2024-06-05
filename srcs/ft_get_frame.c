#include "so_long.h"

static int	get_pixel_color(t_img *img, int x, int y)
{
	char			*pixel;
	unsigned int	color;

	color = 0;
	pixel = NULL;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

static void	extract_colors(t_info *data, t_img *frame, sprite_type sprite,
		int frame_x, int frame_y, int frame_width, int frame_height)
{
	unsigned int	color;
	char			*dst;
	int				x;
	int				y;

	y = -1;
	while (++y < frame_height)
	{
		x = -1;
		while (++x < frame_width)
		{
			color = get_pixel_color(data->img[sprite].spsh, frame_x
					+ x, frame_y + y);
			dst = frame->addr + (y * frame->line_length + x
					* (frame->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
	}
}

static t_img	*initialize_frame(t_info *data, int frame_width,
		int frame_height)
{
	t_img	*frame;

	frame = (t_img *)ft_calloc(1 ,sizeof(t_img));
	if (!frame)
		return (NULL);
	frame->img = mlx_new_image(data->mlx, frame_width, frame_height);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bits_per_pixel,
			&frame->line_length, &frame->endian);
	frame->frameNumber = 0;
	return (frame);
}

t_img	*ft_extract_frame(t_info *data, sprite_type sprite, int frame_x,
		int frame_y)
{
	t_img	*frame;

	frame = initialize_frame(data, RES, RES);
	if (!frame->img)
		return (NULL);
	extract_colors(data, frame, sprite, frame_x, frame_y, RES, RES);
	return (frame);
}
