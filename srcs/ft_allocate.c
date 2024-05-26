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
		data->images[img_index].sprite = img_index;
		data->images[img_index].spritesheet = ft_calloc(1, sizeof(t_img));
		while (++y < F)
		{
			x = -1;
			while (++x < F)
				ft_init_img(data->images[img_index].frames[y], x);
	
		}
	}
}