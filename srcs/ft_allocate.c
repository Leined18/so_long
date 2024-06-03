// Allocation of memory for the sprites
#include "so_long.h"

void	ft_init_img(t_img **img, int sp)
{
	img[sp] = ft_calloc(1, sizeof(t_img));
	img[sp]->frameNumber = sp;
}

void	ft_allocate_sprites(t_info *data)
{
	int x;
	int y;
	int img_index;

	img_index = -1;
	while (++img_index < NUMBERS_SPRITE)
	{
		y = -1;
		while (++y < data->s_info.rows[img_index])
		{
			x = -1;
			while (++x < data->s_info.frames[img_index])
				ft_init_img(data->images[img_index].frames[y], x);
			
		}
		data->images[img_index].frames[y][x] = NULL;
	}
}